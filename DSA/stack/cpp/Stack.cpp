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
// #include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class Stack{
    private:
    int topIndex;
    int capacity;
    int *arr;
    public:
   Stack(int x){
    arr=new int[x];
    this->capacity=x;
    this->topIndex=-1;
   }
  int size(){
    return this->topIndex+1;
   }
   int pop(){
    topIndex--;
    return arr[topIndex];
   }
   void push(int x){
    topIndex++;
    arr[topIndex]=x;
   }
   bool isEmpty(){
    return this->topIndex==-1;
   }
   int peek(){
    return arr[this->topIndex];
   }
};
signed main(){
Stack st=Stack(5);
st.push(6);
cout<<st.peek();
return 0;
}