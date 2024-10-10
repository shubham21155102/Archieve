# DP

---

# [**Climbing Stairs**](https://leetcode.com/problems/climbing-stairs/description/)

```cpp
class Solution {
public:
    int recursion(int n,vector<int> &dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=recursion(n-1,dp)+recursion(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return recursion(n,dp);

    }
};
```

---

# [**Frog Jump CN**](https://www.naukri.com/code360/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM/)

## Recursion

```cpp
#include <bits/stdc++.h>
int recursion(int ind,vector<int> &v){
     if(ind==0) return 0;
     int l=recursion(ind-1,v)+abs(v[ind]-v[ind-1]);
     int r=INT_MAX;
     if(ind>1) r=recursion(ind-2,v)+abs(v[ind]-v[ind-2]);
     return min(l,r);
}
int frogJump(int n, vector<int> &v)
{
    return recursion(n-1,v);
}
```

## Memoization

```cpp
#include <bits/stdc++.h>
int recursion(int ind,vector<int> &v,vector<int> &dp){
     if(ind==0) return 0;
     if(dp[ind]!=-1) return dp[ind];
     int l=recursion(ind-1,v,dp)+abs(v[ind]-v[ind-1]);
     int r=INT_MAX;
     if(ind>1) r=recursion(ind-2,v,dp)+abs(v[ind]-v[ind-2]);
     return dp[ind]=min(l,r);
}
int frogJump(int n, vector<int> &v)
{
     vector<int> dp(n,-1);
    return recursion(n-1,v,dp);
}
```

## Tabulation

```cpp
int frogJump(int n, vector<int> &v)
{
     vector<int> dp(n,-1);
     dp[0]=0;
     for(int i=1;i<n;i++){
          int fs=dp[i-1]+abs(v[i]-v[i-1]);
          int ss=INT_MAX;
          if(i>1)
          ss= dp[i-2]+abs(v[i]-v[i-2]);
          dp[i]=min(fs,ss);
     }
     return dp[n-1];
}
```

## Space Optimized

```cpp
int frogJump(int n, vector<int> &v)
{
     int prev=0,prev2=0;
     for(int i=1;i<n;i++){
          int fs=prev+abs(v[i]-v[i-1]);
          int ss=INT_MAX;
          if(i>1)
          ss= prev2+abs(v[i]-v[i-2]);
          int curr=min(fs,ss);
          prev2=prev;
          prev=curr;
     }
     return prev;
}
```

---

# [**Frog Jump with k distances**](https://www.naukri.com/code360/problems/minimal-cost_8180930?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf)

```cpp
int minimizeCost(int n, int k, vector<int> &v){
    // Write your code here.
    vector<int> dp(n);
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if((i-j)>=0){
                int steps=dp[i-j]+abs(v[i]-v[i-j]);
                minSteps=min(minSteps,steps);
            }
        }
        dp[i]=minSteps;
    }
    return dp[n-1];
}
```

---

# [**Frog Jump Leetcode**](https://leetcode.com/problems/frog-jump/description/)

```cpp
class Solution {
public:
     bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> dp;
        for(auto position: stones)dp[position]=unordered_set<int>();
        dp[0].insert(0);
        for(auto position:stones){
            for(auto k:dp[position]){
                if(k-1>0 && dp.find(position+k-1)!=dp.end())
                dp[position+k-1].insert(k-1);
                if(dp.find(position+k)!=dp.end())
                dp[position+k].insert(k);
                if(dp.find(position+k+1)!=dp.end())
                dp[position+k+1].insert(k+1);
            }
        }
        return !dp[stones.back()].empty();
    }
};
```

---

## [ Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

---

Given two strings `text1` and `text2`, return *the length of their longest **common subsequence** . *If there is no **common subsequence** , return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

---

**Example 1:**

<pre><strong>Input:</strong> text1 = "abcde", text2 = "ace" 
<strong>Output:</strong> 3  
<strong>Explanation:</strong> The longest common subsequence is "ace" and its length is 3.
</pre>

---

**Example 2:**

<pre><strong>Input:</strong> text1 = "abc", text2 = "abc"
<strong>Output:</strong> 3
<strong>Explanation:</strong> The longest common subsequence is "abc" and its length is 3.
</pre>

---

**Example 3:**

<pre><strong>Input:</strong> text1 = "abc", text2 = "def"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no such common subsequence, so the result is 0.
</pre>

---

**Constraints:**

- `1 <= text1.length, text2.length <= 1000`
- `text1` and `text2` consist of only lowercase English characters.

---

### Raw Solution

---

```cpp
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void subSequence(string s, int i, string temp, vector<string> &ans, unordered_map<string, vector<string>> &mp)
{
    if (i == s.size())
    {
        ans.push_back(temp);
        mp[temp].push_back(temp);
        return;
    }
    subSequence(s, i + 1, temp + s[i], ans, mp);
    subSequence(s, i + 1, temp, ans, mp);
}
int lcs_recursion(string s1, string s2, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + lcs_recursion(s1, s2, m - 1, n - 1);
    }
    return max(lcs_recursion(s1, s2, m - 1, n), lcs_recursion(s1, s2, m, n - 1));
}
int lcs_d_bottom_up(string s1, string s2, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[m][n] = 1 + dp[m - 1][n - 1];
            }
            else
            {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }
    return dp[m][n];
}
int lcs_dp_top_down(string s1, string s2, int m, int n, vector<vector<int>> &dp)
{
    if (m == 0 or n == 0)
        return dp[m][n] = 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    if (s1[m - 1] == s2[n - 1])
    {
        return dp[m][n] = 1 + lcs_dp_top_down(s1, s2, m - 1, n - 1, dp);
    }
    return dp[m][n] = max(lcs_dp_top_down(s1, s2, m - 1, n, dp), lcs_dp_top_down(s1, s2, m, n - 1, dp));
}
int main()
{
    string s1 = "GEOGRAPHY";
    // vector<string> words;
    // unordered_map<string, vector<string>> mp;
    // subSequence(s1, 0, "", words, mp);
    // for (auto x : words)
    // {
    //     cout << x << endl;
    // }
    s1 = "ABCDGH";
    string s2 = "AEDFHR";
    cout << lcs_recursion(s1, s2, s1.size(), s2.size());
    cout << endl;
    cout << lcs_d_bottom_up(s1, s2, s1.size(), s2.size());
    cout << endl;
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    cout << lcs_dp_top_down(s1, s2, s1.size(), s2.size(), dp);

    return 0;
}
```

---

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[m][n];
    }
};
```

---

# [Maximize Number of Subsequences in a String](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/)

---

You are given a **0-indexed** string `text` and another **0-indexed** string `pattern` of length `2`, both of which consist of only lowercase English letters.

You can add **either** `pattern[0]` **or** `pattern[1]` anywhere in `text` **exactly once** . Note that the character can be added even at the beginning or at the end of `text`.

Return _the **maximum** number of times_ `pattern` _can occur as a **subsequence** of the modified _`text`.

A **subsequence** is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

---

**Example 1:**

<pre><strong>Input:</strong> text = "abdcdbc", pattern = "ac"
<strong>Output:</strong> 4
<strong>Explanation:</strong>
If we add pattern[0] = 'a' in between text[1] and text[2], we get "ab<u><strong>a</strong></u>dcdbc". Now, the number of times "ac" occurs as a subsequence is 4.
Some other strings which have 4 subsequences "ac" after adding a character to text are "<u><strong>a</strong></u>abdcdbc" and "abd<u><strong>a</strong></u>cdbc".
However, strings such as "abdc<u><strong>a</strong></u>dbc", "abd<u><strong>c</strong></u>cdbc", and "abdcdbc<u><strong>c</strong></u>", although obtainable, have only 3 subsequences "ac" and are thus suboptimal.
It can be shown that it is not possible to get more than 4 subsequences "ac" by adding only one character.
</pre>

---

**Example 2:**

<pre><strong>Input:</strong> text = "aabb", pattern = "ab"
<strong>Output:</strong> 6
<strong>Explanation:</strong>
Some of the strings which can be obtained from text and have 6 subsequences "ab" are "<u><strong>a</strong></u>aabb", "aa<u><strong>a</strong></u>bb", and "aab<u><strong>b</strong></u>b".
</pre>

---

**Constraints:**

- `1 <= text.length <= 10<sup>5</sup>`
- `pattern.length == 2`
- `text` and `pattern` consist only of lowercase English letters.

---

```cpp
class Solution {
public:
    long long Helper(string text, string pattern){
        vector<int> pfx(text.size(), 0);

        for(int i = 0; i < text.size(); i++) {
            if(text[i] == pattern[0]) {
                pfx[i] = 1;
            }
        }
        // for(int i=0;i<pfx.size();i++){
        //     cout<<pfx[i]<<" ";
        // }
        // cout<<"\n";
        if(pattern[0]==pattern[1]){
         int sum=accumulate(begin(pfx),end(pfx),0);
        //    cout<<sum;
        if(sum==1) return 0;
        else {
            int count_ttl=0;
            for(int i=0;i<text.size();i++){
                if(text[i]==pattern[0]) count_ttl++;
            }
            long long ans=count_ttl;
            ans*=(count_ttl-1);
            return ans/2;
        }
        }
        for(int i = 1; i < pfx.size(); i++) {
            pfx[i] += pfx[i-1];
        }

        long long ans = 0;
        // for(int i=0;i<pfx.size();i++){
        //     cout<<pfx[i]<<" ";
        // }
        // cout<<"\n";
        for(int i = 0; i < text.size(); i++) {
            if(text[i] == pattern[1]) {
                ans += pfx[i];
            }
        }



        // cout<<"\n";
        return ans;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        string s1 = pattern[0] + text;
        // string s2 = text + pattern[0];
        // string s3 = pattern[1] + text;
        string s4 = text + pattern[1];

        return max({Helper(s1, pattern),Helper(s4, pattern)});
    }
};
```

---

```cpp
class Solution {
public:
    long long Helper(string s,char a,char b){
        long long ans=0LL,first=0LL;
        for(char c:s){
            if(c==b) ans+=first;
            if(c==a)first++;
        }
        return ans;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        char first = pattern[0], second = pattern[1];
        long long option1 = Helper(first + text, first, second);
        long long option2 = Helper(text + second, first, second);
        return max(option1, option2);
    }
};
```

---

```cpp

```
