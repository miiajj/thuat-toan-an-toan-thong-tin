#include <stdio.h>
#include <math.h>

void outPut(int arr[],int n){
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void sortArr(int arr[],int n){
    int temp;
    for(int i = 0; i < n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}
void convertToArr(int t, int w, long long x, int arr[]){
    for(int i = t-1; i >= 0; i--){
        arr[t-1-i] = x / pow(2,w*i);
        x -= arr[t-1-i] * pow(2,w*i);
    }
}
void multiplication(int t,int a[], int b[], int c[]){
    sortArr(a,t);
    sortArr(b,t);
    int u, v, u_v;
    for(int i = 0; i < t; i++){
        c[i] = 0;
    }
    for(int i = 0; i < t; i++){
        u = 0;
        for(int j = 0; j < t; j++){
            u_v = c[i+j] + a[i]*b[j] + u;
            int temp[50];
            //  dec -> bin
            for(int k = 0; k < 16; k++){
                temp[k] = u_v % 2;
                u_v = u_v / 2;
            }
            //  u
            u = 0;
            for(int k = 0; k < 8; k++){
                u = u + pow(2,k)*temp[k+8];
            }
            // v
            v = 0;
            for(int k = 0; k < 8; k++){
                v = v + pow(2,k)*temp[k];
            }
            c[i+j] = v;
        }
        c[t+i] = u;
    }
}                                                         
int main(){
    int arr1[50], arr2[50], arr3[50];
    long long p = 2147483647;
    int w = 8;
    int m = log2(p);
    int t = round((float)m/w);
    long long a = 524647;
    long long b = 32549;
    convertToArr(t,w,a,arr1);
    convertToArr(t,w,b,arr2);
    multiplication(t,arr1,arr2,arr3);
    sortArr(arr3,w);
    outPut(arr3,w);
    return 0;
}
//  c = a.b =[0 0	0	3	249	218	76	227]
