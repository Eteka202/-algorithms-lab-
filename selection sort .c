#include<stdio.h>
int main()
{
    //runtime complixity O(n^2)
   int arr[] = {11, 5, 7, 15, 2, 9, 4},i,j,temp,min;
   for(i=0;i<=6;i++)
   {
       min=i;
       for(j=i+1;j<=6;j++)
       {
           if(arr[j]< arr[min])
           {
               min=j;
           }
       }
       if(min!=i)
       {
           temp=arr[i];
           arr[i]=arr[min];
           arr[min]=temp;
       }
       else
            {
                break;
            }
            j--;
        }


    for(i=0;i<=6;i++)
        printf("%d\n",arr[i]);

    return 0;
   }
