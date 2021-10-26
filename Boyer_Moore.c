#include <stdio.h>
#include <string.h>

#define MAX 10000
// Bài 16. Cài đặt thuật toán tìm kiếm mẫu P trong đoạn văn bản T. Kết quả trả về vị trí xuất hiện của mẫu P và
// số lần lặp tính toán, số phép tính theo Boyer-Moore với P và T nhập vào từ bàn phím
void last_Occurrence(char t[], char p[], int len_t, int len_p, int L[]){
    for(int i = 0; i < len_t; ++i){
        L[t[i]] = -1; 
    }
    for(int i = 0; i < len_p; ++i){
        L[p[i]] = i;
    }
}
int boyer_moore(char t[], char p[], int len_t, int len_p, int L[]){
    last_Occurrence(t,p,len_t,len_p,L);
    int count = 0;
    int check_length = 0;
    int i = len_p - 1;
    int j = len_p - 1;
    while(i < len_t){
        ++count;
        if(t[i] == p[j]){
            ++check_length;
            if(check_length == len_p){
                printf("Vi tri xuat hien cua \"%s\" trong \"%s\" la %d.\nSo lan lap la %d.",p,t,i,count);
                return 0;
            }
            --i;
            --j;
        }else{
            int jump = j < 1 + L[t[i]] ? j : 1 + L[t[i]];
            i += len_p - jump;
            j = len_p - 1;
            check_length = 0;
        }
    }
    printf("Mau \"%s\" khong xuat hien trong \"%s\".\nSo lan lap la %d.",p,t,count);
    return 0;
}
int main(){
    char t[MAX], p[MAX];
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
    int L[MAX];
    boyer_moore(t,p,len_t,len_p,L);
    return 0;
}