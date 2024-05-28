#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
#define int long long
#define endl '\n'
#define fori(i, a, b) for(int i=a; i<b; i++)
#define ford(i, a, b) for(int i=a;i>=b; i--)

const int mod=998244353;
const int SIZE=300001;
int n;
bool chk[SIZE];
vector<int> child[SIZE];

int fact(int num){
	int prod=1;
	fori(i, 1, num+1)
		prod=prod*i%mod;
	return prod;
}

signed main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	fori(i, 1, n){
		int aa, bb;
		cin >> aa >> bb;
		child[aa].push_back(bb);
		child[bb].push_back(aa);
	}
	chk[1]=true;
	queue<int> qu;
	qu.push(1);
	int ans=1;
	while(qu.size()){
		int x=qu.front();
		int l=child[x].size();
		int c=0;
		qu.pop();
		fori(i, 0, l){
			if(chk[child[x][i]]) continue;
			chk[child[x][i]]=true;
			c++;
			qu.push(child[x][i]);
		}
		ans=ans*fact(c)%mod;
	}
	cout << ans;
}
