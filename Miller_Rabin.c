#include <stdio.h>
#include <stdbool.h>

// Miler-Rabin

// Bài 15. Viết chương trình kiểm tra số nguyên tố với xác suất nằm
// trong khoảng cho trước.
int multiply_square(int a, int m, int n){
    int arr[100];
    int i = 0;
    while (m != 0){
        arr[i] = m % 2;
        m = m / 2;
        ++i;
    }
    m = 1;
    if (arr[0] == 1){
        m = a;
    }
    for (int j = 1; j < i; ++j){
        a = a * a % n;
        if (arr[j] == 1){
            m = a * m % n;
        }
    }
    return m;
}
bool miller_Rabin(int n, int a){
    int r = n - 1;
    int s = 0;
    while (r % 2 == 0){
        r /= 2;
        ++s;
    }
    int y = multiply_square(a, r, n);
    if (y != 1 && y != n - 1){
        int j = 1;
        while (j < s && y != n - 1){
            y = y * y % n;
            if (y == 1){
                return false;
            }
            ++j;
        }
        if (y != n - 1){
            return false;
        }
    }
    return true;
}
bool isPrime(int n, int from, int to){
    for(int a = from; a < to; ++a){
        if(miller_Rabin(n,a) == false){
            return false;
        }
    }
    return true;
}
int main(){
    int n, a, z;
    do{
        printf("Nhap n nguyen le >=3: "); // n >=3 n%2!=0
        scanf("%d", &n);
        printf("Nhap khoang [a;z] (2 <= a va z <= n-2): ");
        scanf("%d", &a); // >=2
        scanf("%d", &z); // <= n-2
        if (n % 2 == 0 || n < 3 || a < 2 || z > n - 2 || a > z){
            printf("Khong hop le! Nhap lai:\n");
        }
    } while (n % 2 == 0 || n < 3 || a < 2 || z > n - 2 || a > z);

    if (isPrime(n, a, z)){
        printf("%d la so nguyen to", n);
    }else{
        printf("%d la hop so", n);
    }
    return 0;
}