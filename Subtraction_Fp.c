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
void subtractionInFp(int w,long long p,int t, int arr1[], int arr2[]){
    int e = 0;
    int c[50];
    int z = pow(2,w);
    for(int i = t-1; i >= 0; i--){
        c[i] = arr1[i] - arr2[i] - e;
        if(c[i] < 0){
            c[i] += z;
            e = 1;
        } else {e = 0;}
    }
    // e = 1 -> c + p
    // e = 0 -> c
    if(e == 1) {
        int p_arr[50];
        convertToArray(t,w,p,p_arr);
        int result[50];
        int e1 = 0;
        for(int i = t-1; i >= 0; i--){
            result[i] = c[i] + p_arr[i] + e1;
            if(result[i] >= z){
                result[i] -= z;
                e1 = 1;
            } else {e1 = 0;}
        }
        outPut(result,t);
    }else{outPut(c,t);}
}
int main() {
    int arr1[50],arr2[50];
    long long p = 2147483647;
    int w = 8;
    int m = log2(p);
    int t = round((float) m/w);
    long long a = 38762497;
    long long b = 568424364;
    convertToArray(t,w,a,arr1);
    convertToArray(t,w,b,arr2);
    subtractionInFp(w,p,t,arr1,arr2);
    return 0;
}
//  KQ:[ 96   110     0    84]