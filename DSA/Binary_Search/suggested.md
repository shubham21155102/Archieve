# Suggested Problems

[2639. Find the Width of Columns of a Grid](https://leetcode.com/problems/find-the-width-of-columns-of-a-grid/description/)

```cpp
class Solution {
public:
    int length(int n){
        int l=0;
        while(n>0){
            l++;
            n/=10;
        }
        return l;
    }
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>v;
        for(int i=0;i<n;i++){
            int maxi=1;
            for(int j=0;j<m;j++){
               if(grid[j][i]<0){
                  int number=abs(grid[j][i]-0);
                  maxi=max(maxi,length(number)+1);
               }
               else{
                    int number=abs(grid[j][i]-0);
                    maxi=max(maxi,length(number));
               }
            }
            v.push_back(maxi);
        }
        return v;
    }
};
```

[2048. Next Greater Numerically Balanced Number](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

```cpp
class Solution {
public:
    bool isBeautiful(int num) {
        vector<int> map(10,0);
        while (num) {

            int digit = num % 10;
            map[digit]++;
            num /= 10;
        }
        for(int i=0; i<10; i++)
            if(map[i] && map[i]!=i) return false;
        return true;
    }
  
    int nextBeautifulNumber(int n) {
        while(true){
            ++n;
            if(isBeautiful(n)) return n;
        }
        return 1;
    }
};

```

[1279 · Count Numbers with Unique Digits](https://www.lintcode.com/problem/count-numbers-with-unique-digits/description)
