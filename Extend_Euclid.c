#include <stdio.h>
// Extend Euclid
int main(){
    long long p = 3193;
    long long a = 213;
    long long q,r,x,y,v,u,x2,x1,y2,y1;
    x2 = 1;
    x1 = 0;
    y2 = 0;
    y1 = 1;
    v = p;
    u = a;
    while (u!=0){
        q = v/u;
        r = v%u;
        x = x2 - q*x1;
        y = y2 -q*y1;
        v = u;
        u = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    if(y2<0){y2+=p;}
    printf("a^-1 mod p = %lld",y2);
    // printf("p^-1 mod a = %lld",x2);
    // printf("ax + by = %lld",v);
    return 0;
}
