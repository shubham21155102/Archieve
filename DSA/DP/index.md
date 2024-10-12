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

# [**Frog Jump Coding Ninjas**](https://www.naukri.com/code360/problems/frog-jump_3621012?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM/)

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

# [**Maximum Sum Of NonAdjacent Elements**](https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM)

## Recursion+Memoization

```cpp
#include <bits/stdc++.h>
int recursion(int ind,vector<int> &dp,vector<int> &nums){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind]+recursion(ind-2,dp,nums);
    int notPick=0+recursion(ind-1,dp,nums);
    return dp[ind]=max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    return recursion(n-1,dp,nums);
}
```

## Tabulation

```cpp
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    dp[0]=nums[0];
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1)
        pick=nums[i]+dp[i-2];
        int nonPick=0+dp[i-1];
        dp[i]=max(pick,nonPick);
    }
    return dp[n-1];
}
```

## Space Optimized

```cpp
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int prev=nums[0];
    int prev2=0;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1)
        pick=nums[i]+prev2;
        int nonPick=0+prev;
        int curr=max(pick,nonPick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
```

---

# [**House Robber**](https://leetcode.com/problems/house-robber/description/)

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1)
            pick=nums[i]+dp[i-2];
            int nonPick=0+dp[i-1];
            dp[i]=max(pick,nonPick);
        }
        return dp[n-1];
    }
};
```

---

# [**House Robber II**](https://leetcode.com/problems/house-robber-ii/description/)

```cpp
#define ll long long int
class Solution {
public:
    ll solve(vector<int> &nums){
        int n=nums.size();
        vector<ll> dp(n,-1);
        dp[0]=nums[0]*1LL;
        for(int i=1;i<n;i++){
            ll pick=nums[i];
            if(i>1) pick=nums[i]+dp[i-2];
            ll nonPick=0+dp[i-1];
            dp[i]=max(pick,nonPick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> nums1,nums2;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) nums1.push_back(nums[i]);
            if(i!=n-1) nums2.push_back(nums[i]);
        }
        return max(solve(nums1),solve(nums2));
    }
};
```

---

# Starting 2D DP

# [**Ninja's Training**](https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf)

## recursion

```cpp
int recursion(vector<vector<int>>&points,int day,int lastIndex){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=lastIndex){
                maxi=max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=lastIndex){
            int pointsToday=points[day][i]+recursion(points,day-1,i);
            maxi=max(maxi,pointsToday);
        }

    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(3,0));
    return recursion(points,n-1,4);

}
```

## Memoization

```cpp
int recursion(vector<vector<int>>&points,int day,int lastIndex,vector<vector<int>>&dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=lastIndex){
                maxi=max(maxi,points[day][i]);
            }
        }
        return maxi;
    }
    if(dp[day][lastIndex]!=-1) return dp[day][lastIndex];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=lastIndex){
            int pointsToday=points[day][i]+recursion(points,day-1,i,dp);
            maxi=max(maxi,pointsToday);
        }

    }
    // return maxi;
    return dp[day][lastIndex]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return recursion(points,n-1,3,dp);

}
```

## Tabulation

```cpp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));
    for(int day=1;day<n;day++){
        for(int lastIndex=0;lastIndex<4;lastIndex++){
            dp[day][lastIndex]=0;
            int maxi=0;
            for(int task=0;task<3;task++){
                if(lastIndex!=task){
                    int pointToday=points[day][task]+dp[day-1][task];
                    maxi=max(pointToday,maxi);
                }
            }
            dp[day][lastIndex]=maxi;
        }
    }
    return dp[n-1][3];

}
```

## Space Optimized

```cpp
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> dp(4,-1);
    dp[0]=max(points[0][1],points[0][2]);
    dp[1]=max(points[0][0],points[0][2]);
    dp[2]=max(points[0][0],points[0][1]);
    dp[3]=max(points[0][0],max(points[0][1],points[0][2]));
    for(int day=1;day<n;day++){
        vector<int> temp(4,-1);
        for(int lastIndex=0;lastIndex<4;lastIndex++){
            temp[lastIndex]=0;
            int maxi=0;
            for(int task=0;task<3;task++){
                if(lastIndex!=task){
                    int pointToday=points[day][task]+dp[task];
                    maxi=max(pointToday,maxi);
                }
            }
            temp[lastIndex]=maxi;
        }
        dp=temp;
    }
    return dp[3];

}
```

---

# [**Unique Paths**](https://leetcode.com/problems/unique-paths/description/)

## Recursion

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1) return 1;
        if(m<0 || n<0) return 0;
        int l=uniquePaths(m-1,n);
        int r=uniquePaths(m,n-1);
        return l+r;
    }
};
```

## Memoization

```cpp
class Solution {
public:
    int recursion(int m,int n ,vector<vector<int>> &dp){
        if(m==1 && n==1) return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n]!=-1) return dp[m][n];
        int l=recursion(m-1,n,dp);
        int r=recursion(m,n-1,dp);
        return dp[m][n]=l+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return recursion(m,n,dp);
    }
};
```

## Tabulation

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                dp[i][j]=1;
                else
                {
                int l=0,r=0;
                if(i>0) l=dp[i-1][j];
                if(j>0) r=dp[i][j-1];
                dp[i][j]=l+r;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```

---

# [**Minimum Path Sum**](https://leetcode.com/problems/minimum-path-sum/description/)

## Recursion+Memoization

```cpp
class Solution {
public:
    int recursion(int m,int n,vector<vector<int>> &grid,vector<vector<int>>&dp){
        if(m==0 && n==0) return grid[m][n];
        if(m<0 || n<0) return INT_MAX;
        if(dp[m][n]!=-1) return dp[m][n];
        int l=recursion(m-1,n,grid,dp);
        int r=recursion(m,n-1,grid,dp);
        return dp[m][n]=grid[m][n]+min(l,r);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recursion(m-1,n-1,grid,dp);
    }
};
```

## Tabulation

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i==0 && j==0) dp[i][j]=grid[i][j];
               else {
                   int l=INT_MAX,r=INT_MAX;
                   if(i>0) l=grid[i][j]+dp[i-1][j];
                   if(j>0) r=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(l,r);
               }

            }
        }
        return dp[m-1][n-1];
    }
};
```

---

# [**Unique Paths II**](https://leetcode.com/problems/unique-paths-ii/description/)

## Recursion+Memoization

```cpp
class Solution {
public:
    int recursion(int m,int n,vector<vector<int>> &dp,vector<vector<int>> &grid){
        if(m==0 && n==0) return 1;
        if(m<0 || n<0 || grid[m][n]==1) return 0;
        int l=0,r=0;
        if(dp[m][n]!=-1) return dp[m][n];
        if(m>0) l=recursion(m-1,n,dp,grid);
        if(n>0) r=recursion(m,n-1,dp,grid);
        return dp[m][n]=l+r;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(grid[m-1][n-1]) return 0;
        if(grid[0][0]) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(m-1,n-1,dp,grid);
    }
};
```

## Tabulation

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(grid[m-1][n-1]) return 0;
        if(grid[0][0]) return 0;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else {
                    if(grid[i][j]==1) dp[i][j]=0;
                    else {
                        int l=0,r=0;
                        if(i>0) l=dp[i-1][j];
                        if(j>0) r=dp[i][j-1];
                        dp[i][j]=l+r;
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};
```

---

# [**Unique Paths III**](https://leetcode.com/problems/unique-paths-iii/description/)

```cpp
class Solution {
public:
    int recursion(int i,int j,int fi,int fj,vector<vector<int>>&grid,int n,int m,int toVisit,vector<vector<int>> &dp){
        if(i==fi && j==fj){
            return (toVisit==1)?1:0;
        }
        if(i<0 || j <0 || i>=m || j >=n ||grid[i][j]==-1) return 0;
        // if(dp[i][j]!=-1) return dp[i][j];
        grid[i][j]=-1;
        int l=0,r=0,u=0,d=0;
        if(i>0) l=recursion(i-1,j,fi,fj,grid,n,m,toVisit-1,dp);
        if(j>0) r=recursion(i,j-1,fi,fj,grid,n,m,toVisit-1,dp);
        if(i<m) u=recursion(i+1,j,fi,fj,grid,n,m,toVisit-1,dp);
        if(j<n) d=recursion(i,j+1,fi,fj,grid,n,m,toVisit-1,dp);
        grid[i][j]=0;
        return r+l+u+d;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
     int m=grid.size();
     if(m==0) return 0;
     int n=grid[0].size();
     int toVisit = 0;
     pair<int,int> start={-1,-1},end={-1,-1};
     vector<vector<int>> dp(n,vector<int>(m,-1));
     for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    start = {i, j};
                }
                if (grid[i][j] == 2) {
                    end = {i, j};
                }
                if (grid[i][j] != -1) {
                    toVisit++;
                }
            }
        }
     return recursion(start.first, start.second, end.first, end.second, grid, n, m,toVisit,dp);



    }
};
```

---

# [**Triangle**](https://leetcode.com/problems/triangle/description/)

## Recursion

```cpp
class Solution {
public:
    int recursion(vector<vector<int>>& triangle,vector<vector<int>>&dp,int i,int j,int n){
        if(i==n-1) return triangle[n-1][j];
        int d=recursion(triangle,dp,i+1,j,n);
        int dg=recursion(triangle,dp,i+1,j+1,n);
        return triangle[i][j]+min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recursion(triangle,dp,0,0,n);
    }
};
```

## Memoization

```cpp
class Solution {
public:
    int recursion(vector<vector<int>>& triangle,vector<vector<int>>&dp,int i,int j,int n){
        if(i==n-1) return triangle[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d=recursion(triangle,dp,i+1,j,n);
        int dg=recursion(triangle,dp,i+1,j+1,n);
        return dp[i][j]=triangle[i][j]+min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recursion(triangle,dp,0,0,n);
    }
};
```

## Tabulation

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int d=dp[i+1][j];
                 int dg=dp[i+1][j+1];
                 dp[i][j]=triangle[i][j]+min(d,dg);
            }
        }
        return dp[0][0];
    }
};
```

---

# [**Minimum Falling Path Sum**](https://leetcode.com/problems/minimum-falling-path-sum/description/)

## Recursion + Memoization

```cpp
class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<vector<int>>& mat, int row, int col, int n) {
        if (col < 0 || col >= n || row >= n) return 1e9;
        if (row == n - 1) return mat[row][col];
        if (dp[row][col] != -1) return dp[row][col];
        int down = recursion(dp, mat, row + 1, col, n);
        int downDiag = recursion(dp, mat, row + 1, col + 1, n);
        int upperDiag = recursion(dp, mat, row + 1, col - 1, n);
        return dp[row][col] = mat[row][col] + min({down, downDiag, upperDiag});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = 1e9;
        for (int col = 0; col < n; col++) {
            ans = min(ans, recursion(dp, mat, 0, col, n));
        }

        return ans;
    }
};
```

## Recursion + Memoization(Reverse)

```cpp
class Solution {
public:
    int recursion(vector<vector<int>> &dp, vector<vector<int>>& mat, int row, int col, int n) {
        if (col < 0 || col >= n) return 1e9;
        if (row == 0) return mat[row][col];
        if (dp[row][col] != -1) return dp[row][col];
        int down = recursion(dp, mat, row - 1, col, n);
        int downDiag = recursion(dp, mat, row - 1, col - 1, n);
        int upperDiag = recursion(dp, mat, row - 1, col + 1, n);
        return dp[row][col] = mat[row][col] + min({down, downDiag, upperDiag});
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = 1e9;
        for (int col = 0; col < n; col++) {
            ans = min(ans, recursion(dp, mat, n-1, col, n));
        }

        return ans;
    }
};
```

## Tabulation

```cpp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for(int j=0;j<n;j++) dp[0][j]= mat[0][j];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0) continue;
                int down=INT_MAX,downDiag=INT_MAX,upperDiag=INT_MAX;
                down=dp[i-1][j];
                if(j>0) downDiag=dp[i-1][j-1];
                if(j<n-1)upperDiag=dp[i-1][j+1];
                dp[i][j]=mat[i][j]+min({down,downDiag,upperDiag});
            }
        }
        int ans = 1e9;
        for (int col = 0; col < n; col++) {
            ans=min(ans,dp[n-1][col]);
        }

        return ans;
    }
};
```

---

# [**Chocolated Pickup 3D DP**](https://www.geeksforgeeks.org/problems/chocolates-pickup/1)

## Recursion

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int recursion(int i,int j1,int j2,int n,int m,vector<vector<int>> &grid){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi=-1e8;
    // there will be 9 ways (+1,0,-1)*3 then writting in the loop;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+=recursion(i+1,j1+dj1,j2+dj2,n,m,grid);
                maxi=max(maxi,value);
            }
        }
        return maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code
        return recursion(0,0,m-1,n,m,grid);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
```

## Memoization

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int recursion(int i,int j1,int j2,int n,int m,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e8;
    // there will be 9 ways (+1,0,-1)*3 then writting in the loop;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+=recursion(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return recursion(0,0,m-1,n,m,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends
```

## Tabulation

```cpp
class Solution {
  public:
    int recursion(int i,int j1,int j2,int n,int m,vector<vector<int>> &grid,vector<vector<vector<int>>>&dp){
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e8;
        if(i==n-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=-1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value=0;
                if(j1==j2) value=grid[i][j1];
                else value=grid[i][j1]+grid[i][j2];
                value+=recursion(i+1,j1+dj1,j2+dj2,n,m,grid,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1e8)));
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    dp[n-1][j1][j2] = grid[n-1][j1];
                } else {
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    for (int dj1 = -1; dj1 <= 1; dj1++) {
                        for (int dj2 = -1; dj2 <= 1; dj2++) {
                            int value = 0;
                            if (j1 == j2) {
                                value = grid[i][j1];
                            } else {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;
                            if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m) {
                                value += dp[i+1][newJ1][newJ2];
                            } else {
                                value += -1e8;
                            }

                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }

};
```

---

# [**Subset Sum Problem**](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1)

## Recursion + Memoization

```cpp
    bool recursion(vector<int> &arr,int ind,int target,vector<vector<int>> &dp){
        if(target==0) return true;
        if(ind==0) return arr[ind]==target;
        if(dp[ind][target]!=-1) return dp[ind][target]==1;
        bool notTake=recursion(arr,ind-1,target,dp);
        bool take=false;
        if(target>=arr[ind]){
            take=recursion(arr,ind-1,target-arr[ind],dp);
        }
        bool ans=(take || notTake);
        dp[ind][target]=(ans==true)?1:0;
        return dp[ind][target]==1?true:false;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return recursion(arr,n-1,sum,dp);
    }
```

## Tabulation

```cpp
bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++) dp[i][0]=1;
        if(arr[0]<=sum)
        dp[0][arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=(dp[i-1][j]==1);
                bool take=false;
                if(j>=arr[i]){
                    take=(dp[i-1][j-arr[i]]==1);
                }
                bool ans=(take || notTake);
                dp[i][j]=(ans==true)?1:0;
            }
        }
        return dp[n-1][sum]==1;
    }
```

---

# [**Partition Equal Subset Sum**](https://leetcode.com/problems/partition-equal-subset-sum/)

```cpp
class Solution {
public:
    bool recursion(vector<int> &nums,int sum,int ind,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(ind<0 || sum<0) return false;
        if(ind==0) return sum==nums[0];
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool notTake=recursion(nums,sum,ind-1,dp);
        bool take=recursion(nums,sum-nums[ind],ind-1,dp);
        bool ans=(take || notTake);
        dp[ind][sum]=((ans==true)?1:0);
        return dp[ind][sum]==1;

    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum&1) return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return recursion(nums,sum/2,n-1,dp);
    }
};
```

---

# [**Array partition with minimum difference**]()

```cpp
bool recursion(vector<vector<int>> &dp,vector<int>&arr,int ind,int target){
	if(target==0) return true;
	if(ind<0 || target<0) return false;
	bool notTake=recursion(dp,arr,ind-1,target);
	bool take=false;
        if (target >= arr[ind]) {
          take = recursion(dp, arr, ind - 1, target - arr[ind]);
        }
        int ans=(take|| notTake);
		dp[ind][target]=(ans==true)?1:0;
		return dp[ind][target]==1;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum=accumulate(begin(arr),end(arr),0LL);
	vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
    for(int i=0;i<n;i++) dp[i][0]=1;
	if(arr[0]<=sum) dp[0][arr[0]]=1;
	for(int ind=1;ind<n;ind++){
		for(int target=1;target<=sum;target++){
			bool notTake=dp[ind-1][target];
			bool take=false;
			if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
			dp[ind][target]=(take | notTake);

		}
	}
	// recursion(dp,arr,n-1,sum);
	int mini=1e9;
	for(int s1=0;s1<=sum/2;s1++){
		if(dp[n-1][s1]==1){
			 mini = min(mini, abs((sum - s1) - s1));
		}
	}
	return mini;
}

```

---

# [**GFG Minimum sum partition**](https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1)

```cpp
int minDifference(int arr[], int n)  {
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    vector<vector<bool>> dp(n,vector<bool>(sum,0));
	    for(int i=0;i<n;i++) dp[i][0]=true;
	    if(arr[0]<=sum) dp[0][arr[0]]=true;
	    for(int ind=1;ind<n;ind++){
	        for(int target=1;target<=sum;target++){
	            bool take=false;
	            bool notTake=dp[ind-1][target];
	            if(target>=arr[ind]) take=dp[ind-1][target-arr[ind]];
	            dp[ind][target]=(take | notTake);
	        }
	    }
	    int mini=1e9;
	    for(int s1=0;s1<=sum/2;s1++){
	        if(dp[n-1][s1]){
	            mini=min(mini,abs((sum-s1)-s1));
	        }
	    }
	    return mini;

	}
```

```apache
1.Why if(arr[0] <= sum) dp[0][arr[0]] = true;:
This is initializing the first element of the dp array. It means that if the first element arr[0] is less than or equal to the total sum, then it is possible to form a subset with this sum. This initialization is necessary to handle the base case for dynamic programming when processing subsequent elements.
2.Why if(dp[n-1][s1]) mini = min(mini, abs((sum-s1) - s1));:
Here, dp[n-1][s1] checks whether it’s possible to form a subset with sum s1 using all elements (up to index n-1). If so, you compute the absolute difference between sum - s1 (the sum of the other subset) and s1 and update the minimum difference (mini). The goal is to minimize the difference between the two subset sums.
3.Why use n-1:
n-1 represents the last element in the array arr when using 0-based indexing. The dynamic programming table dp has size n, where dp[i][target] tells if it’s possible to form the sum target using elements from arr[0] to arr[i]. Thus, dp[n-1] checks if it’s possible to form the sum using all elements from the array.
```

## Optimized

```cpp
int minSubsetSumDifference(vector<int>& arr, int n) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> dp(sum / 2 + 1, false);

    dp[0] = true;
    for (int num : arr) {
        for (int target = sum / 2; target >= num; target--) {
            dp[target] = dp[target] || dp[target - num];
        }
    }
    int mini = INT_MAX;
    for (int s1 = sum / 2; s1 >= 0; s1--) {
        if (dp[s1]) {
            mini = min(mini, abs((sum - s1) - s1));
        }
    }

    return mini;
}
```

---

# [**Partition Equal Subset Sum**](https://leetcode.com/problems/partition-equal-subset-sum/description/)

```cpp
class Solution {
public:
    bool recursion(vector<int> &nums,int sum,int ind,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(ind<0 || sum<0) return false;
        if(ind==0) return sum==nums[0];
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        bool notTake=recursion(nums,sum,ind-1,dp);
        bool take=recursion(nums,sum-nums[ind],ind-1,dp);
        bool ans=(take || notTake);
        dp[ind][sum]=((ans==true)?1:0);
        return dp[ind][sum]==1;

    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(begin(nums),end(nums),0);
        if(sum&1) return false;
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return recursion(nums,sum/2,n-1,dp);
    }
};
```

---

# [**Partition to K Equal Sum Subsets**](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/)

```cpp
// class Solution {
// public:
//     bool recursion(vector<vector<int>> &dp,vector<int> &nums,int k,int ind,int target){
//           if(k==0) return true;
//           if(ind<0) return false;
//           if(dp[ind][target]!=-1) return dp[ind][target]==1;
//           if(target==0) {
//             bool x=recursion(dp,nums,k-1,ind,target);
//             dp[ind][target]=(x==true?1:0);
//             return x;
//            }
//            bool pick=false;
//            bool nonPick=recursion(dp,nums,k,ind-1,target);
//            if(target>=nums[ind]) pick=recursion(dp,nums,k,ind-1,target-nums[ind]);
//            bool ans=(pick || nonPick);
//            dp[ind][target]=(ans==true?1:0);
//            return ans;

//     }
//     bool canPartitionKSubsets(vector<int>& nums, int k) {
//         int n=nums.size();
//         sort(nums.begin(), nums.end(), greater<int>());

//         int sum=accumulate(begin(nums),end(nums),0);
//         int target=sum/k;
//         if (nums[0] > target) return false;
//         if(sum % k !=0) return false;
//         vector<vector<int>> dp(n,vector<int>(target+1,-1));
//         return recursion(dp,nums,k,n-1,target);
//     }
// };
class Solution {
public:
    bool canPartitionHelper(vector<int>& nums, vector<bool>& used, int target, int k, int start, int currSum) {
        if (k == 1) return true;
        if (currSum == target)
            return canPartitionHelper(nums, used, target, k - 1, 0, 0);

        for (int i = start; i < nums.size(); ++i) {
            if (!used[i] && currSum + nums[i] <= target) {
                used[i] = true;
                if (canPartitionHelper(nums, used, target, k, i + 1, currSum + nums[i]))
                    return true;
                used[i] = false;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target) return false;

        vector<bool> used(nums.size(), false);
        return canPartitionHelper(nums, used, target, k, 0, 0);
    }
};
```

---

# [**Perfect Sum Problem**](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1)

```cpp
int recursion(int sum,int ind,int arr[],vector<vector<int>> &dp){
	    if(ind<0) {
	        if(sum==0) return 1;
	        return 0;
	    }
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    int pick=0;
	    int notPick=recursion(sum,ind-1,arr,dp);
	    if(sum>=arr[ind]) pick=recursion(sum-arr[ind],ind-1,arr,dp);
	    return dp[ind][sum]=(pick+notPick)%mod;

	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return recursion(sum,n-1,arr,dp);
	}
```

---

# [**Partitions with Given Difference**](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

# [**Same Problem on CN**](https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM)

```cpp
int recursion(vector<vector<int>> &dp, vector<int> &arr, int ind, int target) {
    if(ind<0) {
         if (target == 0) return 1;
         return 0;
    }
    if (dp[ind][target] != -1) return dp[ind][target];

    int notPick = recursion(dp, arr, ind - 1, target);
    int pick = 0;
    if (target >= arr[ind]) pick = recursion(dp, arr, ind - 1, target - arr[ind]);

    return dp[ind][target] = (pick + notPick)%mod;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if ((sum + d) % 2 != 0) return 0;

    int target = (sum + d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return recursion(dp, arr, n - 1, target);
}
```

---

# [**0-1 KnapSack Problem**](https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)

```cpp
int recursion(int target,vector<int> &wt,vector<int> &val,int ind,vector<vector<int>> &dp){
        if(ind==0){
            if(wt[0]<=target) return val[0];
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int pick=INT_MIN;
        int notPick=0+recursion(target,wt,val,ind-1,dp);
        if(wt[ind]<=target) pick=val[ind]+recursion(target-wt[ind],wt,val,ind-1,dp);
        return dp[ind][target]=max(pick,notPick);

    }
    int knapSack(int target, vector<int>& wt, vector<int>& val) {
        // Your code here
        int n=wt.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return recursion(target,wt,val,n-1,dp);

    }
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
