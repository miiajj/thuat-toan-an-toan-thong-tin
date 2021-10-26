#include <stdio.h>
#include <math.h>

void outPut(int arr[],int n){
    for(int i = 0; i < n; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void convertToArray(int t, int w, long long x, int arr[]){
    for(int i = t-1; i >= 0; i--){
        arr[t-1-i] = x / pow(2,w*i);
        x -= arr[t-1-i] * pow(2,w*i);
    }
}
void additionInFp(int w,long long p,int t, int arr1[], int arr2[]){
    int e = 0;
    int c[t];
    int d = pow(2,w);
    for(int i = t-1; i >= 0; i--){
        c[i] = arr1[i] + arr2[i] + e;
        if(c[i] >= d){
            c[i] -= d;
            e = 1;
        } else {e = 0;}
    }
    // e = 1 -> p - c
    // e = 0 -> c - p
    if(e == 1){
        int p_arr[100];
        convertToArray(t,w,p,p_arr);
        int result[50];
        int e1 = 0;
        for(int i = t-1; i >= 0; i--){
            result[i] = p_arr[i] - c[i] - e1;
            if(result[i] < 0){
                result[i] += d;
                e1 = 1;
            } else {e1 = 0;}
        }
        printf("%d\t",e1);
        outPut(result,t);
    }else{
        int p_arr[100];
        convertToArray(t,w,p,p_arr);
        int result[50];
        int e1 = 0;
        for(int i = t-1; i >= 0; i--){
            result[i] = c[i] - p_arr[i] - e1;
            if(result[i] < 0){
                result[i] += d;
                e1 = 1;
            } else {e1 = 0;}
        }
        printf("%d\t",e1);
        outPut(result,t);
    }
}
int main() {
    int arr1[100],arr2[100];
    long long p = 2147483647;
    int w = 8;
    int m = log2(p);
    int t = round((float) m/w);
    long long a = 2147483646;
    long long b = 2147483643;
    convertToArray(t,w,a,arr1);
    convertToArray(t,w,b,arr2);
    additionInFp(w,p,t,arr1,arr2);
    return 0;
}
//  KQ: [127   255   255   250]