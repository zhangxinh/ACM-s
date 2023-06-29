## C

### 题意

给你n，m，(4<=n,m<=1000)，要求你构造一个n行m列的矩阵，使得矩阵中任意元素与其相邻的元素的差不能为质数。

### 题解

从1到m的中只需要保证连续即可它们的差值为1，这样每一整行的策略便可以确定了。

这样每一行上下的相邻差为m的倍数

设置为:

((n+1)/2)+1

1

((n+1)/2)+2

2

...

以此类推。

### 代码

```c++
#include<bits/stdc++.h>
#include<numeric>

using namespace std;
//template<typename typC,typename typD> bool cmin(typC &x,const typD &y) { if (y<x) { x=y; return 1; } return 0; }
//template<typename typC,typename typD> bool cmax(typC &x,const typD &y) { if (x<y) { x=y; return 1; } return 0; }
#define ll long long
#define pb emplace_back
#define fs first
#define sc second
#define pi pair<ll,ll>
#define mpi make_pair
#define re(a) {cout<<a<<endl;return;}
#define all(v) v.begin(),v.end()
//#define all(v, n) v.begin()+1,v.begin()+n+1
#define fr(i, a, n)  for(int i=a;i<=n;i++)
const int N = 1e3 + 7;
const ll inf = 1e12;
const int mod = 998244353;
//#define cin fin
//ifstream fin("in.txt",ios::in);
//#define  cout fout
//ofstream fout("13.ans",ios::out);
//function<void(int,int)>dfs=[&](int x,int y)->void{};
int a[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i % 2 == 1) {
                cout << (i  / 2 ) * m + j << " ";
            } else {
                cout << (i / 2  + n / 2) * m + j << " ";
            }
        }
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;//处理多组样例T
    while (_--) solve();
}
```

## D

### 题意

给你一个长度为n的括号序，q次询问。

我们从括号序的最左边出发，每次可以选择向左或者向右走，走到那一位便将这一位添加到序列最后一位，最终要求从最右边退出，问能否使得这个序列为合法序列。

q次询问每次会将第i位上的括号变反。

每次询问都会永久改变括号序。

### 解法

