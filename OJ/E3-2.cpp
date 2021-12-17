/*
 * 归并排序：
 * 有n个数组，数组长度分别为a[i]
 * 现只能merge相邻数组i,i+1，复杂度为a[i]+a[i+1]
 * INPUT:
 * 第一行为n之后是每个数组的长度
 * OUTPUT:
 * 最短耗时
 */
# include <iostream>

using namespace std;

int suma[200][200];

int main(){
    int n;
    cin>>n;
    int a[200];
    int dp[200][200];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        suma[i][i] = a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            suma[i][j] = suma[i][j-1]+a[j];
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        dp[i][i+1] = suma[i][i+1];
    }
    for (int j = 2; j < n; ++j) {
        for (int i = 0; i < n-j; ++i) {
            int minnum = 10000000;
            for (int k = i; k < i+j; ++k) {
                int tmp = dp[i][k]+dp[k+1][i+j]+suma[i][i+j];
                if (tmp<minnum){
                    minnum = tmp;
                }
            }
            dp[i][i+j] = minnum;
        }
    }
    cout<<dp[0][n-1];
    return 0;
}