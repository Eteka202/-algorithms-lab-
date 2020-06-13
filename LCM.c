#include<stdio.h>
int main(){
    //run time complexity :O(logn)
    int  a, b ,gcd, rem,lcm,n1,n2;
    scanf("%d %d",&n1,&n2);
    a=n1;
    b=n2;
    while(b!=0)
    {
       rem=a%b;
       a=b;
       b=rem;
    }
    gcd=a;

    lcm= ((n1*n2)/gcd);
    printf("%d\n",lcm);
    return 0;
}
