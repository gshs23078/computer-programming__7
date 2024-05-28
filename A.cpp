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
int v, e, g[101][101];
bool chk[101];
void dfs(int node){
	chk[node]=1;
	cout << node << ' ';
	fori(i, 1, v+1){
		if(!g[node][i]) continue;
		if(chk[i]) continue;
		dfs(i);
	}
	return;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> v >> e;
	fori(i, 0, e){
		int aa, bb;
		cin >> aa >> bb;
		g[aa][bb]++;
		g[bb][aa]++;
	}
	dfs(1);
}
