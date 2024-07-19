#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;
// const int N = 1000;
// const int X = 1e7;
int n, x;

// state -> dp[i] = no of ways of make sum of i with avail coins
// transition -> dp(i) = f(i - c[0]) + f(i - c[1]) + f(i - c[2]) + .....
// base case -> dp(0) = 1
// final subproblem -> dp[x]



signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>x;
	vector<int>c(n);
	vector<int>dp(x+1, 0);
	for(int i = 0;i < n; i++) cin>>c[i];
	// for(int i = 0;i < n; i++) c[i] %= M;

	dp[0] = 1;
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
			if(i >= c[j]){
				dp[i] += dp[i - c[j]];
			}
		}
		dp[i] %= M;
	}

    cout<<dp[x]<<" ";

}