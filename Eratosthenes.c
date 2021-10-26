#include <stdio.h>
#include <stdbool.h>

// Eratosthenes
void display_Primes(long long x){
    bool primes[x+1];
    primes[0] = false;
    primes[1] = false;
    for(long long i = 2; i <= x; ++i){
        primes[i] = true;
    }
    for(long long i = 2; i <= x; ++i){
        if(primes[i] == true){
            printf("%lld  ",i);
            for(long long j = 2*i; j <= x; j+=i){
                primes[j] = false;
            }
        }
    }
}
int main(){
    long long num = 400000;
    display_Primes(num);
    return 0;
}

// Bài 9. Viết chương trình tìm tất cả các số nguyên tố <=n 
//với n nhập vào từ bàn phím 
// Ví dụ: n=30  [2,3,5,7,11,13,17,19,23,29]