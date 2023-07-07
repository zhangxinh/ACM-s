#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) continue;
		static int cnt[2010][26]; memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < n; j++) {
			cnt[j % i][s[j] - 'a']++;
		}
		int need = 0;
		for (int j = 0; j < i; j++) {
			int sum = 0, maxj = 0;
			for (int k = 0; k < 26; k++) {
				sum += cnt[j][k], maxj = max(maxj, cnt[j][k]);
			}
			need += sum - maxj;
		}
		if (need <= k) ans = min(ans, i);
	}
	cout << ans << endl;
	return 0;
}