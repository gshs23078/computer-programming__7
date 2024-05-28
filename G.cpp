#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

int w, h;
int farm[1001][81];
int dx[4]={0, 0, -1, 1};
int dy[4]={-1, 1, 0, 0};
int Max=0, area=0;

void dfs(int idx){
	int x=idx/w;
	int y=idx%w;
	farm[x][y]=0;
	area++;
	fori(k, 0, 4){
		int nx=x+dx[k], ny=y+dy[k];
		if(nx<0 || nx>=h || ny<0 || ny>=w)
			continue;
		if(farm[nx][ny]) dfs(nx*w+ny);
	}
	return;
}

signed main(){
	cin >> w >> h;
	string str;
	fori(i, 0, h){
		cin >> str;
		fori(j, 0, w){
			if(str[j]=='*') farm[i][j]=1;
			else farm[i][j]=0;
		}
	}
	fori(i, 0, h) fori(j, 0, w){
		if(farm[i][j]){
			if(Max<area) Max=area;
			area=0;
			dfs(i*w+j);
		}
	}
	cout << Max;
}
