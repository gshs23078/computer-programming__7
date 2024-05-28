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
int v, e;
vector<int> g[2001];
bool chk[2001];

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> v >> e;
	fori(i, 0, e){
		int aa, bb;
		cin >> aa >> bb;
		g[aa].push_back(bb);
		g[bb].push_back(aa);
	}
	queue<int> qu;
	chk[1]=true;
	qu.push(1);
	while(qu.size()){
		int node=qu.front();
		qu.pop();
		cout << node << ' ';
		int l=g[node].size();
		fori(i, 0, l){
			if(!chk[g[node][i]]){
				qu.push(g[node][i]);
				chk[g[node][i]]=true;
			}
		}
	}
}
