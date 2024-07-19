#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6;
const int M = 1e9 + 7;
int dp[N], n;

// state-> dp[i] = no of ways to obtain sum of i
// transition -> dp[i] = (f(i-1)+ f(i-2)+ f(i-3)+ f(i-4)+ f(i-5)+ f(i-6))
// base case-> f(0) = 1
// final subproblem -> dp[n]

int solve(int x){
	if(x==0) return 1;
	if(dp[x] != 0) return dp[x]%M;

	dp[x] = (((x-1 >= 0) ? solve(x-1) : 0) + ((x-2 >= 0) ? solve(x-2) : 0) + ((x-3 >= 0) ? solve(x-3) : 0)
		     + ((x-4 >= 0) ? solve(x-4) : 0) + ((x-5 >= 0) ? solve(x-5) : 0) + ((x-6 >= 0) ? solve(x-6) : 0)) % M;

	return dp[x]%M;
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	memset(dp, 0, sizeof(dp));


	cout<<solve(n)<<" ";

}
