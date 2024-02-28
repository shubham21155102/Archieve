#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printLIS(vector<int>& arr, vector<vector<int > >& allLIS, vector<int>& currentLIS, int currentIndex, int lastIndex) {
    if (currentIndex == -1) {
        for (int i = lastIndex; i >= 0; i--) {
            cout << currentLIS[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = currentIndex; i >= 0; i--) {
        if (arr[currentIndex] > arr[i] && allLIS[currentIndex].size() == allLIS[i].size() + 1) {
            currentLIS.push_back(arr[currentIndex]);
            printLIS(arr, allLIS, currentLIS, i, lastIndex);
            currentLIS.pop_back();
        }
    }
}

int maxSumLis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<vector<int > > allLIS(n);
    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        allLIS[i].push_back(arr[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                allLIS[i] = allLIS[j];
                allLIS[i].push_back(arr[i]);
                maxLen = max(maxLen, dp[i]);
            }
        }
    }

    vector<int> currentLIS;
    for (int i = n - 1; i >= 0; i--) {
        if (dp[i] == maxLen) {
            printLIS(arr, allLIS, currentLIS, i, i);
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr;
    //  {10, 22, 9, 33, 21, 50, 41, 60, 80};
    arr.push_back(10);
    arr.push_back(22);
    arr.push_back(9);
    arr.push_back(33);
    arr.push_back(21);
    arr.push_back(50);
    arr.push_back(41);
    arr.push_back(60);
    arr.push_back(80);
    
    cout << "Length of LIS: " << maxSumLis(arr) << endl;

    return 0;
}
