### 字符串hash

```c++
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 1e6 + 7;
ull ha[N], fac[N];
ull seed = 201326611;   //233 50331653
ull getStr(int l, int r){
    return ha[r] - ha[l - 1] * fac[r - l + 1];
}
int main(){
    // 预处理
    fac[0] = 1;
    for(int i = 1; i < N; i++)  fac[i] = fac[i - 1] * seed;
    string s;   cin >> s;
    int sz = s.size();
    s = " " + s;
    ha[1] = s[1];
    for(int i = 2; i <= sz; i++)    ha[i] = ha[i - 1] * seed + s[i];

}
```

