#include <stdio.h>
// Euclid
int findGCD(int a, int b) {
    int r;
    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int result = findGCD(712,9468);
    printf("%d",result);
    return 0;
}
// Ví dụ: 	a= 28150488 b= 10507620 =>gcd(a,b)=12
// a= b=	345632 => gcd(a,b)=1
