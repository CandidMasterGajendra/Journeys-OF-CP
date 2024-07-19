#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int X = 1e7;
const int N = 1000;
const int M = 1e9 + 7;
int n, x, dp[X];
int c[N];

// state -> dp[i] = no of ways of make sum of i with avail coins
// transition -> dp(i) = f(i - 2) + f(i - 3) + f(i - 5)
// base case -> dp(0) = 1
// final subproblem -> dp[x]

int solve(int i){
	if(i == 0) return 1;
	if(dp[i] != 0) return dp[i];

	for(int j = 0; j < n; j++){
		dp[i] += (((i - c[j] >= 0) ? solve(i - c[j]) : 0)) % M;
	}

    return dp[i] % M;
}

signed main(){

	cin>>n>>x;
	for(int i = 0;i < n; i++) cin>>c[i];
	for(int i = 0; i < n; i++) c[i] %= M;

	memset(dp, 0, sizeof(dp));

    cout<<solve(x)<<" ";

}