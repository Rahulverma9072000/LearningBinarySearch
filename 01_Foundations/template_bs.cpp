#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Check Function 
//We have to do something like our Check Function Range Should be 0 0 0 0 0 1 1 1 
//And We have to return the first 1 coming 


//Problem if we want to find number of rotation in the Rotated Sorted Array 
//Number of rotation will be equals to index of minimum element 
//Just Check mid 
int check(vector<int> &arr,int mid){
    if(arr[mid] < arr[0]){
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
    int ans = 0; //default value 
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(check(arr,mid) == 1){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}