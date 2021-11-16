#include <iostream>
#include <string.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include<tr1/unordered_map>
using namespace std;
using namespace std::tr1;


//int map1(char s[]){
//    int val = 0;
//    int i = 0;
//    int k = 1;
//    while(s[i]!='\0'){
//        val += (s[i] - 96) * k;
//        k *= 27;
//        i++;
//    }
//    return val;
//}
int main(){
    int cnt=0;
    int n,k;
    scanf("%d %d",&n, &k);
    char s[n][6];
    unordered_map<string,int>m;
    for (int i = 0; i < n; ++i) {
        scanf("%s",s[i]);
        m[s[i]]=0;
    }
    int i =0;
    int l=-1;
    int size = 0;
    while(size<k&&l<n-1){
        ++l;
        if(m[s[l]]==0){
            m[s[l]] = m[s[l]]+1;
            size++;
        } else  m[s[l]] = m[s[l]]+1;
    }
    int r=l;
    while (size==k){
        ++r;
        if(m[s[r]]==0||r==n){
            break;
        }
    }
    cnt+=r-l;
    for (i = 1; i < n-k+1; ++i) {
        m[s[i-1]] = m[s[i-1]]-1;
        if(m[s[i-1]]>0){
            cnt+=r-l;
        } else{
            size--;
            while(size<k&&l<n-1){
                ++l;
                if(m[s[l]]==0){
                    m[s[l]] = m[s[l]]+1;
                    size++;
                } else  m[s[l]] = m[s[l]]+1;
            }
            r=l;
            while (size==k){
                ++r;
                if(m[s[r]]==0||r==n){
                    break;
                }
            }
            cnt+=r-l;
        }
    }
    printf("%d", cnt);
    return 0;
}