#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    vector<int> brr(m);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    for(int i = 0;i < m;i++){
        cin>>brr[i];
    }
    //Now Find the Result 
    int res = 0;
    for(int i = 0;i<n;i++){
        int closest_dist = INT_MAX;
        //Find the first tower lower bound 
        int towerAhead = lower_bound(brr.begin(),brr.end(),arr[i]) - brr.begin(); //this should be either equal or just after it 
        cout<<"Check " <<towerAhead<<endl;
        //Now finding the tower before will be 
        if(towerAhead != brr.size()){
            closest_dist = min(closest_dist,brr[towerAhead]);
            if(towerAhead != 0){
                closest_dist = min(closest_dist,brr[towerAhead-1]);
            }
        }else{
            closest_dist = min(closest_dist,brr[towerAhead-1]);
        }
        res = max(res,closest_dist);
    }
    cout<<res<<endl;
    return 0;
}