#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
long long pwr(long long u,int n){
	if(n == 0) return 1LL;
	if(n%2) return ((u)*pwr(u,n-1))%mod;
	long long ans = pwr(u,n/2);
	return (ans*ans)%mod;
}
int main(){
	int tc;cin>>tc;
	while(tc--){
		int n,k;cin>>n>>k;n*=n;
		if(k==1) {
		    long long ans = pwr(2,mod-2);
		    ans = (ans*n)%mod;
		    ans = (ans*(n+1))%mod;
		    cout<<(ans+2*mod)%mod<<endl;
		    continue;
		}
		long long ans = (pwr(k-1,mod-3))%mod;
		ans = (ans*k)%mod;cerr<<ans<<endl;
		ans = (ans * ((n*pwr(k,n+1))%mod-((n+1)*pwr(k,n))%mod +1LL)%mod)%mod;
		cout<<(ans+2*mod)%mod<<endl;
	}
}