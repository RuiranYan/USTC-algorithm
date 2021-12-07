/*
 * 基站放置:
 * n个村庄排成一排，挑若干村建基站，基站覆盖范围为R，求使所有村庄能覆盖的最少基站数
 * INPUT:
 * 第一行为N,R，接下来N行每行一个整数Xi表示第i个村庄的座标。
 * OUTPUT:
 * 输出最少的基站数。
 */

# include <iostream>
# include <algorithm>

using namespace std;

int x[100000];
int a[100000];

int main() {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);
    int minx;
    int flag = 0;
//    for (int i = 0; i < n; ++i) {
//        cout<<x[i]<<endl;
//    }
    int j, k = 0;
    int center, left;
    int right = -1;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (flag == 0) {
            left = x[i];
            flag = 1;
        } else if (flag == 1) {
            if (x[i] > left + r) {
                flag = 2;
                center = x[i - 1];
//                cout<<center<<endl;
                a[k++] = x[i - 1];
                count++;
                i--;
            }
        } else if (flag == 2){
            if(x[i]>center+r){
                flag=0;
                i--;
            }
        }
    }
    if(flag==1) count++;
    cout<<count;
}

