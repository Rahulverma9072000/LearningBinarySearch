// Write your code here
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
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
int findPeak(vector<int> &arr){
    int lo = 0;
    int hi = arr.size() - 1;
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
    return res;
}
int binary_search(vector<int> &arr,int s,int e,int x){
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] > x){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return -1;
}
int binary_search_desc(vector<int> &arr,int s,int e,int x){
    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid] == x){
            return mid;
        }else if(arr[mid] < x){
            e = mid - 1;
        }else{
            s = mid + 1;
        }
    }
    return -1;
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int i = 1;i<=q;i++){
            int x;cin>>x;
            //First Find the Peak index of this 
            int peakIdx = findPeak(arr);
            //Now Cut the array into 2 parts 
            //0 to peakIdx and peakIdx+1 , n-1
            int res1 = binary_search(arr,0,peakIdx,x);
            if(res1 != -1) cout<<(res1+1)<<" ";
            int res2 = binary_search_desc(arr,peakIdx+1,n-1,x);
            if(res2 != -1) cout<<(res2+1)<<" ";
            cout<<endl;
        }
    }
    return 0;
}