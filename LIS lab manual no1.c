#include<stdio.h>
#include<string.h>
int main(){
    int array[1000], previous_index[1000], dp[1000], path[1000];
    int n, path_index = 0;
    printf("Data size: ");
    scanf("%d", &n);
    printf("Data[] = ");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
        dp[i] = 1;
        previous_index[i] = -1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(array[j] < array[i] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                previous_index[i] = j;
            }
        }
    }
    int ans = dp[0], pos = 0;
    for(int i = 1; i < n; i++){
        if(dp[i] > ans){
            ans = dp[i];
            pos = i;
        }
    }
    while(pos != -1){
        path[path_index++] = array[pos];
        pos = previous_index[pos];
    }
    printf("LIS = ");
    for(int i = path_index - 1; i >= 0; i--)
        printf("%d ", path[i]);
    return 0;
}

