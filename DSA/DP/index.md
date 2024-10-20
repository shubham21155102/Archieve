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

# [** Coin Change Problem**](https://leetcode.com/problems/coin-change/))

## Recursion+Memoization

```cpp
class Solution {
public:
    int recursion(vector<int> &coins,vector<vector<int>>&dp,int ind,int amt){
        if(amt==0) return 0;
        if(ind< 0 || amt<0) return 1e9;
        if(dp[ind][amt]!=-1) return dp[ind][amt];
        int notPick=recursion(coins,dp,ind-1,amt);
        int pick=1e9;
        if(amt>=coins[ind]) pick=1+recursion(coins,dp,ind,amt-coins[ind]);
        return dp[ind][amt]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int result=recursion(coins,dp,n-1,amount);
        return result==1e9?-1:result;
    }
};
```

## Tabulation

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,1e9));
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int i=0;i<n;i++){
            for(int amt=1;amt<=amount;amt++){
                 int notPick = (i > 0) ? dp[i - 1][amt] : 1e9;
                 int pick=1e9;
                 if(amt>=coins[i]) pick=1+dp[i][amt-coins[i]];
                 dp[i][amt]=min(pick,notPick);
            }
        }
       int result= dp[n-1][amount];
       return result==1e9?-1:result;
    }
};
```

---

# [**Target Sum**](https://leetcode.com/problems/target-sum/)

```cpp
class Solution {
public:
    int recursion(vector<vector<int>> &dp,vector<int> &nums,int ind,int target){
          if(ind==0) {
            if(target==0 && nums[0]==0) return 2;
            if(target==nums[0] || target==0) return 1;
            return 0;
          }
          if(dp[ind][target]!=-1) return dp[ind][target];
          int pick=0;
          int notPick=recursion(dp,nums,ind-1,target);
          if(target>=nums[ind]) pick=recursion(dp,nums,ind-1,target-nums[ind]);
          return dp[ind][target]=(pick+notPick);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(begin(nums),end(nums),0);
         if (sum < abs(target) || (sum + target) % 2 != 0) return 0;
        int n=nums.size();
        target=(sum+target)/2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return recursion(dp,nums,n-1,target);
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

---

### Recursion

```cpp
class Solution {
public:
    int recursion(int i,int j,string text1,string text2){
        if(i<0 || j<0) return 0;
        if(text1[i]==text2[j]) return 1+recursion(i-1,j-1,text1,text2);
        return max(recursion(i-1,j,text1,text2),recursion(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        return recursion(n-1,m-1,text1,text2);
    }
};
```

### Memoization

```cpp
class Solution {
public:
    int recursion(int i,int j,string text1,string text2,vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+recursion(i-1,j-1,text1,text2,dp);
        return dp[i][j]= max(recursion(i-1,j,text1,text2,dp),recursion(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recursion(n-1,m-1,text1,text2,dp);
    }
};
```

### Shifted Memoization

```cpp
class Solution {
public:
    int recursion(int i,int j,string text1,string text2,vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i-1]==text2[j-1]) return dp[i][j]=1+recursion(i-1,j-1,text1,text2,dp);
        return dp[i][j]= max(recursion(i-1,j,text1,text2,dp),recursion(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recursion(n,m,text1,text2,dp);
    }
};
```

### Why Shifted Memoization

```apache
1. Why is the memoization array shifted by 1?
The memoization array is shifted by 1 because the base case of the recursion is when i or j becomes 0. In the recursion, we are using 0-based indexing, so we need to shift the indices by 1 to match the base case of the recursion.
```

### Tabulation

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++) dp[i][0]=0;
        for(int j=0;j<m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};
```

### Space Optimized Tabulation

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return curr[m];
    }
};
```

---

# Print LCS

## Method 1

```cpp
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int len=dp[n][m];
	int i=n,j=m;
	string ans;
	int ind=len-1;
	while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
		ans.push_back(s1[i-1]);
		   ind--;
		   i--;
		   j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
            i--;
		}
		else {
           j--;
		}
	}
	reverse(begin(ans),end(ans));
	return ans;
}
```

## Method 2

```cpp
string findLCS(int n, int m,string &s1, string &s2){
	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int len=dp[n][m];
	int i=n,j=m;
	string ans(len,'-');
	int ind=len-1;
	while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
           ans[ind]=s1[i-1];
		   ind--;
		   i--;
		   j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
            i--;
		}
		else {
           j--;
		}
	}
	return ans;
}
```

---

# [**Print all LCS sequences**](https://www.geeksforgeeks.org/problems/print-all-lcs-sequences3413/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card)

You are given two strings `s` and `t`. Now your task is to print all longest common subsequences in lexicographical order.

> **Note:** A subsequence is derived from another string by deleting some or none of the elements without changing the order of the remaining elements.

### Example 1:

**Input:**
`s = abaaa`
`t = baabaca`

**Output:**

```plaintext
aaaa
abaa
baaa
```

**Explanation:**
Length of LCS is 4. In lexicographical order, the longest common subsequences are:
`aaaa, abaa, baaa`

### Example 2:

**Input:**
`s = aaa`
`t = a`

**Output:**

```plaintext
a
```

### Your Task:

You do not need to read or print anything. Your task is to complete the function `all_longest_common_subsequences()` which takes strings `s` and `t` as first and second parameters respectively and returns a list of strings that contains all possible longest common subsequences in lexicographical order.

### Expected Time Complexity:

O(n `<sup>`3 `</sup>`)

### Expected Space Complexity:

O(k \* n) where `k` is a constant less than `n`.

### Constraints:

- 1 ≤ Length of both strings ≤ 50

#### TLE

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recursion(vector<string> &ans,string &ds,int i,int j,vector<vector<int>> &dp,string s,string t){
        if(i==0 && j==0){
            reverse(begin(ds),end(ds));
            ans.push_back(ds);
            reverse(begin(ds),end(ds));
            return;
        }
        if(s[i-1]==t[j-1]){
            ds.push_back(s[i-1]);
            recursion(ans,ds,i-1,j-1,dp,s,t);
            ds.pop_back();
        }
       else {
    if (i > 0 && dp[i-1][j] == dp[i][j]) recursion(ans, ds, i-1, j, dp, s, t);
    if (j > 0 && dp[i][j-1] == dp[i][j]) recursion(ans, ds, i, j-1, dp, s, t);
}
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        vector<string> ans;
        string ds;
        recursion(ans,ds,n,m,dp,s,t);
        set<string> st(ans.begin(),ans.end());
        vector<string> ans2(st.begin(),st.end());
        return ans2;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends

```

#### Again TLE

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recursion(vector<vector<set<string>>> &memo,string &ds,int i,int j,vector<vector<int>> &dp,string s,string t,set<string>&temp){
        if(i==0 && j==0){
            reverse(begin(ds),end(ds));
            temp.insert(ds);
            reverse(begin(ds),end(ds));
            return;
        }
        if(!memo[i][j].empty()) {
            // temp.insert(memo[i][j].begin(),memo[i][j].end());
            // return;
            for (const string &subseq : memo[i][j]) {
                temp.insert(subseq);
            }
            return;
        }
        if(s[i-1]==t[j-1]){
            ds.push_back(s[i-1]);
            recursion(memo,ds,i-1,j-1,dp,s,t,temp);
            ds.pop_back();
        }
       else {
    if (i > 0 && dp[i-1][j] == dp[i][j]) recursion(memo, ds, i-1, j, dp, s, t,temp);
    if (j > 0 && dp[i][j-1] == dp[i][j]) recursion(memo, ds, i, j-1, dp, s, t,temp);
        }
        temp.insert(memo[i][j].begin(),memo[i][j].end());
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string ds;
        vector<vector<set<string>>> memo(n+1,vector<set<string>>(m+1));
        set<string>temp;
        recursion(memo,ds,n,m,dp,s,t,temp);
        return vector<string>(temp.begin(), temp.end());
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
```

### Optimized with Map

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void recursion(unordered_map<string,bool> &mp,string &ds,int i,int j,vector<vector<int>> &dp,string s,string t,set<string>&temp){
        if(i==0 && j==0){
            reverse(begin(ds),end(ds));
            temp.insert(ds);
            reverse(begin(ds),end(ds));
            return;
        }
        string key=to_string(i)+','+to_string(j)+ds;
        if(mp.find(key)!=mp.end()) return;
        mp[key]=true;
        if(s[i-1]==t[j-1]){
            ds.push_back(s[i-1]);
            recursion(mp,ds,i-1,j-1,dp,s,t,temp);
            ds.pop_back();
        }
       else {
    if (i > 0 && dp[i-1][j] == dp[i][j]) recursion(mp, ds, i-1, j, dp, s, t,temp);
    if (j > 0 && dp[i][j-1] == dp[i][j]) recursion(mp, ds, i, j-1, dp, s, t,temp);
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string ds;
        unordered_map<string,bool> mp;
        set<string>temp;
        recursion(mp,ds,n,m,dp,s,t,temp);
        return vector<string>(temp.begin(), temp.end());
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
```

---

# [**Longest Common Substring**](https://www.geeksforgeeks.org/problems/longest-common-substring1452/1)

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string s, string t) {
        // your code here
        int n=s.size();
        int m=t.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends
```

---

# [**Longest Palindromic Subsequence**](https://leetcode.com/problems/longest-palindromic-subsequence/)

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(begin(t),end(t));
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max({dp[i-1][j],dp[i][j-1]});
          }
        }
        return dp[n][n];
    }
};
```

---

[**Delete Operation for Two Strings**](https://leetcode.com/problems/delete-operation-for-two-strings/)

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m+n-2*dp[m][n];

    }
};
```

---

# [**Shortest Common Supersequence**](https://leetcode.com/problems/shortest-common-supersequence/)

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n,j=m;
        string ans;
        while(i>0 && j>0){
           if(s[i-1]==t[j-1]){
             ans+=s[i-1];
             i--;
             j--;
           }
           else {
            if(dp[i-1][j]>dp[i][j-1]){
                ans+=s[i-1];
                i--;
            }
            else {
                ans+=t[j-1];
                j--;
            }
           }
        }
        while(i>0){
          ans+=s[i-1];
          i--;
        }
        while(j>0){
            ans+=t[j-1];
            j--;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
```

---

# [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

### Recursion

```cpp
class Solution {
public:
    int recursion(string s,string t,int i,int j){
        if(j<0) return 1;
        if(i<0) return 0;
        if(s[i]==t[j]){
            return recursion(s,t,i-1,j-1)+recursion(s,t,i-1,j);
        }
        return recursion(s,t,i-1,j);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        return recursion(s,t,n-1,m-1);
    }
};
```

### Memoization

```cpp
class Solution {
public:
    int recursion(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=recursion(s,t,i-1,j-1,dp)+recursion(s,t,i-1,j,dp);
        }
        return dp[i][j]=recursion(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recursion(s,t,n-1,m-1,dp);
    }
};
```

### Shifted Memoization

```cpp
class Solution {
public:
    int recursion(string s,string t,int i,int j,vector<vector<int>> &dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
            return dp[i][j]=recursion(s,t,i-1,j-1,dp)+recursion(s,t,i-1,j,dp);
        }
        return dp[i][j]=recursion(s,t,i-1,j,dp);
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recursion(s,t,n,m,dp);
    }
};
```

### Tabulation

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};
```

### Space Optimized Tabulation

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> prev(m+1,0),curr(m+1,0);
        prev[0]=curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1]+prev[j];
                else curr[j]=prev[j];
            }
            prev=curr;
        }
        return (int)prev[m];
    }
};
```

---

# [Edit Distance](https://leetcode.com/problems/edit-distance/)

### Recursive

```cpp
class Solution {
public:
    int recursion(int i,int j,string s,string t){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s[i]==t[j]) return 0+recursion(i-1,j-1,s,t);
        int insertion=1+recursion(i,j-1,s,t);
        int deletion=1+recursion(i-1,j,s,t);
        int replacement=1+recursion(i-1,j-1,s,t);
        return min({insertion,deletion,replacement});
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        return recursion(n-1,m-1,s,t);
    }
};
```

### Memoization

```cpp
class Solution {
public:
    int recursion(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=0+recursion(i-1,j-1,s,t,dp);
        int insertion=1+recursion(i,j-1,s,t,dp);
        int deletion=1+recursion(i-1,j,s,t,dp);
        int replacement=1+recursion(i-1,j-1,s,t,dp);
        return dp[i][j]=min({insertion,deletion,replacement});
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return recursion(n-1,m-1,s,t,dp);
    }
};
```

### Shifted Memoization

```cpp
class Solution {
public:
    int recursion(int i,int j,string s,string t,vector<vector<int>> &dp){
        if(i==0) return j;
        if(j==0) return i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) return dp[i][j]=0+recursion(i-1,j-1,s,t,dp);
        int insertion=1+recursion(i,j-1,s,t,dp);
        int deletion=1+recursion(i-1,j,s,t,dp);
        int replacement=1+recursion(i-1,j-1,s,t,dp);
        return dp[i][j]=min({insertion,deletion,replacement});
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return recursion(n,m,s,t,dp);
    }
};
```

### Tabulation

```cpp
class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=0;j<=m;j++) dp[0][j]=j;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
            }
        }
        return dp[n][m];
    }
};
```

### Space Optimized Tabulation

```cpp
class Solution {
public:
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j]=prev[j-1];
                else curr[j]=min({prev[j],curr[j-1],prev[j-1]})+1;
            }
            prev=curr;
        }
        return prev[m];
    }
};
```

---

# [Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

### Recursion

```cpp
class Solution {
public:
    bool recursion(int i,int j,string p,string s){
       if(i<0 && j<0) return true;
       if(i<0 && j>=0) return false;
       if(j<0 && i>=0) {
        for(int x=0;x<=i;x++){
            if(p[x]!='*') return false;
        }
        return true;
       }
       if(p[i]==s[j] || p[i]=='?') return recursion(i-1,j-1,p,s);
       if(p[i]=='*'){
        return recursion(i-1,j,p,s) || recursion(i,j-1,p,s);
       }
       return false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        return recursion(m-1,n-1,p,s);
    }
};
```

### Memoization

###### MLE(Memory Limit Exceeded)

```cpp
class Solution {
public:
    bool recursion(int i,int j,string p,string s,vector<vector<int>> &dp){
       if(i<0 && j<0) return true;
       if(i<0 && j>=0) return false;
       if(j<0 && i>=0) {
        for(int x=0;x<=i;x++){
            if(p[x]!='*') return false;
        }
        return true;
       }
       if(dp[i][j]!=-1) return dp[i][j]==1;
       if(p[i]==s[j] || p[i]=='?') return dp[i][j]=recursion(i-1,j-1,p,s,dp);
       if(p[i]=='*'){
        return dp[i][j]=(recursion(i-1,j,p,s,dp) || recursion(i,j-1,p,s,dp));
       }
       return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return recursion(m-1,n-1,p,s,dp);
    }
};
```

### Shifted Memoization

#### MLE(Memory Limit Exceeded)

```cpp
class Solution {
public:
    bool recursion(int i,int j,string p,string s,vector<vector<int>> &dp){
       if(i==0 && j==0) return true;
       if(i==0 && j>0) return false;
       if(j==0 && i>0) {
        for(int x=0;x<i;x++){
            if(p[x]!='*') return false;
        }
        return true;
       }
       if(dp[i][j]!=-1) return dp[i][j]==1;
       if(p[i-1]==s[j-1] || p[i-1]=='?') return dp[i][j]=recursion(i-1,j-1,p,s,dp);
       if(p[i-1]=='*'){
        return dp[i][j]=(recursion(i-1,j,p,s,dp) || recursion(i,j-1,p,s,dp));
       }
       return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        return recursion(m,n,p,s,dp);
    }
};
```

### Tabulation
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(m+1,vector<bool> (n+1,0));
        dp[0][0]=true;
        for(int j=1;j<=n;j++) dp[0][j]=false;
        for(int i=1;i<=m;i++){
            int flag=true;
            for(int x=0;x<i;x++){
                if(p[x]!='*') {
                    flag=false;
                    break;
                }
            }
             dp[i][0]=flag;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?') dp[i][j]=dp[i-1][j-1];
                if(p[i-1]=='*') dp[i][j]= (dp[i-1][j] || dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
```
### Space Optimized Tabulation

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=p.size();
        int n=s.size();
        vector<bool> prev(n+1,0),curr(n+1,0);
        prev[0]=1;
        for(int j=1;j<=n;j++) prev[j]=false;
        for(int i=1;i<=m;i++){
            bool flag=true;
            for(int x=1;x<=i;x++){
                if(p[x-1]!='*') {
                    flag=false;
                    break;
                }
            }
             curr[0]=flag;
            for(int j=1;j<=n;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?') curr[j]=prev[j-1];
                else if(p[i-1]=='*') curr[j]= (prev[j] || curr[j-1]);
                else curr[j]=false;
            }
            prev=curr;
        }
        return prev[n];
    }
};
```