#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int h, w;
char field[51][51];

bool isend(){
	fori(i, 0, h) fori(j, 0, w)
		if(field[i][j]!='.') return false;
	return true;
}

bool inrange(int x, int y){
	if(x<0 || x>=h) return false;
	if(y<0 || y>=w) return false;
	return true;
}

signed main(){
	int ans=0;
	cin >> h >> w;
	fori(i, 0, h){
		string str;
		cin >> str;
		fori(j, 0, w){
			field[i][j]=str[j];
		}
	}
	char now=field[0][0];
	while(1){
		if(isend()) break;
		ans++;
		queue<pair<int, int> > qu;
		vector<pair<int, int> > v;
		char now=field[0][0];
		field[0][0]='.';
		qu.push(make_pair(0, 0));
		v.push_back(make_pair(0, 0));
		while(qu.size()){
			int x=qu.front().first;
			int y=qu.front().second;
			qu.pop();
			fori(k, 0, 4){
				if(!inrange(x+dx[k], y+dy[k]))
					continue;
				if(field[x+dx[k]][y+dy[k]]!=now)
					continue;
				qu.push(make_pair(x+dx[k], y+dy[k]));
				v.push_back(make_pair(x+dx[k], y+dy[k]));
				field[x+dx[k]][y+dy[k]]='.';
			}
		}
		if(isend()) break;
		if(now=='F') now='R';
		else now='F';
		int l=v.size();
		fori(i, 0, l){
			field[v[i].first][v[i].second]=now;
		}
	}
	cout << ans;
}
