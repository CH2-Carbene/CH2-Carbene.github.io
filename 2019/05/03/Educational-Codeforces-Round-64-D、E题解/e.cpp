#include <bits/stdc++.h>
using namespace std;
int lft[301000],rgt[301000],loc[301000],a[301000];
int main (/*int argc, char const* argv[]*/){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
		loc[a[i]]=i;
	}
	stack<int>st1,st2;
	for(int i=1;i<=n;++i){
		while(st1.size()&&a[st1.top()]<a[i])st1.pop();
		if(!st1.size())lft[i]=1;
		else lft[i]=st1.top()+1;
		st1.push(i);
	}
	for(int i=n;i;--i){
		while(st2.size()&&a[st2.top()]<a[i])st2.pop();
		if(!st2.size())rgt[i]=n;
		else rgt[i]=st2.top()-1;
		st2.push(i);
	}
	long long ans=0;
	for(int i=1;i<=n;i+=1){
		int l=lft[i],r=rgt[i];
		if(i-l<=r-i){
			for(int j=lft[i];j<i;++j){
				int k=loc[a[i]-a[j]];
				if(k<=r&&k>i)++ans;
			}
		}
		else{
			for(int j=rgt[i];j>i;--j){
				int k=loc[a[i]-a[j]];
				if(k>=l&&k<i)++ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
