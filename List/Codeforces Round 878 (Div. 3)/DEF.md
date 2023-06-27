## D

### 题意

给你一个数组，要求你构造三个数字a,b,c,使得min(min(|a[i]-a|,|a[i]-b|,|a[i]-c|))

### 解法

二分答案，贪心模拟。

### 代码

```c++
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb emplace_back
const ll inf = 1e10;
const int mod = 998244353;
const int N = 1e6 + 1e5;
const ll MAXN = 2e5 + 10;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 3);
    ll l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    a[n + 1] = inf;
    auto judge = [&](ll x) {
        ll mi = a[1] + 2 * x, mx = a[n] - 2 * x;
        mi = *upper_bound(a.begin() + 1, a.begin() + n + 2, mi);
        if (mi >= mx) return true;
        mi += 2 * x;
        mi = *upper_bound(a.begin() + 1, a.begin() + n + 2, mi);
        if (mi >= mx) return true;
        else return false;
    };
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (judge(mid)) r = mid - 1;
        else l = mid + 1;
        //cout<<mid<<" "<<l<<" "<<r<<"\n";
    }
    cout << l << "\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;//处理多组样例T
    while (_--) solve();
}
```

