#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
string a,b,u,v;

int sa(){
	char c = a[1];
	int ans = 0;
	int i = 1;
	
	while(i <= n){
		if(v[i] == '0'){
			if(b[i] == c) ans++;
			i++;
		}
		else{
			int j = i;
			while(j <= n && v[j] == '1') j++;
			for(int k=i;k<j;k++){
				if(b[k] == c) ans++;
			}
			i = j;
		}
	}
	return ans;
}

int sb(){
	int ans = 0;
	int i = 1;
	
	while(i <= n){
		if(u[i] == '0'){
			if(a[i] == b[i]) ans++;
			i++;
		}
		else{
			int j = i;
			int p0 = 0,p1 = 0;
			int q0 = 0,q1 = 0;
			
			while(j <= n && u[j] == '1'){
				if(a[j] == '0') p0++; 
				else p1++;
				
				if(b[j] == '0') q0++; 
				else q1++;
				
				j++;
			}
			ans += min(p0,q0) + min(p1,q1);
			i = j;
		}
	}
	return ans;
}

bool check(string s,string t,int L){
	int i = 1;
	while(i <= n){
		if(t[i] == '0'){ 
			i++; 
			continue; 
		}
		
		int j = i;
		while(j <= n && t[j] == '1') j++;
		
		if(j - i > L) return false;
		
		i = j;
	}
	return true;
}

vector<string> get(string s,string t){
	vector<string> r;
	r.push_back(s);
	int i = 1;
	
	while(i <= n){
		if(t[i] == '0'){ 
			i++; 
			continue; 
		
		}
		int j = i;
		while(j <= n && t[j] == '1') j++;
		
		vector<string> nx;
		string g = s.substr(i,j-i);
		
		sort(g.begin(), g.end());
		
		do{
			for(int x=0;x<r.size();x++){
				string c = r[x];
				for(int k=0;k<g.size();k++){
					c[i + k] = g[k];
				}
				nx.push_back(c);
			}
		}while(next_permutation(g.begin(),g.end()));
		
		r = nx;
		i = j;
	}
	
	return r;
}

int bfs(){
	auto A = get(a,u);
	auto B = get(b,v);
	int ans = 0;
	
	for(int x=0;x<A.size();x++){
		for(int y=0;y<B.size();y++){
			int c = 0;
			for(int k=1;k<=n;k++){
				if(A[x][k] == B[y][k]) c++;
			}
			ans = max(ans,c);
		}
	}
	return ans;
}

bool is(string s){
	for(int i=1;i<=n;i++){
		if(s[i] != s[1]) return false;
	}
	return true;
}

int main(){
	freopen("edit.in","r",stdin);
	freopen("edit.out","w",stdout);
	
	int T;
	cin >> T;
	
	while(T--){
		cin >> n;
		cin >> a >> b >> u >> v;
		
		a = " " + a;
		b = " " + b;
		u = " " + u;
		v = " " + v;
		
		int ans = 0;
		
		if(is(a)) ans = sa();
		else if(u == v) ans = sb();
		else{
			if(check(a,u,8) && check(b,v,8)) ans = bfs();
			else ans = 0;
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
