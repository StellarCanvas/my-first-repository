#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

int n,m;
string s[N];
char maxn[N];
char minn[N];

int main(){
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s[i];
		
		s[i] = " " + s[i];
		
		char minV = 'z';
		char maxV = 'a';
		for(int j=1;j<=m;j++){
			minV = min(minV,s[i][j]);
			maxV = max(maxV,s[i][j]);
		}
		
		maxn[i] = maxV;
		minn[i] = minV;
	}
	
	for(int i=1;i<=n;i++){
		bool flag = true;
		
		for(int j=1;j<=n;j++){
			if(j == i) continue;
			
			if(maxn[j] <= minn[i]){
				flag = false;
				break;
			}
		}
		
		if(flag) cout << 1;
		else cout << 0;
	}
		
	return 0;
} 
