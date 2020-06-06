#include<stdio.h>

int main()

{

    int a[]={9, -23, 20, 44, 26, 33};

    int searchItem=44;

    int i;

    //runtime complexity:O(N)

    //space complexity:O(1)

    for(i=0;i<=5;i++){

        if(a[i]==searchItem){

            printf("item found :%d\n",i);

            return 0;

 

        }

 

    }

    printf("not found");

    return 0;

}
