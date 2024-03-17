# Longest Increasing Subsequence(Length)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int binary_search_lis(int arr[],int n){
        vector<int>ans;
        ans.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>ans.back()) {
                ans.push_back(arr[i]);
            }
            else{
                int lb=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
                ans[lb]=arr[i];
            }
        }
        return ans.size();
    }
int dp_lis(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(dp, dp + n);
}
int lis_end(int arr[], int curr)
{
    if (curr == 0)
        return 1;
    int ans = 1;
    for (int i = curr - 1; i >= 0; i--)
    {
        if (arr[curr] > arr[i])
            ans = max(ans, 1 + lis_end(arr, i));
    }
    return ans;
}
int lisSolve(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,lis_end(arr,i));
    }
    return ans;

}
signed main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << lisSolve(arr, n) << endl; //TC O(2^n)// SC O(n)
    cout << dp_lis(arr, n) << endl; //TC O(n^2)// SC O(n)
    cout << binary_search_lis(arr, n) << endl; //TC O(nlogn)// SC O(n)
    return 0;
}
```

-
