# Bit Manipulation

## Check ith Bit

- 1 -> 000....1
- now shfting this to i=3
- 0000...100
- 1<<(i-2)
- let n=2
- 00...0010
- 00...0100
- taking or and clearly getting 0 then not set

```cpp
#include <iostream>
using namespace std;
int main() {
    int n=2;
    int i=3;
    int mask=1<<(i-1);
    if(mask & n) cout<<"Set";
    else cout<<"Not Set";
    return 0;
}
```

## Setting ith bit

- just taken or
- 00...0010
- 00...0100
- so here we can set th ith bit

```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n=9;
    bitset<32>b(9);
    cout<<b<<"\n";
    int i=3;
    int mask=1<<(i-1);
    cout<<(mask | n);
}
```

## Clearing ith bit

- 1 -> 000....1
- now shfting this to i=3
- 0000...100
- 1<<(i-2)
- now taking not of this
- 1111...011
- and taking and with n
- let n=2
- 00...0010
- 00...0100
- taking and and clearly getting 0 then not set

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
int i=1;
int mask=1<<(i-1);
mask=~mask;
int n=81;
cout<<(mask & n)<<"\n";
return 0;
}
```

## Remove last set bit of a number

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
int n=81;
cout<<((n-1)& n)<<"\n";
return 0;
}
```

## Find the position of rightmost setbit

- n&(-n) will give the rightmost set bit
- n=8
- n // 00000000000000000000000000001000
- -n // 11111111111111111111111111111000
- // n&(-n) -> 1000
- // log10(1000) --> 3
- then take log2 of this

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
int n=8;
bitset<32>b1(n);
cout<<b1<<"\n";
bitset<32>b2(-n);
cout<<b2<<"\n";
cout<<(int)log2(n&(-n))+1<<"\n";
return 0;
}
```

## Odd or Even

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
int n=8;
if(n&1) cout<<"Odd\n";
else cout<<"Even\n";
return 0;
}
```

## Power Of Two

- 4 - 100
- 8 - 1000
- 16 - 10000
- 32 - 100000
- 7 - 00000000000000000000000000001000
- 8 & 7 =0
- then power of two

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n = 8;

    bitset<32> b(n-1);
    cout << b << "\n";

    bitset<32> b1(n);
    cout << b1 << "\n";

    cout << (b & b1) << "\n";

    bitset<32> c(0);
    if ((b & b1) == c)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

```

## Power Of Four

```cpp

```
