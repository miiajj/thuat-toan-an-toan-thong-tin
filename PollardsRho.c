#include <stdio.h>
#include <math.h>

// Pollard's Rho
int gcd(long long a, long long b){
    long long r;
    while (b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    long long n,d;
    printf("Nhap n = ");
    scanf("%lld",&n);
    long long a = 2;
    long long b = 2;
    while(1){
        a = (a*a + 1) % n;    // can change 1 = other number != 0,2;
        b = (b*b + 1) % n;    
        b = (b*b + 1) % n; 
        d = gcd(abs(a-b),n);
        if(1<d && d<n){
            printf("%d ",d);
            break;
        }
        if(d==n){
            printf("Failure!");
            break;
        }
    }
    return 0;
}