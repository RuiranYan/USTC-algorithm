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
    for (int i = 1; i < n; ++i) {
        int time1 = 0;
        int time2 = 0;
        int maxtime = 0;
        for (int j = 0; j < i; ++j) {
            if(dp[j]>a[i].r) time1+=a[i].p;
            if(dp[j]>maxtime) maxtime = dp[j];
        }
        time1 += a[i].p;
        if(maxtime>a[i].r){
            time2 = maxtime - a[i].r + a[i].p;
        } else{
            time2 = a[i].p;
        }
        if(time1 <= time2){
            for (int j = 0; j < i; ++j) {
                if(dp[j]>a[i].r) dp[j]+=a[i].p;
            }
            dp[i] = a[i].r + a[i].p;
        } else{
            dp[i] = maxtime + a[i].p;
        }
    }
    for (int i = 0; i < n; ++i) {
        time+=dp[i]-a[i].r;
//        cout<<dp[i]<<endl;
    }
    cout<<time;
    return 0;
}
