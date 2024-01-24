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
signed main()
{
    int a = 5;                // 101
    int b = 7;                // 111
    int c = 16;               // 10000
    int d = 17;               // 10001
    cout << (a & b) << endl;  // 101
    cout << (a | b) << endl;  // 111
    cout << (a ^ b) << endl;  // 010
    cout << (c ^ d) << endl;  // 1
    cout << (~a) << endl;     // 010
    cout << (a << 1) << endl; // 1010 // left shift // multiply by 2
    cout << (a << 2) << endl; // 10100 // left shift // multiply by 2
    cout << (a >> 1) << endl; // 10 // right shift // divide by 2
    cout << (a >> 2) << endl; // 1 // right shift // divide by 2
    cout << (a << 3) << endl; // 101000 // left shift // multiply by 2
    cout << (a >> 3) << endl; // 0 // right shift // divide by 2
    // ith bit checking
    int i = 2;
    int mask = 1 << i;
    if (a & mask)
    {
        cout << "1 is bit" << endl;
    }
    else
    {
        cout << "0 is bit" << endl;
    }
    // set ith bit
    int j = 3;
    int mask1 = 1 << j;
    int ans = a | mask1;
    cout << ans << endl;
    // clear ith bit
    int k = 2;
    int mask2 = ~(1 << k);
    int ans1 = a & mask2;
    cout << ans1 << endl;
    // update ith bit
    int l = 2;
    int mask3 = 1 << l;
    int ans2 = a | mask3;
    cout << ans2 << endl;
    int m = 2;
    int mask4 = ~(1 << m);
    int ans3 = a & mask4;
    cout << ans3 << endl;
    // clear last i bits
    int n = 2;
    int mask5 = (-1 << n);
    int ans4 = a & mask5;
    cout << ans4 << endl;
    // clear range of bits
    int o = 2;
    int p = 4;
    int mask6 = (-1 << o);
    int mask7 = (1 << p) - 1;
    int mask8 = mask6 | mask7;
    int ans5 = a & mask8;
    cout << ans5 << endl;
    // even odd
    int q = 5;
    if (q & 1)
    {
        cout << "odd" << endl;
    }
    else
    {
        cout << "even" << endl;
    }
    // power of 2
    int r = 16;
    if (r & (r - 1))
    {
        cout << "not power of 2" << endl;
    }
    else
    {
        cout << "power of 2" << endl;
    }
    // count set bits
    int s = 5;
    int count = 0;
    while (s)
    {
        s = s & (s - 1);
        count++;
    }
    cout << count << endl;
    // or we can use inbuilt function
    int t = 5;
    cout << __builtin_popcount(t) << endl;
   // power of 4
    int u = 16;
    if (u & (u - 1))
    {
        cout << "not power of 4" << endl;
    }
    else
    {
        int count = 0;
        while (u)
        {
            u = u >> 1;
            count++;
        }
        if (count % 2 == 0)
        {
            cout << "power of 4" << endl;
        }
        else
        {
            cout << "not power of 4" << endl;
        }
    }
    // using hexa decimal
    int v = 16;
    bool powerOf4 = (v > 0) && ((v & (v - 1)) == 0) && ((v & 0x55555555) != 0);

    if (powerOf4) {
        cout << "Power of 4" << endl;
    } else {
        cout << "Not Power of 4" << endl;
    }
    // swap two numbers
    int w = 5;
    int x = 7;
    w = w ^ x;
    x = w ^ x;
    w = w ^ x;
    cout << w << " " << x << endl;
    //power of 8
    int y = 64;
    bool powerOf8 = !(y& (y-1)) && (n%7==1);
    if (powerOf8) {
        cout << "Power of 8" << endl;
    } else {
        cout << "Not Power of 8" << endl;
    }

    return 0;
}