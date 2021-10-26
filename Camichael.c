#include <stdio.h>
#include <stdbool.h>
// Bài 13. Viết chương trình kểm tra một số n nhập từ bàn phím có phải là một số camichael hay không?
// Ví dụ: 	n=561  số camichael
// 		N=22  Không phải camichael
bool isPrime(long long n){
    if(n<2){
        return false;
    }
    for(long long i = 2; i*i <= n; ++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int gcd(int a, long long b){
    int r;
    while(b!=0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int multiply_square(int a, int m, long long n){
    int arr[100];
    int i = 0;
    while(m!=0){
        arr[i] = m % 2;     // convert to bin
        m /= 2;
        ++i;
    }
    m = 1;
    if(arr[0]==1){
        m = a;
    }
    for(int j = 1; j < i; ++j){
        a = a*a % n;
        if(arr[j]==1){
            m = a*m % n;
        }
    }
    return m;
}
bool isCarmichael(long long n){
    if(isPrime(n)){
        return false;
    }
    for(int a = 2; a < 20; ++a){
        if(gcd(a,n)==1 && multiply_square(a,n-1,n)!=1){
                return false;
        }
    }
    return true;
}
int main(){
    long long n;
    printf("Nhap n: ");
    scanf("%lld",&n);
    if(isCarmichael(n)){
        printf("%d la so Carmichael",n);
    }else{
        printf("%d khong phai so Carmichael",n);
    }
    return 0;
}
