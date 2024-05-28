#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int n, m, k;
vector<int> road[11][11];
vector<int> cost;

void f(int now, int visited, int v, bool halved){
	if(now==n){
		if(!halved) return;
		cost.push_back(v);
		return;
	}
	int p=1;
	fori(i, 1, n+1){
		int l=road[now][i].size();
		if(!l) continue;
		if((visited>>i)&1) continue;
		fori(j, 0, l){
			f(i, visited+(p<<i), v+road[now][i][j], halved);
			if(!halved)
				f(i, visited+(p<<i), v+road[now][i][j]/2, true);
		}
	}
	return;
}

signed main(){
	cin >> n >> m >> k;
	fori(i, 0, m){
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		road[aa][bb].push_back(cc);
		if(aa!=bb) road[bb][aa].push_back(cc);
	}
	f(1, 2, 0, 0);
	if(n==1 && cost.empty()) cost.push_back(0);
	if(cost.size()<k) cout << -1;
	else{
		sort(cost.begin(), cost.end());
		cout << cost[k-1];
	}
}
