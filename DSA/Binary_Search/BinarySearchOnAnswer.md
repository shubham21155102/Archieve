# Binary Search On Answer

---

# 🐵 **Koko Eating Bananas** 🍌

Koko loves to eat bananas. There are **n** piles of bananas, where the **i-th** pile has `piles[i]` bananas. The guards have left and will return in **h** hours.

Koko can decide her bananas-per-hour eating speed **k**. Each hour, she picks a pile and eats **k** bananas. If the pile has fewer than **k** bananas, she eats all the bananas from that pile and won't eat any more bananas during that hour.

Koko likes to eat slowly 🍽️ but wants to finish eating all the bananas before the guards return ⏰.

**Your task:**
Return the minimum integer **k** such that Koko can eat all the bananas within **h** hours.

---

## 📋 **Example 1:**

**Input:**
`piles = [3, 6, 7, 11]`, `h = 8`

**Output:**
`4`

---

## 📋 **Example 2:**

**Input:**
`piles = [30, 11, 23, 4, 20]`, `h = 5`

**Output:**
`30`

---

## 📋 **Example 3:**

**Input:**
`piles = [30, 11, 23, 4, 20]`, `h = 6`

**Output:**
`23`

---

## ⚙️ **Constraints:**

- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

---

## 💻 **Solution (C++):**

```cpp
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long ans = *max_element(begin(piles), end(piles));
        long totalBananas = accumulate(begin(piles), end(piles), 0LL);
        long left = (totalBananas + h - 1) / h;  // Minimum speed based on total bananas and hours
        long right = ans;

        while (left <= right) {
            long mid = left + (right - left) / 2;  // Middle speed to check
            long requiredTime = 0LL;

            for (auto bananas : piles) {
                requiredTime += (bananas + mid - 1) / mid;  // Time to finish each pile at speed mid
            }

            if (requiredTime <= h) {
                ans = mid;  // Update answer with current middle speed
                right = mid - 1;  // Try lower speeds
            } else {
                left = mid + 1;  // Increase speed
            }
        }

        return (int)ans;
    }
};
```

---

# 🍬 **Maximum Candies Allocated to Children** 🎉

You are given a **0-indexed** integer array `candies`. Each element in the array represents a pile of candies with `candies[i]` candies. You can split each pile into any number of sub-piles, but merging two piles together is not allowed.

You are also given an integer `k`, representing the number of children. Your task is to allocate piles of candies such that each child gets the same number of candies.
Each child can take at most one pile, and some piles may go unused.

**Objective:**
Return the maximum number of candies each child can get.

---

## 📋 **Example 1:**

**Input:**
`candies = [5, 8, 6]`, `k = 3`

**Output:**
`5`

**Explanation:**
We can divide `candies[1]` into two piles of size 5 and 3, and `candies[2]` into two piles of size 5 and 1. Now we have five piles of candies: `[5, 5, 3, 5, 1]`. We allocate the three piles of size 5 to the children.

---

## 📋 **Example 2:**

**Input:**
`candies = [2, 5]`, `k = 11`

**Output:**
`0`

**Explanation:**
There are 11 children but only 7 candies in total. It is impossible to ensure each child receives at least one candy, so the answer is 0.

---

## ⚙️ **Constraints:**

- `1 <= candies.length <= 10^5`
- `1 <= candies[i] <= 10^7`
- `1 <= k <= 10^12`

---

## 💻 **Solution (C++):**

```cpp
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = accumulate(begin(candies), end(candies), 0LL);
        if (sum < k) return 0;

        long long l = 1, r = *max_element(begin(candies), end(candies));
        long long ans = 0;

        while (l <= r) {
            long long m = l + (r - l) / 2;
            long long count = 0;

            for (auto num : candies) {
                count += num / m;
            }

            if (count >= k) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return ans;
    }
};
```

---

# 🛍️ **Minimize Maximum Products Distribution** 📦

You are given an integer `n`, representing the number of specialty retail stores. There are `m` product types, with their amounts provided in a **0-indexed** integer array `quantities`, where `quantities[i]` denotes the number of products of the `i-th` type.

The task is to distribute all products to the retail stores following these rules:

- A store can only be given at most one product type, but it can be given any amount of that product type.
- After distribution, each store will have some number of products (possibly 0). Let `x` represent the maximum number of products given to any store.

Your objective is to minimize `x`, i.e., minimize the maximum number of products given to any store.

---

## 📋 **Example 1:**

**Input:**
`n = 6`, `quantities = [11, 6]`

**Output:**
`3`

**Explanation:**An optimal distribution is:

- Distribute the 11 products of type 0 to four stores as: `[2, 3, 3, 3]`
- Distribute the 6 products of type 1 to the remaining two stores as: `[3, 3]`

The maximum number of products any store gets is `3`.

---

## 📋 **Example 2:**

**Input:**
`n = 7`, `quantities = [15, 10, 10]`

**Output:**
`5`

**Explanation:**An optimal distribution is:

- Distribute the 15 products of type 0 to three stores as: `[5, 5, 5]`
- Distribute the 10 products of type 1 to two stores as: `[5, 5]`
- Distribute the 10 products of type 2 to two stores as: `[5, 5]`

The maximum number of products any store gets is `5`.

---

## 📋 **Example 3:**

**Input:**
`n = 1`, `quantities = [100000]`

**Output:**
`100000`

**Explanation:**
With only one store, the store must take all 100000 products.

---

## ⚙️ **Constraints:**

- `m == quantities.length`
- `1 <= m <= n <= 10^5`
- `1 <= quantities[i] <= 10^5`

---

## 💻 **Solution (C++):**

```cpp
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long ans = *max_element(begin(quantities), end(quantities));
        long l = 1;
        long r = ans;

        while (l <= r) {
            long m = l + (r - l) / 2;
            long count = 0;

            for (auto num : quantities) {
                count += (num + m - 1) / m;
            }

            if (count <= n) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};
```

---

# 🏬 **Minimize Maximum Products Given to Retail Stores** 🛒

You are given an integer `n` representing the number of specialty retail stores. There are `m` product types with varying quantities, provided in a **0-indexed** integer array `quantities`, where `quantities[i]` indicates the number of products of the `i-th` type.

Your goal is to distribute all the products to the stores under the following conditions:

- Each store can only receive at most one product type, but it can receive any amount of that type.
- After the distribution, each store will have received a certain number of products (possibly none). Let `x` represent the **maximum number of products given to any store**. You want to minimize this `x`.

Return the minimum possible `x`.

---

## 📋 **Example 1:**

**Input:**
`n = 6`, `quantities = [11, 6]`

**Output:**
`3`

**Explanation:**An optimal distribution is:

- The 11 products of type 0 are distributed to four stores as: `[2, 3, 3, 3]`
- The 6 products of type 1 are distributed to two stores as: `[3, 3]`

The maximum number of products any store receives is `3`.

---

## 📋 **Example 2:**

**Input:**
`n = 7`, `quantities = [15, 10, 10]`

**Output:**
`5`

**Explanation:**An optimal distribution is:

- Distribute the 15 products of type 0 to three stores as: `[5, 5, 5]`
- Distribute the 10 products of type 1 to two stores as: `[5, 5]`
- Distribute the 10 products of type 2 to two stores as: `[5, 5]`

The maximum number of products any store receives is `5`.

---

## 📋 **Example 3:**

**Input:**
`n = 1`, `quantities = [100000]`

**Output:**
`100000`

**Explanation:**
With only one store, the store must take all 100,000 products.

---

## ⚙️ **Constraints:**

- `m == quantities.length`
- `1 <= m <= n <= 10^5`
- `1 <= quantities[i] <= 10^5`

---

## 💻 **Solution (C++):**

```cpp
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long ans = *max_element(begin(quantities), end(quantities));
        long l = 1, r = ans;

        while (l <= r) {
            long m = l + (r - l) / 2;
            long count = 0;

            for (auto num : quantities) {
                count += (num + m - 1) / m;
            }

            if (count <= n) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};
```

---

# 🚢 **Ship Capacity Problem**

A conveyor belt has packages that need to be shipped within a given number of days. Each package has a specific weight, and the goal is to determine the minimum capacity of the ship required to carry out this task. Let's break it down with some examples and explanations.

---

## Problem Statement 📋

You are given an array `weights`, where `weights[i]` represents the weight of the i-th package. You also have a variable `days`, which is the number of days you have to ship all the packages.

Each day, you load the ship with consecutive packages from the conveyor belt. The total weight loaded on the ship each day cannot exceed the ship's capacity.

The task is to find the minimum ship capacity that allows all packages to be shipped within the specified number of days.

---

### Constraints 🧩

- 1 ≤ days ≤ `weights.length` ≤ 50,000
- 1 ≤ `weights[i]` ≤ 500

---

### Example 1

```text
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15

Explanation:
A ship capacity of 15 is the minimum to ship all the packages in 5 days:

- Day 1: [1, 2, 3, 4, 5]
- Day 2: [6, 7]
- Day 3: [8]
- Day 4: [9]
- Day 5: [10]

Splitting the packages in any other way would either require more days or exceed the ship's capacity.
```

---

### Example 2

```text
Input: weights = [3,2,2,4,1,4], days = 3
Output: 6

Explanation:
With a ship capacity of 6, the packages can be shipped in 3 days as follows:

- Day 1: [3, 2]
- Day 2: [2, 4]
- Day 3: [1, 4]
```

---

### Example 3

```text
Input: weights = [1,2,3,1,1], days = 4
Output: 3

Explanation:
The packages are shipped as follows:

- Day 1: [1]
- Day 2: [2]
- Day 3: [3]
- Day 4: [1, 1]
```

---

## Approach 🚀

This problem can be solved using **binary search** and a **greedy approach**. The goal is to find the minimum capacity that allows us to ship all packages within `days` days.

We can perform a binary search on the ship's capacity, testing different capacities and counting how many days it would take to ship all the packages for each capacity.

### Steps:

1. **Binary Search Range**:

   - The minimum capacity should be the weight of the heaviest package (`max(weights)`).
   - The maximum capacity should be the sum of all package weights (`sum(weights)`).

2. **Check Function**:

   - For a given ship capacity, simulate the number of days it would take to ship the packages. If the number of days is less than or equal to `days`, the capacity is valid.

3. **Update Binary Search**:

   - If the current capacity is valid, reduce the capacity by moving to the left half of the search space.
   - Otherwise, increase the capacity by moving to the right half.

---

### Solution Code 💻

```cpp
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        long left = *max_element(weights.begin(), weights.end());
        long right = accumulate(weights.begin(), weights.end(), 0LL);
        long answer = right;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sum = 0LL;
            int requiredDays = 1;

            for (auto weight : weights) {
                if (sum + weight > mid) {
                    sum = weight;
                    requiredDays++;
                } else {
                    sum += weight;
                }
            }

            if (requiredDays <= days) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};
```

---

### Explanation of Code 🧑‍💻

1. **Initialization**:

   - `left`: The largest package weight (smallest possible ship capacity).
   - `right`: The sum of all package weights (largest possible ship capacity).
   - `answer`: Stores the minimum ship capacity that can ship all packages in `days`.

2. **Binary Search**:

   - We perform a binary search to find the minimum ship capacity. The middle capacity (`mid`) is calculated as the average of `left` and `right`.

3. **Check Validity**:

   - For each capacity, simulate how many days it would take to ship all packages by iterating over the weights.
   - If the current weight exceeds the capacity for the day, we increment the `requiredDays` and start a new day.

4. **Update Search Space**:

   - If the number of required days is less than or equal to `days`, we update the answer and continue searching in the left half.
   - Otherwise, we search in the right half for a larger capacity.

---

### Complexity Analysis ⏳

- **Time Complexity**: `O(N log W)` where `N` is the number of packages, and `W` is the sum of all weights. This is because we perform a binary search (`log W`) over the possible ship capacities, and for each capacity, we check the number of required days by iterating over all the packages (`N`).
- **Space Complexity**: `O(1)` (excluding the space required for the input).

---

### Summary 📦

- We used **binary search** to optimize the ship's capacity, which minimizes the number of days needed.
- The code ensures that all packages are shipped in the given order and within the required number of days.

---

# 📚 **Split Array Problem**

In this problem, you're tasked with splitting an integer array into `k` non-empty subarrays, such that the largest sum among these subarrays is minimized. The objective is to return the minimized largest sum.

---

## Problem Statement 🧩

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty subarrays such that the largest sum of any subarray is minimized.

### Subarray Definition:

A subarray is a contiguous part of the array.

---

### Constraints

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 10^6`
- `1 <= k <= min(50, nums.length)`

---

## Example Scenarios

### Example 1

```text
Input: nums = [7, 2, 5, 10, 8], k = 2
Output: 18

Explanation:
There are four ways to split nums into two subarrays:
- [7, 2, 5] and [10, 8], with the largest sum being 18.
- [7, 2], [5, 10, 8] has a larger sum of 23.
- Other splits would also yield larger sums.

Thus, the minimized largest sum of the split is 18.
```

---

### Example 2

```text
Input: nums = [1, 2, 3, 4, 5], k = 2
Output: 9

Explanation:
There are four possible ways to split the array:
- [1, 2, 3], [4, 5], where the largest sum is 9.
- Other splits yield larger sums.

The minimized largest sum of the split is 9.
```

---

## Approach 🚀

The approach to solving this problem is quite similar to the **Ship Capacity Problem** mentioned earlier. We will use a **binary search** strategy to minimize the largest sum of the subarrays by splitting the array into `k` parts.

### Steps

1. **Binary Search Range**:

   - The minimum possible value for the largest subarray sum is the largest element in `nums`, as this is the smallest any subarray can get.
   - The maximum possible value is the sum of all elements in `nums`, as this would correspond to a single subarray containing all elements.

2. **Check Function**:

   - For a given value of the largest sum, simulate the number of subarrays it would take to split the array such that the largest sum of each subarray is less than or equal to the current mid-point.
   - If we can split the array into `k` or fewer subarrays, this value is valid.

3. **Binary Search**:

   - Use binary search to find the minimum largest sum that allows splitting the array into exactly `k` subarrays.

---

## Solution Code 💻

```cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long left = *max_element(nums.begin(), nums.end());  // Minimum possible largest sum
        long long right = accumulate(nums.begin(), nums.end(), 0LL);  // Maximum possible largest sum
        long long answer = left;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long sum = 0LL;
            int requiredSplits = 1;

            for (auto num : nums) {
                if (sum + num > mid) {
                    sum = num;
                    requiredSplits++;
                } else {
                    sum += num;
                }
            }

            if (requiredSplits <= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return answer;
    }
};
```

---

### Code Explanation 🧑‍💻

1. **Initialization**:

   - `left`: The largest element in the array (`*max_element(nums.begin(), nums.end())`), representing the minimum possible largest sum.
   - `right`: The sum of all elements in the array (`accumulate(nums.begin(), nums.end(), 0LL)`), representing the maximum possible largest sum.
   - `answer`: This variable stores the minimized largest sum, initialized to `left`.

2. **Binary Search**:

   - We perform a binary search on the possible values of the largest sum (`left` to `right`).
   - At each step, we calculate the middle value (`mid`) and try to determine if we can split the array into `k` or fewer subarrays where the sum of each subarray is less than or equal to `mid`.

3. **Simulation**:

   - For each possible largest sum (`mid`), iterate over the elements of the array.
   - If adding the current element exceeds the current subarray sum limit (`mid`), start a new subarray and increment the `requiredSplits` counter.
   - If the number of subarrays required is less than or equal to `k`, it means the current value of `mid` is a valid solution, and we continue the search on the left half (`right = mid - 1`).
   - Otherwise, we search in the right half for a larger possible sum (`left = mid + 1`).

4. **Return**:

   - After the binary search, the value in `answer` is the minimized largest sum.

---

## Complexity Analysis ⏳

- **Time Complexity**:

  - `O(N log S)`, where `N` is the number of elements in `nums` and `S` is the sum of the array.
  - We perform a binary search over the sum (`log S`), and for each candidate value, we iterate through the array (`N`).

- **Space Complexity**:

  - `O(1)`, excluding the input array `nums`.

---

### Summary 📦

By using a binary search and greedy approach, we were able to find the minimum largest sum of any subarray when splitting the array into `k` parts. This solution is efficient and handles large arrays and sums effectively. 🔍

---

# 📚 **Smallest Divisor Problem**

This problem is about finding the smallest divisor such that the sum of the divisions of all elements in an array is less than or equal to a given `threshold`. Each division is rounded up to the nearest integer greater than or equal to the result.

---

## Problem Statement 🧩

Given an array of integers `nums` and an integer `threshold`, you are tasked with choosing a positive integer divisor and dividing all elements in the array by this divisor. The sum of the results (each result rounded up) must be less than or equal to `threshold`.

The goal is to find the smallest such divisor.

---

### Constraints

- `1 <= nums.length <= 5 * 10^4`
- `1 <= nums[i] <= 10^6`
- `nums.length <= threshold <= 10^6`

---

## Example Scenarios

### Example 1

```text
Input: nums = [1, 2, 5, 9], threshold = 6
Output: 5

Explanation:
- If the divisor is 1, the sum is 17 (1+2+5+9), which exceeds the threshold.
- If the divisor is 4, the sum is 7 (1+1+2+3).
- If the divisor is 5, the sum is 5 (1+1+1+2), which satisfies the condition (<= 6).
```

---

### Example 2

```text
Input: nums = [44, 22, 33, 11, 1], threshold = 5
Output: 44

Explanation:
- Dividing by the smallest possible divisors leads to sums greater than the threshold, so the smallest divisor satisfying the condition is 44.
```

---

## Approach 🚀

To solve this problem efficiently, we can utilize **binary search** to find the smallest divisor that results in a sum that meets the threshold. Here's the reasoning:

1. **Binary Search Range**:

   - The smallest possible divisor is `1`, which will give the largest sum.
   - The largest possible divisor is `max(nums)`, which gives the smallest sum.

2. **Check Function**:

   - For a given divisor `m`, divide all the elements of `nums` by `m`, round up, and sum the results. If this sum is less than or equal to the `threshold`, then this divisor is valid.

3. **Binary Search**:

   - Using binary search, we narrow down the possible divisors by testing whether the sum with the current divisor is less than or equal to the `threshold`.

---

## Solution Code 💻

```cpp
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long ans = *max_element(begin(nums), end(nums));  // Max element is the largest possible divisor
        long left = 1LL;  // Smallest possible divisor
        long right = ans;  // Largest possible divisor

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sum = 0LL;

            for (auto num : nums) {
                sum += (num + mid - 1) / mid;  // Calculate sum by rounding up the division
            }

            if (sum <= threshold) {
                ans = mid;
                right = mid - 1;  // Try smaller divisors
            } else {
                left = mid + 1;  // Try larger divisors
            }
        }
        return ans;
    }
};
```

---

### Code Explanation 🧑‍💻

1. **Initialization**:

   - `ans`: This stores the result of the smallest divisor. Initially set to the maximum element of `nums`, which is the largest divisor possible.
   - `left`: The smallest possible divisor is `1`.
   - `right`: The largest possible divisor is the maximum element in `nums`.

2. **Binary Search**:

   - Perform binary search on the range `[left, right]` to find the smallest divisor that satisfies the condition.
   - At each step, calculate `mid` as the potential divisor.

3. **Sum Calculation**:

   - For the current divisor `mid`, iterate through the elements of `nums` and sum the results of `ceil(nums[i] / mid)`. This is efficiently computed as `(nums[i] + mid - 1) / mid`, which gives the same result as `ceil(nums[i] / mid)`.

4. **Binary Search Logic**:

   - If the sum of the divisions is less than or equal to `threshold`, this means `mid` is a valid divisor, so try smaller divisors (`right = mid - 1`).
   - If the sum exceeds the threshold, the divisor is too small, so we search for a larger divisor (`left = mid + 1`).

5. **Return**:

   - After binary search completes, `ans` will contain the smallest divisor that satisfies the condition.

---

## Complexity Analysis ⏳

- **Time Complexity**:

  - The binary search runs in `O(log(max(nums)))`, where `max(nums)` is the largest number in the array.
  - For each binary search iteration, we compute the sum by iterating over `nums`, which takes `O(N)` time, where `N` is the length of `nums`.
  - Thus, the overall time complexity is `O(N log(max(nums)))`.

- **Space Complexity**:

  - `O(1)`, excluding the input array `nums`, as we are only using a few extra variables.

---

## Summary

This solution efficiently finds the smallest divisor using binary search and rounding logic, ensuring that the sum of divisions does not exceed the given threshold. By narrowing the divisor range and testing with each midpoint, we can quickly pinpoint the smallest divisor that meets the requirements. 🎯
