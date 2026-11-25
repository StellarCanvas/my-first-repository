#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int LOG = 15;

int n,q;
vector<int> g[N];
int depth[N];
int up[N][LOG];
int dfn[N];
int rdfn[N];
int timer = 0;

void dfs(int u,int f){
	up[u][0] = f;
	depth[u] = depth[f] + 1;
	dfn[u] = ++timer;
	rdfn[timer] = u;
	
	for(int i=1;i<LOG;i++){
		up[u][i] = up[up[u][i-1]][i-1];
	}
	
	for(int v : g[u]){
		if(v == f) continue;
		
		dfs(v,u);
	}
}

int lca(int u,int v){
	if(depth[u] < depth[v]) swap(u,v);
	
	int diff = depth[u] - depth[v];
	
	for(int i=0;i<LOG;i++){
		if(diff >> i & 1) u = up[u][i];
	}
	
	if(u == v) return u;
	
	for(int i=LOG-1;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	
	return up[u][0];
}

int bin(int l,int r){
	int minn = 1e9;
	int maxn = -1e9;
	int u = 0,v = 0;
	
	for(int i=l;i<=r;i++){
		if(dfn[i] < minn){
			minn = dfn[i];
			u = i; 
		}
		
		if(dfn[i] > maxn){ 
			maxn = dfn[i]; 
			v = i; 
		}
	}
	
	return lca(u,v);
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	cin >> n;
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1,0);
	
	cin >> q;
	while(q--){
		int l,r,k;
		cin >> l >> r >> k;
		int ans = 0;
		for(int i=l;i<=r;i++){
			for(int j=i+k-1;j<=r;j++){
				int w = bin(i,j);
				ans = max(ans,depth[w]);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}
