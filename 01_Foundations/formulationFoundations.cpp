#include<iostream>
using namespace std;
#include<algorithm>
//Binary Search 
//Basic Problem - Given a Sorted Array and x , Find if x is present in the array or not 
//Time Complexity : O(logN) Every time we are discarding half of the search space . 
bool searchX(vector<int> &arr,int x){
    int s = 0;
    int e = arr.size() - 1;
    while(s <= e){
        int m = s + (e-s)/2;
        if(arr[m] == x){
            return true;
        }else if(arr[m] > x){
            e = m - 1;
        }else{
            s = m + 1;
        }
    }
    return false;
}
//Problem : Given an array having 0 and 1 and is sorted as well , We have to find the first 1 index 
//here you have make a variable to store the result and update it everytime 
int findOne(vector<int> &arr){
    int ans = -1;
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == 1){
            //update the value 
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
//Lower Bound and Upper Bound 
// Lower Bound finds first element greater than or equal to x 
//Upper Bound finds first element strictly greater than x 
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();  // high is arr.size(), not arr.size() - 1
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int upperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

//Now Comes to the Next Type : Rotated Sorted Array 

//Given an array which was orignally sorted where all element are distinct , Find how many times this sorted array is rotated 




int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    //Lower Bound 

    return 0;
}