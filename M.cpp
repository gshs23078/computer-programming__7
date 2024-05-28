#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int dx[4]={1, 1, -1, -1};
int dy[4]={1, -1, 1, -1};
int n=8;
int cost[33][33];

bool inrange(int x, int y){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=n) return false;
	return true;
}

void solve(){
	pair<int, int> b;
	vector<pair<int, int> > t;
	int odd=-1;
	vector<int> ans;
	fori(i, 0, 8){
		string str;
		cin >> str;
		fori(j, 0, 8){
			if(str[j]=='B'){
				b=make_pair(i, j);
				if(odd<0) odd=(i+j)%2;
				else if(odd==10000) continue;
				else if(odd!=(i+j)%2){
					cout << -1 << endl;
					odd=10000;
				}
			}
			if(str[j]=='T'){
				t.push_back(make_pair(i, j));
				if(odd<0) odd=(i+j)%2;
				else if(odd==10000) continue;
				else if(odd!=(i+j)%2){
					cout << -1 << endl;
					odd=10000;
				}
			}
		}
	}
	if(odd==10000) return;
	int l=t.size();
	fori(i, 0, l){
		fori(j, i+1, l){
			if(abs(t[i].first-t[j].first)==abs(t[i].second-t[j].second))
				cost[i+1][j+1]=cost[j+1][i+1]=1;
			else cost[i+1][j+1]=cost[j+1][i+1]=2;
		}
		if(abs(t[i].first-b.first)==abs(t[i].second-b.second))
			cost[0][i+1]=cost[i+1][0]=1;
		else cost[0][i+1]=cost[i+1][0]=2;
	}
	ans.push_back(cost[0][1]+cost[1][2]+cost[2][3]);
	ans.push_back(cost[0][1]+cost[1][3]+cost[3][2]);
	ans.push_back(cost[0][2]+cost[2][1]+cost[1][3]);
	ans.push_back(cost[0][2]+cost[2][3]+cost[3][1]);
	ans.push_back(cost[0][3]+cost[3][1]+cost[1][2]);
	ans.push_back(cost[0][3]+cost[3][2]+cost[2][1]);
	sort(ans.begin(), ans.end());
	cout << ans[0] << endl;
	return;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	int tt;
	cin >> tt;
	while(tt--) solve();
}
