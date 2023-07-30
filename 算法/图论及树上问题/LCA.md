### LCA最近公共祖先

两个节点的最近公共祖先，即两个节点的公共祖先中离根最远的那一个。

#### 倍增

维护各个点的$2^{i}$个祖先，倍增跳转求值。

```c++
/*
input
5 5 4	//5个点，5次LCA询问，4为树的根节点。
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5
*/

vc<int> depth(N + 2),edge[N + 2];
vc<vc<int>>fa(N + 2,vc(22 , 0));
void solve() {
    int n, q ,root;  cin >> n >> q >> root;
    int u, v;
    fr(i, 2, n){
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    vector<int>lg(n);
    fr(i, 1, n) lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    function<void(int, int)>dfs = [&](int now,int fath)->void{
        fa[now][0] = fath;//第一个父亲节点是自己
        depth[now] = depth[fath] + 1;
        fr(i, 1, lg[depth[now]])    fa[now][i] = fa[fa[now][i - 1]][i - 1];
        for(auto i:edge[now])   if(i != fath) dfs(i, now);
    };
    function<int(int, int)>lca = [&](int x,int y)->int{
        if(depth[x] < depth[y]) swap(x, y);
        while(depth[x] > depth[y])  x = fa[x][lg[depth[x] - depth[y]] - 1];
        if(x == y)  return x;
        for(int k = lg[depth[x]] - 1;k >= 0; k--)
            if(fa[x][k] != fa[y][k])    x = fa[x][k], y = fa[y][k];
        return fa[x][0];
    };
    dfs(root, 0);
    rep(q){
        cin >> u >> v;
        cout << lca(u, v) <<"\n";
    }
}
```

#### 树剖写

1.判断两点是否在同一条链上，是则能直接得到答案

2.否则，令深度较大的点变成它重链端的父节点，得到新的两点，重复以上步骤。

树剖步骤

定义siz[x] 为以x为根结点的子树节点个数

对x的每个子节点，找到其最大的节点y，使得siz[y] >= siz[z]。

```c++
vc<int>dep(N + 2),edge[N + 2],fa(N + 2),son(N + 2),siz(N + 2), top(N + 2);
//son存最大的儿子子树
void solve() {
    int n, q ,root;  cin >> n >> q >> root;
    int u, v;
    fr(i, 2, n){
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    function<void(int)>dfs1 = [&](int x)->void{
        siz[x] = 1;
        dep[x] = dep[fa[x]] + 1;
        for(auto i : edge[x]){
            if(i == fa[x]) continue;
            fa[i] = x;
            dfs1(i);
            siz[x] += siz[i];
            if(!son[x] || siz[son[x]] < siz[i]) son[x] = i;
        }
    };
    function<void(int, int)>dfs2 = [&](int x, int tv)->void{
        top[x] = tv;
        if(son[x])  dfs2(son[x], tv);
        for(auto i:edge[x]){
            if(i == fa[x] || i == son[x]) continue;
            dfs2(i,i);
        }
    };
    dfs1(root);
    dfs2(root, root);
    int ans;
    rep(q){
        cin >> u >> v;
        while(top[u] != top[v])
            dep[top[u]] >= dep[top[v]] ? u = fa[top[u]] : v = fa[top[v]];
        ans = (dep[u] < dep[v] )? u : v;
        cout<<ans <<"\n";
    }
}
```

#### 欧拉序列转换为RMQ

