#include <stdio.h>
#include <string.h>
// Bài 18. Cài đặt thuật toán tìm kiếm mẫu P trong đoạn văn bản T
// kết quả trả về vị trí xuất hiện của mẫu P và số lần lặp tính toán,
// số phép tính theo thuật toán vét cạn Với P và T nhập vào từ bàn phím
#define MAX 10000

void brute_force(char p[], char t[], int len_t, int len_p){
    int j = 0;
    int count = 0;
    for(int i = 0; i < len_t; ++i){
        ++count;
        if(t[i]==p[j]){
            ++j;
            if(j==len_p){
                printf("Mau \"%s\" xuat hien trong van ban \"%s\" tai vi tri %d - so phep lap la %d",p,t,i-j+1,count);
                break;
            }
        }else{
            if(i > len_t - len_p){
                printf("Mau \"%s\" khong xuat hien trong van ban \"%s\", so phep lap la %d.",p,t,count);
                break;
            }
            if(j > 0){
                i -= j;
            }
            j = 0;
        }
    }
}
int main(){
    char t[MAX];
    char p[MAX];
    int len_t,len_p;
    do{
        printf("Nhap van ban T: ");
        fflush(stdin);  gets(t);
        printf("Nhap mau P: ");
        fflush(stdin);  gets(p);
        len_t = strlen(t);
        len_p = strlen(p);
        if(len_t < len_p){printf("Khong hop le! Nhap lai:\n");}
    } while (len_t < len_p);
    brute_force(p,t,len_t,len_p);
    return 0;
}