#include <iostream>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

// fresh air: 2
// cheese: 1
// inside: 0

int n, m;
int cheese[101][101];
int  chese[101][101];
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};

void air(int idx){
	int x=idx/m;
	int y=idx%m;
	int nx, ny;
	fori(i, 0, 4){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=m)
			continue;
		if(chese[nx][ny]) continue;
		chese[nx][ny]=2;
		air(nx*m+ny);
	}
	return;
}

void twin(){
	fori(i, 0, n) fori(j, 0, m)
		chese[i][j]=cheese[i][j];
	return;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int time=0;
	cin >> n >> m;
	fori(i, 0, n) fori(j, 0, m)
		cin >> cheese[i][j];
	while(1){
		int chk=0;
		fori(i, 0, n) fori(j, 0, m)
			chk+=cheese[i][j];
		if(!chk) break;
		time++;
		twin();
		chese[0][0]=2;
		air(0);
		fori(i, 0, n) fori(j, 0, m){
			if(chese[i][j]!=1) continue;
			chk=0;
			fori(k, 0, 4)
				if(chese[i+dx[k]][j+dy[k]]==2)
					chk++;
			if(chk>1) cheese[i][j]=0;
		}
	}
	cout << time;
}
