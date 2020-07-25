
#include<stdio.h>
void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}
int main( ){
    int n, change;
    printf("Enter Number of Coin: ");

    scanf("%d", &n);
    printf("coin[]:");
    int coin[n];
    for(int i = 0; i < n; i++)
        scanf("%d", & coin[i]);
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
           if(coin[j] > coin[j+1])
              swap(&coin[j], &coin[j+1]);
    printf("Change Amount: ");
    scanf("%d", &change);
    printf("Coin Need: \n");
    for(int i = n - 1; i >= 0; i--)
        if(change >= coin[i]){
            int cnt = 0;
            while(change >= coin[i]){
                ++cnt;
                change -= coin[i];
            }
            printf("%d coin %d times\n", coin[i], cnt);
        }

    return 0;
}






