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

## G

### 题意

给你一个大小未知的序列，他们排列成一个环，在这个环上有一个指针，可以告诉你指针指的地方的值，刚开始指针指在环上随机一个地方。

你有k次机会向左或向右旋转任意格数，让你在k次机会中求出环的大小n,(1<=n<=1000000)

easy version	k = 2000；

hard version 	k = 1000；

### 解法

easy version:

先从当前这个点开始求出连续1000个的长度，再每次1000个大小的向右跳，直到遇到了那连续长度中的数字为止。

hard version：

在序列中随机选100个数字，找到其中的最大值M，这个M会与N十分接近，然后向右转M个，那指针与原来的差距就是M-N，一个非常小的数，再用上面的方法，例如去300长度，跳600次300长度确定N。

### TOTAL

这个取随机的方法真是一点想不到。