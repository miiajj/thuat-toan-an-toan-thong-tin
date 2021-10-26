#include <stdio.h>
// Bài 12. Viết chương trình kiểm tra tính nguyên tố của một số n 
//nhập vào từ bàn phím
// Ví dụ:   17  Nguyên tố
//          19  Nguyên tố
//          21  Hợp số

int multiply_square(int a, int m, int n){
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
int main(){         
    long long n,r;
    long long t,a;
    do{
        printf("Nhap N le >= 3: ");
        scanf("%lld",&n);
        printf("Nhap t >= 1: ");
        scanf("%lld",&t);
        if(n < 3 || n%2 == 0 || t < 1){
            printf("Khong hop le, nhap lai\n");
        }
    }while(n < 3 || n%2 == 0 || t < 1);

    int count = 0;
    for(long long i = 1; i <= t; ++i){
        a = i+1;    // choose a: 2 <= a <= n-2, here a = i+1
        r = multiply_square(a,n-1,n); 
        if(r == 1){
            printf("a = %lld: %lld so nguyen to\n",a,n);
        }else{
            printf("a = %lld: %lld hop so\n",a,n);
            ++count;
        }
    }
    if(count > 0){printf("%lld la hop so.",n);}
    else{printf("%lld co the la so nguyen to.",n);}
    return 0;
}