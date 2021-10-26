#include <stdio.h>
#include <string.h>

#define MAX 10000
// Bài 17. Cài đặt thuật toán tìm kiếm mẫu P trong đoạn văn bản T
// kết quả trả về vị trí xuất hiện của mẫu P và số lần lặp tính toán,
// số phép tính theo Knuth-Moris-Pratt với P và T nhập vào từ bàn phím

void failureFunction(char p[], int F[], int len_p) {
    int i, j;
    F[0] = 0;
    i = 1;
    j = 0;
    while (i < len_p) {
        if(p[i] == p[j]) {
            F[i] = j + 1;
            ++i;
            ++j;
        }
        else if (j > 0) {
            j = F[j-1];
        }
        else {
            F[i] = 0;
            ++i;
        }
    }
}
int kmp(char t[], char p[], int len_t, int len_p) {
    int F[len_p];
    failureFunction(p,F,len_p);
    int i = 0;
    int j = 0;
    int count = 0;
    while (i < len_t) {
        ++count;
        if (t[i] == p[j]) {
            if (j == len_p -1) {
                printf("Vi tri xuat hien cua \"%s\" trong \"%s\" la %d.\nSo lan lap la %d.",p,t,i-j,count);
                return 0;
            } else {
                ++i;
                ++j;
            }
        }
        else if (j > 0) {
            j = F[j-1];
        }
        else {
            ++i;
        }
    }
    printf("Mau \"%s\" khong xuat hien trong \"%s\".\nSo lan lap la %d.",p,t,count);
    return 0;
}
int main() {
    char t[MAX], p[MAX];
    int len_t, len_p;
    do{
        printf("Nhap van ban T: ");
        fflush(stdin);  gets(t);
        printf("Nhap mau P: ");
        fflush(stdin);  gets(p);
        len_t = strlen(t);
        len_p = strlen(p);
        if(len_t < len_p){
            printf("Khong hop le!\n");
        }
    }while(len_t < len_p);
    kmp(t,p,len_t,len_p);
    return 0;
}
