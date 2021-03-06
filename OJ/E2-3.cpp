/*
 * 内存分配:
 * 每次输入两个整数代表占用该段内存
 * 当新的需要的内存区域已被分配则分配失败，打印-1，分配成功打印0。
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main(){
    map<int, int> interval;
    map<int,int>::iterator itr;
    int n;
    int max,min;
    int a,b;
    scanf("%d",&n);
    scanf("%d %d", &min, &max);
    interval.insert(pair<int,int>(min,max));
    printf("0\n");
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &min, &max);
        itr = interval.upper_bound(min);
        if(itr==interval.end()){
            itr--;
            if(min>(*itr).second){
                interval.insert(pair<int,int>(min,max));
                printf("0\n");
            } else{
                printf("-1\n");
            }
            continue;
        }
        else if(itr==interval.begin()){
            if(max<(*itr).first){
                interval.insert(pair<int,int>(min,max));
                printf("0\n");
            }
            else{
                printf("-1\n");
            }
            continue;
        }
        a = (*itr).first;//max<=a
        itr--;
        b = (*itr).second;//min>=b
        if(max<a&&min>b){
            interval.insert(pair<int,int>(min,max));
            printf("0\n");
        }
        else printf("-1\n");
    }

}
