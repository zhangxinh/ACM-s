#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define mod 998244353
#define ll long long
int n,a[N],cnt[N];
ll ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=0;j<30;j++)
			if ((a[i]>>j)&1)cnt[j]++;
	}
	for(int i=1;i<=n;i++)ans+=a[i];
	for(int i=1;i<=n;i++){
		ll s=0;
		for(int j=0;j<30;j++)
			if ((a[i]>>j)&1)s+=(ll)(n-cnt[j])*(1<<j);
			else s+=(ll)cnt[j]*(1<<j);
		ans=max(ans,s);
	}
	printf("%lld\n",ans);
	return 0;
}