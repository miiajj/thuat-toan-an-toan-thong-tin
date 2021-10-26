#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool primes[100000];

void eratosthenes(long long n){
    primes[0] = false;
    primes[1] = false;
    for(long long i = 2; i <= n; ++i){
        primes[i] = true;
    }
    for(long long i = 2; i <= n; ++i){
        if(primes[i] == true){
            for(long long j = 2*i; j <= n; j+=i){
                primes[j] = false;
            }
        }
    }
}
int main(){
    long long n; // n < 2072432
    long long delta;
    printf("Nhap N: ");
    scanf("%lld",&n);
    long long sqrt_n = round(sqrt(n));
    printf("Chon delta <= %lld: ",sqrt_n);
    scanf("%lld",&delta);
    for(long long i = 2; i <= n; ++i){
        primes[i] = true;
    }
    eratosthenes(delta+1);
    long long lower_limit, upper_limit, m;
    lower_limit = delta + 2;
    upper_limit = lower_limit + delta - 1;
    while(lower_limit <= n && upper_limit <= n){
        m = sqrt(upper_limit);
        for(long long i = lower_limit; i <= upper_limit; ++i){
            if(primes[i] == true){
                for(long long j = 2; j <= m; ++j){
                    if((primes[j] == true) && (i % j == 0)){
                        primes[i] = false;
                        j = m + 1;  // exit "for" loop
                    }
                }
            }
        }
        lower_limit += delta;
        upper_limit += delta;
        if(upper_limit > n){
            upper_limit = n;
        }
    }
    for(long long i = 2; i <= n; ++i){
        if (primes[i] == true){
            printf("%lld ", i);
        }
    }
    return 0;
}