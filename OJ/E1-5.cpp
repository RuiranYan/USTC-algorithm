#include <iostream>
#include <string.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;
unsigned int a[14348906]={0};
int map1(char s[]){
    int val = 0;
    int i = 0;
    int k = 1;
    while(s[i]!='\0'){
        val += (s[i] - 96) * k;
        k *= 27;
        i++;
    }
    return val;
}
int main(){
    int cnt=0;
    int n,k;
    scanf("%d %d",&n, &k);
    int id[n];
    char s[6];
    for (int i = 0; i < n; ++i) {
        scanf("%s",s);
        id[i] = map1(s);
    }
    int i =0;
    int l=-1;
    int size = 0;
    while(size<k&&l<n-1){
        ++l;
        if(a[id[l]]==0){
            a[id[l]] = a[id[l]]+1;
            size++;
        } else  a[id[l]] = a[id[l]]+1;
    }
    int r=l;
    while (size==k){
        ++r;
        if(a[id[r]]==0||r==n){
            break;
        }
    }
    cnt+=r-l;
    for (i = 1; i < n-k+1; ++i) {
        a[id[i-1]] = a[id[i-1]]-1;
        if(a[id[i-1]]>0){
            cnt+=r-l;
        } else{
            size--;
            while(size<k&&l<n-1){
                ++l;
                if(a[id[l]]==0){
                    a[id[l]] = a[id[l]]+1;
                    size++;
                } else  a[id[l]] = a[id[l]]+1;
            }
            r=l;
            while (size==k){
                ++r;
                if(a[id[r]]==0||r==n){
                    break;
                }
            }
            cnt+=r-l;
        }
    }
    printf("%d", cnt);
    return 0;
}
