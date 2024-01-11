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
struct TreeNode{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):data(x),left(nullptr),right(nullptr){};
};
signed main(){
TreeNode *root=new TreeNode(10);
root->left=new TreeNode(20);
root->right=new TreeNode(45);
cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<"\n";
return 0;
}