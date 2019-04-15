#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[402000],b[402000];

int main (/*int argc, char const* argv[]*/){
	std::ios::sync_with_stdio(false);
	int n;cin>>n;
	ll w=0,s=0;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
		s+=a[i];
	}
	int t=0,bd=0;
	for(int i=n;i>=1;--i){
		t+=a[i]/2;
		if(a[i]%2){
			if(!t)++bd;
			else --t;
		}
	}
	cout<<(s-bd)/3<<endl;
	return 0;
}
