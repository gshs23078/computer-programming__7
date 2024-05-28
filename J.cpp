#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int w, h, g1, g2, s1, s2;
int ans=0;
int dx[2][3]={{0, 1, 1}, {-1, 0, 1}};
int dy[2][3]={{1, 1, 0}, {1, 1, 0}};

bool inrange(int x, int y){
	if(y<=0 || y>h) return false;
	if(x<=0) return false;
	if(y&1) return x<=w;
	else return x<w;
}

void f(int x, int y){
	if(x==g1 && y==g2){
		ans++;
		return;
	}
	if(y>g2) return;
	fori(k, 0, 3){
		int nx=x+dx[y&1][k];
		int ny=y+dy[y&1][k];
		if(!inrange(nx, ny)) continue;
		f(nx, ny);
	}
	return;
}

signed main(){
	cin >> w >> h >> s1 >> s2 >> g1 >> g2;
	f(s1, s2);
	cout << ans;
}
