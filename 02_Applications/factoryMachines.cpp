#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
bool check(vector<int> &arr, int time, int t)
{
    int cnt_product = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cnt_product += (time/arr[i]);
        if(cnt_product >= t) return 1;
    }
    return 0;
}
signed main()
{
    int n, t;
    cin >> n >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // I have to make the t total product
    // Search Space
    int ans = 0;
    int low = 0;
    int high = t * arr[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // Check Function
        if (check(arr, mid, t))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}