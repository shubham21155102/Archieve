#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int binary_search_lis(int arr[], int n)
{
    vector<int> ans;
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > ans.back())
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int lb = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[lb] = arr[i];
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
int lisSolve(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, lis_end(arr, i));
    }
    return ans;
}
int maxSumIS(int arr[], int n)
{
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int maxSumLis(int arr[], int n)
{
    int sum = accumulate(arr, arr + n, 0);
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = arr[i];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
                dp[i] = dp[j] + arr[i];

    return sum-(*max_element(dp, dp + n));
}
signed main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << lisSolve(arr, n) << endl;
    // cout << dp_lis(arr, n) << endl;
    // cout << binary_search_lis(arr, n) << endl;
    cout << maxSumIS(arr, n) << endl;
    return 0;
}