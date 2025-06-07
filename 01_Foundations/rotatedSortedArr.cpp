#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Given Sorted Rotated Array , find the index of the minimum element in the array 
int findMinIdx(vector<int> &arr){
    //Array is sorted Rotated 
    int n = arr.size();
    int resIdx = 0;
    int s = 0;
    int e = n - 1;
    while(s <= e){
        int m = s + (e-s)/2;
        if(arr[m] <= arr[n-1]){
            resIdx = m;
            e = m - 1;
        }else{
            s = m + 1;
        }
    }
    return resIdx;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for(int i = 0;i < n;i ++){
            cin>>arr[i];
        }
        cout<<findMinIdx(arr)<<endl;
    }
    return 0;
}