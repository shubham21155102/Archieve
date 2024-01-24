#include <bitset>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
// shubham@SHUBHAMs-MacBook-Air BitManipulation % g++ -std=c++11 -o 2.subset 2.subset.cpp
// shubham@SHUBHAMs-MacBook-Air BitManipulation % ./2.subset
void recursion(vector<int> &nums, unordered_set<int> &s, int sum, int n, int curr)
{
    if (curr > n)
        return;
    if (curr == n)
    {
        s.insert(sum);
        return;
    }
    recursion(nums, s, sum + nums[curr], n, curr + 1);
    recursion(nums, s, sum, n, curr + 1);
}
vector<int> DistinctSum(int *nums, int n)
{

    bitset<1000007> bi(1);
    for (int i = 0; i < n; i++)
    {
        bi = bi | (bi << nums[i]);
    }
    vector<int> ans;
    for (int i = 0; i < 1000007; i++)
    {
        if (bi[i])
            ans.push_back(i);
    }
    return ans;
}
int equalPartition(int *nums, int n)
{
    bitset<30000> bi(1);
    unordered_map<long long int, long long int> mp;
    for (int i = 0; i < n; i++)
    {
        bi = bi | (bi << nums[i]);
    }
    vector<int> ans;
    for (int i = 0; i < 30000; i++)
    {
        if (bi[i])
        {
            ans.push_back(i);

            mp[i]++;
        }
    }
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // for (auto i : mp)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }
    long long int sum = accumulate(nums, nums + n, 0LL);
    for (auto i : mp)
    {
        long long int x = i.first;
        long long int y = i.second;
        if (sum & 1)
        {
            return 0;
        }
        else
        {
            if (mp.find(sum / 2) != mp.end())
                return 1;
        }
    }
    // cout << sum << endl;
    return 0;
}
signed main()
{
    int n = 47;
    int nums[] = {339, 111, 883, 603, 661, 825, 542, 216, 339, 174, 344, 596, 330, 267, 294, 13, 757, 519, 860, 650, 292, 832, 876, 279, 990, 953, 635, 295, 598, 107, 741, 937, 570, 976, 540, 584, 801, 83, 800, 492, 609, 496, 440, 939, 763, 735, 304};
    vector<int> ans = DistinctSum(nums, n);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << equalPartition(nums, n);

    return 0;
}