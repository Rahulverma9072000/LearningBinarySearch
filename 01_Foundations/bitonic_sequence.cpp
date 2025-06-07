#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Bitonic Arrays :  First Strictly increasing than strictly increasing , Find the Peak element in the bitonic sequence 
int check(vector<int> &arr,int mid){
    //Edge Case 
    if(mid == arr.size() - 1){
        return 1;
    }
    if(arr[mid] > arr[mid+1]){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    int lo = 0;
    int hi = n-1;
    int res = -1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(check(arr,mid) == 1){
            res = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout<<res<<endl;
    return 0;
}