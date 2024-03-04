# Problems On Binary Search

[704. Binary Search](https://leetcode.com/problems/binary-search)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target) return mid;
           else if(nums[mid]>target) e=mid-1;
           else s=mid+1;
        }
        return -1;
    }
};
```

[Implement Lower Bound](https://www.codingninjas.com/studio/problems/lower-bound_8165382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf)

```cpp
int lowerBound(vector<int> arr, int n, int x) {
	int ans = n;
	int s=0;
	int e=n-1;
	while(s<=e){
		int mid=s+(e-s)/2;
		if(arr[mid]>=x){
			ans=mid;
			e=mid-1;
		}
		else {
			s=mid+1;
		}
	}
		return ans;
}

```

[ Implement Upper Bound](https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM)

```cpp
int upperBound(vector<int> &arr, int x, int n) {
    int s = 0;
    int e = n-1; 
	int ans=n;
    while (s <= e) { 
        int mid = s + (e - s) / 2;
        if(arr[mid]>x){
			e=mid-1;
			ans=mid;
		}
		else{
          s=mid+1;
		}
    }
    return ans;
}

```

[35. Search Insert Position](https://leetcode.com/problems/search-insert-position/description/)

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int ans=nums.size();
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=target){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
```
