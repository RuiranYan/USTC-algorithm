/*
 * 超过⼀半的数:
 * ⾸先输⼊⼀个正整数T，代表存在T组样例
 * 接下来共T组样例，每组样例中⾸先输⼊N，下⼀⾏N个正整数。
 * 在每组样例中你需要找到是否存在⼀个“超过⼀半的数”x(即存在x在这N个数中出现次数>=(N+1)/2)
 * 若存在x则输出x否则输出-1
 */
#include <stdio.h>
#include <string.h>
unsigned short array[10000000]={0};
int main(){
    unsigned int T;
    scanf("%d",&T);
    int output[T];
    for (int i = 0; i < T; ++i) {
        output[i] = -1;
    }
    for (int i = 0; i < T; ++i) {
        int n=0;
        scanf("%d",&n);
        for(int a=0;a<n;a++){
            unsigned int x;
            scanf("%d",&x);
            array[x]++;
            if(array[x]>(n/2)){
                output[i] = x;
            }
        }
        memset(array, 0, sizeof(array));
    }
    for (int i = 0; i < T; ++i) {
        printf("%d\n", output[i]);
    }
}

