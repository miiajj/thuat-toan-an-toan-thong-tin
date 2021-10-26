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
void subtraction(int t,int w, int a[], int b[],int c[]){
    int e = 0;
    int d = pow(2,w);
    for(int i = t-1; i >= 0; i--){
        c[i] = a[i] - b[i] - e;
        if(c[i] < 0){
            c[i] += d;
            e = 1;
        }else{e = 0;}
    }
    printf("%d",e);
}
int main(){
    int arr1[100], arr2[100], result[100];
    long long p = 2147483647;
    int w = 8;
    int m = log2(p);
    int t = round((float) m/w);
    long long a = 38762497;
    long long b = 568424364;
    convertToArray(t,w,a,arr1);
    convertToArray(t,w,b,arr2);
    subtraction(t,w,arr1,arr2,result);
    outPut(result,t);
    return 0;
}