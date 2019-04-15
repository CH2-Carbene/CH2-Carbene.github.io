#include <bits/stdc++.h>
using namespace std;
struct node{
	int fa,sh;//,nleaf;
	vector<int>son;
}st[400000];
int k=1,a[400000];
void dfs(const int&now){
	if(st[now].son.size()){
		int minm=INT_MAX,sum=0;
		for(auto&x:st[now].son){
			dfs(x);
			minm=min(minm,st[x].sh);
			sum+=st[x].sh;
		}
		if(a[now]){
			st[now].sh=minm;
			k+=sum-minm;
		}
		else st[now].sh=sum;
	}
	else{
		st[now].sh=1;
	}
}

int main (/*int argc, char const* argv[]*/){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i+=1){
		cin>>a[i];
	}
	for(int i=2;i<=n;i+=1){
		int f;cin>>f;
		st[i].fa=f;
		st[f].son.push_back(i);
	}
	dfs(1);
	cout<<k<<endl;
	return 0;
}
