#include "stdio.h"
#include "math.h"

int main(){
    long long x = 30;   // fill x
    for(long long i = 2; i <= x; i++){
        int count = 0;
        while(x % i == 0){
            x /= i;
            ++count;
        }
        if(count>0){
            printf("%lld^%d",i,count);
            if(x>i){
                printf(" * ");
            }
        }
    }
    return 0;
}
// Bài 11. Viết chương trình tìm phân tích nguyên tố của một số nhập vào 
// từ bàn phím:
// Ví dụ: 	n=20  coso=[2,5], somu=[2,1]
// n=12   coso=[2,3], somu=[2,1]
