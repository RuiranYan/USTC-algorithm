/*
 * 最佳置换算法(OPT, Optimal Page Replacement algorithm):
 * 现有一个长为N的数据访问序列和一块大小为K的缓存，请设计算法使数据访问的MISS次数最少。
 * 假设所有可能访问的数据在一个确定的范围内，这里用整数来表示存放数据的地址。
 * 假设无论是否命中，这次访问的数据都需要存放在缓存内。
 * INPUT:
 * 第一行两个整数N,K表示共N个访问请求，缓存大小为K
 * 接下来的N行每行一个整数i，表示访问内存地址为i的数据。
 * OUTPUT:
 * 输出一个整数表示最少的MISS次数。
 */

# include <iostream>
# include <algorithm>
# include <set>
# include <queue>
# include <map>

using namespace std;
int a[100000];
int flag[100000] = {0};

int main(){
    int n,k;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    map<int,int> m;
    map<int,int>::const_iterator  it;
    int j;
    int miss = 0;
    for (int i = 0; i < n; ++i) {
        if(m.size()<k){
            if(flag[a[i]]==0) {
                flag[a[i]] = 1;
                miss++;
                for (j = i + 1; j < n; ++j) {
                    if (a[j] == a[i]) break;
                }
                if (j == n) {
                    m[n + i] = a[i];
                } else {
                    m[j] = a[i];
                }
//                cout << "insert" << a[i] << " miss" << endl;
            } else{
                m.erase(i);
                for (j = i+1; j < n; ++j) {
                    if(a[j] == a[i]) break;
                }
                if (j == n){
                    m[n+i] = a[i];
                } else{
                    m[j] = a[i];
                }
//                cout<<"hit"<<a[i]<<endl;
            }
        } else{
            if (flag[a[i]]==0){//miss and replace
                flag[a[i]] = 1;
                miss++;
                it = m.end();
                it--;
                int tmp = it->second;
                flag[tmp]=0;
                m.erase(it);
                for (j = i+1; j < n; ++j) {
                    if(a[j] == a[i]) break;
                }
                if (j == n){
                    m[n+i] = a[i];
                } else{
                    m[j] = a[i];
                }
//                cout<<"insert "<<a[i]<<" miss, replace "<<tmp<<endl;
            }
            else{//hit
                m.erase(i);
                for (j = i+1; j < n; ++j) {
                    if(a[j] == a[i]) break;
                }
                if (j == n){
                    m[n+i] = a[i];
                } else{
                    m[j] = a[i];
                }
//                cout<<"hit"<<a[i]<<endl;
            }
        }
    }
    cout<<miss;
    return 0;
}
