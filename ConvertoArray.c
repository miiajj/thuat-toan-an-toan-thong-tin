#include <stdio.h>
#include <math.h>

void outPut(int arr[],int n){
    for(int i = 0; i < n; i++){
        printf("\t%d",arr[i]);
    }
    printf("\n");
}
void convertToArray(int t, int w, long long x, int arr[]){
    for(int i = t-1; i >= 0; i--){
        arr[t-1-i] = x / pow(2,w*i);
        x -= arr[t-1-i] * pow(2,w*i);
    }
}
int main(){
    int arr1[100], arr2[100];
    long long p = 2147483647;
    int w = 8;
    int m = log2(p);
    int t = round((float) m/w);
    long long a = 38762497;
    long long b = 568424364;
    convertToArray(t,w,a,arr1);
    convertToArray(t,w,b,arr2);
    outPut(arr1,t);
    outPut(arr2,t);
    return 0;
}