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

int n;
string x[1001];
string gshs="gshs";
int dx[8]={-1, -1, -1, 1, 1, 1, 0, 0};
int dy[8]={-1, 0, 1, -1, 0, 1, -1, 1};

bool inrange(int x, int y){
	if(x<0 || x>=n) return false;
	if(y<0 || y>=n) return false;
	return true;
}

signed main(){
	int ans=0;
	cin >> n;
	fori(i, 0, n) cin >> x[i];
	fori(i, 0, n) fori(j, 0, n){
		if(x[i][j]!='g') continue;
		fori(k, 0, 8){
			bool chk=true;
			fori(l, 0, 4){
				if(!inrange(i+dx[k]*l, j+dy[k]*l)){
					chk=false;
					break;
				}
				if(gshs[l]!=x[i+dx[k]*l][j+dy[k]*l]){
					chk=false;
					break;
				}
			}
			if(chk) ans++;
		}
	}
	cout << ans;
}
