#### ST表

```c++
const int N = 1e5 + 10, M = 20;
int st[N][M];
int n, m;

int query(int l, int r)
{
	int x = log2(r - l + 1);
	return max(st[l][x], st[r - (1 << x) + 1][x]);
}

void solve()
{
	cin >> n >> m;
	fer(i, 1, n)cin >> st[i][0];
	fer(j, 1, 18)
	{
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
		{
			st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
		}
	}
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}
```

