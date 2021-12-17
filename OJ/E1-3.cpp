/*
 * 逆序对:
 * 输⼊⼀个⻓度为 的数组，你需要求出数组中逆序对的数量（答案对10,000,007取模）
 */
#include<stdio.h>
#include<stdlib.h>


int count=0;


void merge(unsigned int *A,int low,int mid,int high){
    int i,j,k;
    int B[high-low+1];
    for(k=low;k<=high;k++){
        B[k]=A[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]<=B[j]){
            A[k]=B[i++];
        }
        else {A[k]=B[j++] ;
            count=(count+mid-i+1)%10000007;
        }
    }
    while(i<=mid){
        A[k++] = B[i++];
    }

    while(j<=high){
        A[k++] = B[j++];
    }

}
void merge_sort(unsigned int *arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    unsigned int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("%d",count);
}
