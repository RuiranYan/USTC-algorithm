/*
 * 正方形计数：
 * INPUT:
 * 第一行n,m表示矩阵大小
 * 接下来共有nn行输入数据，每行包含mm个0或1的整数，其中0表示该地面完好，1表示该地面已损坏。
 * OUTPUT:
 * 输出不包含损坏区域的正方形的个数
 */

# include <iostream>
# include <algorithm>

using namespace std;
int dp[2000][2000];
int a[2000][2000];

//dp[i][j]表示以(i,j)为右下角的正方形个数。
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        a[i][0] == 0 ? dp[i][0] = 1 : dp[i][0] = 0;
        a[0][i] == 0 ? dp[0][i] = 1 : dp[0][i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (a[i][j] == 1) dp[i][j] = 0;
            else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            count += dp[i][j];
        }
    }
    cout << count;
    return 0;
}

