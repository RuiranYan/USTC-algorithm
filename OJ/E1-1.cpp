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

