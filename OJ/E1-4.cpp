#include<stdio.h>
#include<stdlib.h>
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
int select(int *a, int p, int r, int i ){
    if(p==r) return a[p];
    int q = partition(a, p, r);
    int k = q-p+1;
    if(k==i) return a[q];
    else if(i<k) return select(a,p,q-1,i);
    else return select(a,q+1,r,i-k);
}
int main(){
    int T;
    int n,k;
    scanf("%d",&T);
    for (int i = 0; i < T; ++i) {
        scanf("%d %d", &n, &k);
        int arr[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
        }
        printf("%d\n",select(arr,0,n-1,k));
    }
    return 0;
}

