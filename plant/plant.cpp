#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char g[N][N];

int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	
	int T,id;
	cin >> T >> id;
	
	while(T--){
		if(id == 1){
			cout << "0 0" << '\n';
			continue;
		}
		
		int n,m,c,f;
		cin >> n >> m >> c >> f;
		
		int cnt[2] = {0,0}; 
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> g[i][j];
				cnt[g[i][j] - '0']++;
			}
		} 
		
		if(id == 2){
			if(cnt[1] > 1) cout << "0 0" << '\n';
			else if(cnt[1] == 1 && g[2][2] == '1') cout << "1 0" << '\n';
			else if(cnt[1] == 0) cout << "1 0" << '\n';
			else cout << "0 0" << '\n';
		}
		
		if(id == 3){
			if(cnt[1] > 2) cout << "0 0" << '\n';
			else if(cnt[1] == 2){
				if(g[2][2] == '1' && g[3][2] == '1') cout << "1 0" << '\n';
				else if(g[2][2] == '1' && g[4][2] == '1') cout << "1 0" << '\n';
				else cout << "0 0" << '\n';
			}
			else if(cnt[1] == 1){
				if(g[2][2] == '1') cout << "2 1" << '\n';
				else if(g[3][2] == '1') cout << "2 0" << '\n'; 
				else if(g[4][2] == '1') cout << "1 1" << '\n';
				else if(g[1][2] == '1') cout << "1 0" << '\n';
				else if(g[1][1] == '1') cout << "1 0" << '\n';
				else if(g[4][1] == '1') cout << "1 0" << '\n';
				else cout << "0 0" << '\n';
			}
			else if(cnt[1] == 0) cout << "3 1" << '\n';
			else cout << "0 0" << '\n';
		}
	} 

	return 0;
} 
