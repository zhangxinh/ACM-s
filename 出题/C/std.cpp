#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
vector<int>v[N];
int n, m;
int a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= n) continue;
        int l = a[i] >= 0 ? 1 : (-a[i] + i - 1) / i;
        int r = min(m, (n - a[i]) / i);
        for (int j = l; j <= r; j++) v[j].push_back(a[i] + j * i);
    }
    for (int i = 1; i <= m; i++) {
        int sz = v[i].size();
        vector<bool> st(sz + 1);
        for (auto j: v[i]) {
            if (j <= sz) st[j] = 1;
        }
        int res = 0;
        while (st[res]) res++;
        cout << res << endl;
    }
    return 0;
}