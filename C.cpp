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

signed main(){
	cin >> v >> e;
	fori(i, 0, e){
		int aa, bb;
		cin >> aa >> bb;
		g[aa][bb]++;
		g[bb][aa]++;
	}
	queue<int> qu;
	qu.push(1);
	chk[1]=true;
	while(qu.size()){
		int node=qu.front();
		qu.pop();
		cout << node << ' ';
		fori(i, 1, v+1){
			if(!g[node][i]) continue;
			if(chk[i]) continue;
			qu.push(i);
			chk[i]=true;
		}
	}
}
