//
// Created by yanruiran on 2021/10/12.
//
#include<stdio.h>

int main() {
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    int a[n], b[n];
    int c[10001] = {0};
    int i, j;
//get input
    for (i = 0; i < n; i++) {
        int num = 0;
        scanf("%d", &num);
        c[num]++;
        a[i] = num;
    }
    for (int i = 1; i < 10001; ++i) {
        c[i] = c[i] + c[i-1];
    }
    //sort
    for (int i = n-1; i >= 0; --i) {
        b[c[a[i]]-1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
    printf("%d", b[k - 1]);
}
