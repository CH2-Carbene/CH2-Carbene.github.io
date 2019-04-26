#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull s[202000],dta[202000],exadz[202000];
int main (/*int argc, char const* argv[]*/){
	std::ios::sync_with_stdio(false);
	int n;cin>>n;
	for(int i=1;i<=n;i+=1){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	for(int i=2;i<=n;i+=1){
		dta[i-1]=s[i]-s[i-1];
	}
	sort(dta+1,dta+n);
	for(int i=1;i<=n;i+=1){
		exadz[i]=exadz[i-1]+dta[i];
	}
	int q;cin>>q;
	for(int i=1;i<=q;i+=1){
		ull l,r;cin>>l>>r;
		ull d=r-l+1;
		int t=lower_bound(dta+1,dta+n,d)-dta;
		ull ans=(n-t+1)*d;
		cout<<ans+exadz[t-1]<<' ';
	}
	return 0;
}
