# include <iostream>
# include <algorithm>

using namespace std;
typedef struct task{
    int r;
    int p;
}task;
task a[100000];
int s[100000];
int f[100000];
int dp[100000];//前i个任务结束时间。

bool cmp(task x,task y){
    return x.r<y.r;
}

int main(){
    int n;
    cin>>n;
    int time=0;

    for (int i = 0; i < n; ++i) {
        cin>>a[i].r>>a[i].p;
    }
    sort(a,a+n,cmp);
    dp[0] = a[0].r+a[0].p;
    time = a[0].p;
    for (int i = 1; i < n; ++i) {
        if(a[i].r<=dp[i-1]){
            if(a[i].r+a[i].p<=dp[i-1]){
                dp[i] = dp[i - 1] + a[i].p;
                time+=a[i].p+2*a[i].p;
            } else {
                dp[i] = dp[i - 1] + a[i].p;
                time+=a[i].p+dp[i-1]-a[i].r;
            }
        } else{
            dp[i] = a[i].r+a[i].p;
            time+=a[i].p;
        }
    }
//    for (int i = 0; i < n; ++i) {
//        time+=dp[i]-a[i].r;
//    }
    cout<<time;
    return 0;
}
