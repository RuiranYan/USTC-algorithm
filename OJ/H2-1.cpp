/*
 * 抽奖：
 * 主持⼈会在⼤屏幕上随机产⽣⼀个数字 ，然后观众通过⼿机在抽奖系统中输⼊⼀个0到10000之间的数字
 * (包括0和10000)，此时中奖观众将会是所有观众中输⼊的第k⼩的⼈，请输出获奖观众选择的数字。
 */
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
