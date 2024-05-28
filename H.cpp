#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int n;
int a[102][102];
int dp[102][102];
bool chk[102][102];

int f(int x, int y){
	if(chk[x][y]) return dp[x][y];
	chk[x][y]=true;
	if(x==n-1 && y==n-1)
		return dp[x][y]=a[x][y];
	if(y>=n || x>=n) return dp[x][y]=-1;
	return dp[x][y]=a[x][y]+max(f(x+1, y), f(x, y+1));
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	fori(i, 0, n) fori(j, 0, n)
		cin >> a[i][j];
	
	cout << f(0, 0);
}
