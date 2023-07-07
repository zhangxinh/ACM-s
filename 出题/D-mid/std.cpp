#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 1e9;
int tr[5][N];
int p[N];
int res[N];
int n;
int lowbit(int x) {
	return x&-x;
}
int query(int x,int ty) {
	int res=INF;
	while(x) {
		res=min(res,tr[ty][x]);
		x-=lowbit(x);
	}
	return res;
}
void add(int x,int c,int ty) {
	while(x<=n) {
		tr[ty][x]=min(tr[ty][x],c);
		x+=lowbit(x);
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&p[i]);
	memset(tr,0x3f,sizeof tr);
	memset(res,0x3f,sizeof res);
	for(int i=1; i<=n; i++) {
		int ans0=p[i]+i;
		ans0+=query(p[i],0);
		int ans1=i-p[i];
		ans1+=query((n+1-p[i]),1);
		res[i]=min({res[i],ans0,ans1});

		add(p[i],-p[i]-i,0);
		add((n+1-p[i]),p[i]-i,1);
	}
	for(int i=n; i>=1; i--) {
		int ans3=p[i]-i;
		ans3+=query(p[i],2);
		int ans4=-p[i]-i;
		ans4+=query((n+1-p[i]),3);
		res[i]=min({res[i],ans3,ans4});
		add(p[i],-p[i]+i,2);
		add(n+1-p[i],p[i]+i,3);
	}
	for(int i=1; i<=n; i++) printf("%d ",res[i]);
}