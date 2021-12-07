/*
 * 数组排序:
 * 给定⼀个⻓为 的int类型数组 ，将该数组排序。
 */
#include<stdio.h>
#include<math.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    int b[n];
    int num;
    int pow = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        a[i] = num;
    }
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

