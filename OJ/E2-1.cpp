/*
 * 数据库1.0:
 * 现有数据库系统支持两种函数INSERT和FIND
 * INSERT满足有序,FIND查找若找到就输出该数否则输出不大于他的最大的数。
 */

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int arr[2000000]={0};
int len=0;
int binary_search(int key,int n) //自定义函数binary_search()
{
    int low = 0, high = n - 1, mid = 0;
    do
    {
        mid = (low + high) / 2;
        if (key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    } while (high >= low && arr[mid] != key);
    return arr[mid];
}

int partition(int *a, int p, int r){
    int x = a[r];
    int i = p-1;
    int temp = 0;
    for (int j = p; j < r; ++j) {
        if(a[j]<x){
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[r];
    a[r] = a[i+1];
    a[i+1] = temp;
    return i+1;
}

void sort(int p,int r){
    if(p<r){
        int q = partition(arr,p,r);
        sort(p,q-1);
        sort(q+1,r);
    }
}
int main(){
    set <unsigned int> db;
    set<unsigned int>::iterator itr;
    char s[10];
    unsigned int key;
    int flag = 0;
    while(1){
        scanf("%s",s);
        if(s[0]=='I'){
            scanf("%ud",&key);
            db.insert(key);
        }
        else if(s[0]=='F'){
            scanf("%u",&key);
            itr = db.upper_bound(key);
            itr--;
            printf("%u\n",*(itr));
        }
        else break;
    }
}

