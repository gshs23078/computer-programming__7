#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

const int SIZE=1001;
int n;
bool chk1[SIZE][SIZE];
bool chk2[SIZE][SIZE];
char a[SIZE][SIZE];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
int t1, t2, g1, g2;

bool inrange(int x, int y){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=n) return false;
	return true;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	queue<pair<int, int> > qu;
	fori(i, 0, n) fori(j, 0, n){
		cin >> a[i][j];
		if(a[i][j]=='S'){
			chk1[i][j]=true;
			qu.push(make_pair(i*n+j, 0));
		}
		if(a[i][j]=='T'){
			t1=i;
			t2=j;
		}
		if(a[i][j]=='G'){
			g1=i;
			g2=j;
		}
	}
	while(qu.size()){
		int x=qu.front().first/n;
		int y=qu.front().first%n;
		int move=qu.front().second;
		qu.pop();
		if(x==t1 && y==t2){
			while(qu.size()) qu.pop();
			chk2[x][y]=true;
			qu.push(make_pair(x*n+y, move));
			break;
		}
		fori(k, 0, 4){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(!inrange(nx, ny)) continue;
			if(chk1[nx][ny]) continue;
			if(a[nx][ny]=='#') continue;
			chk1[nx][ny]=true;
			qu.push(make_pair(nx*n+ny, move+1));
		}
	}
	while(qu.size()){
		int x=qu.front().first/n;
		int y=qu.front().first%n;
		int move=qu.front().second;
		qu.pop();
		if(x==g1 && y==g2){
			cout << move;
			break;
		}
		fori(k, 0, 4){
			int nx=x+dx[k];
			int ny=y+dy[k];
			if(!inrange(nx, ny)) continue;
			if(chk2[nx][ny]) continue;
			if(a[nx][ny]=='#') continue;
			chk2[nx][ny]=true;
			qu.push(make_pair(nx*n+ny, move+1));
		}
	}
}
