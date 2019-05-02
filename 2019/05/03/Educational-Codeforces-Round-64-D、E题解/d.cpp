#include <bits/stdc++.h>
#define maxn 201000
#define maxm 500100
using namespace std;
typedef long long ll;
struct node{
	vector<int>son;
	int fa,sz,v;
	ll f00,f01,f10,f11,ans;
}te[maxn];
struct ljb{
	
	int firstEdge[maxn],used[maxn],m,n;
	node dist[maxn];
	struct edgeNode{
		int x,v,next;
	}edge[maxm*2];
	
	ljb(){
		memset(this,0,sizeof(ljb));
	}
	inline void append(int op,int ed,int va){
		m++;
		edge[m].v=va;
		edge[m].x=ed;
		edge[m].next=firstEdge[op];
		firstEdge[op]=m;
	}
}graph;
void bt(const int&x,const int&fa){
	te[x].fa=fa;te[x].sz=1;
	for(int q=graph.firstEdge[x];q;q=graph.edge[q].next){
		if(graph.edge[q].x!=fa){
			te[x].son.push_back(graph.edge[q].x);
			te[graph.edge[q].x].v=graph.edge[q].v;
			bt(graph.edge[q].x,x);
			te[x].sz+=te[graph.edge[q].x].sz;
		}
	}
}
void dfs(int x){
	
	for(auto&i:te[x].son){
		dfs(i);
		if(te[i].v){
			te[x].f01+=te[i].f00+te[i].f01;
			te[x].f11+=1+te[i].f11;
		}
		else{
			te[x].f10+=te[i].f10+te[i].f11;
			te[x].f00+=1+te[i].f00;
		}
	}
	te[x].ans=te[x].f00*2+te[x].f11*2+te[x].f00*te[x].f11+te[x].f01+te[x].f10;
	for(auto&i:te[x].son){
		if(te[i].v){
			te[x].ans+=(te[i].f11+1)*(te[x].f01-te[i].f01-te[i].f00);
			te[x].ans+=(te[i].f11+1)*(te[x].f11-te[i].f11-1);
		}
		else{
			te[x].ans+=(te[i].f00+1)*(te[x].f10-te[i].f10-te[i].f11);
			te[x].ans+=(te[i].f00+1)*(te[x].f00-te[i].f00-1);
		}
	}
}
int main (/*int argc, char const* argv[]*/){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i+=1){
		int x,y,v;cin>>x>>y>>v;
		graph.append(x,y,v);
		graph.append(y,x,v);
	}
	bt(1,0);
	dfs(1);
	ll ans=0;
	for(int i=1;i<=n;i+=1){
		ans+=te[i].ans;
	}
	cout<<ans<<endl;
	return 0;
}
