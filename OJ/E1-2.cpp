#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int N;
    char T;
    scanf("%d %c", &N, &T);
    getchar();
    int len = 0;
    unsigned int a[1000000]={0};
    int flag = 0;
    int num;
    char s[N + 1];
    scanf("%s", s);
    for (int i = 0; i < N+1; ++i) {
        char c = s[i];
        if (c != T && c != '\0') {
            if (flag == 0) {
                num = c - 48;
                flag = 1;
            } else {
                num = num * 10 + c - 48;
            }
        } else {
            if (flag == 1) {
                len++;
                a[len-1] = num;
            }
            flag = 0;
        }
    }
//    for (int i = 0; i < len; ++i) {
//        printf("%d\n",a[i]);
//    }
    int n = len;
    int b[n];
    int pow = 1;
    for (int i = 0; i < 10; ++i) {
        int c[10] = {0};
        int dig[n];
        for (int j = 0; j < n; ++j) {
            dig[j] = a[j] / pow % 10;
            c[dig[j]]++;
        }
        pow = pow * 10;
        for (int j = 1; j < 10; ++j) {
            c[j] = c[j] + c[j - 1];
        }
        for (int j = n - 1; j >= 0; --j) {
            b[c[dig[j]] - 1] = a[j];
            c[dig[j]] = c[dig[j]] - 1;
        }
        for (int j = 0; j < n; ++j) {
            a[j] = b[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}


