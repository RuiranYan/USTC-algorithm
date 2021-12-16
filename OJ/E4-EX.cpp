/*
 * 最小距离最大问题:
 * 坐标轴上n个点，取走其中m个点后问点之间距离最小值最大是多少
 * INPUT:
 * n m
 * n个点的座标
 * OUTPUT:
 * 输出去掉m个点后最小点间距的最大值
 */


# include <iostream>
# include <algorithm>

using namespace std;

int a[200000];

int main(){
    int n,m;
    cin >>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sort(a,a+n);
    int cnt,pos = 0;
    int low = 0;
    int high = a[n-1];
    while(low<=high)
    {
        int mid=(low+high)/2;//答案间距
        pos=cnt=0;
        for(int i=1;i<n;i++)
        {
            if(mid>=a[i]-a[pos])//两块石头的间距小于等于答案间距
                cnt++;
            else
                pos=i;
        }
        if(cnt>m)//要搬的石头个数大于题目要求的个数
            high=mid-1;
        else
            low=mid+1;
    }
    cout<<low<<endl;
    return 0;
}

