#include<stdio.h>
int main(){
    //run time complexity:O(logn)
    int  a, b ,gcd, rem;
    scanf("%d %d",&a,&b);
    while(b!=0)
    {
       rem=a%b;
       a=b;
       b=rem;
    }
    gcd =a;
    printf("%d\n",gcd);
    return 0;
}
