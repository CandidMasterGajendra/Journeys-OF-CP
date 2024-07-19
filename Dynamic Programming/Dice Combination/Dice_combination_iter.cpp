#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6;
const int M = 1e9 + 7;
int dp[N], n;  


signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	memset(dp, 0, sizeof(dp));


	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 6; j++){
			if(i >= j){
				dp[i] += dp[i - j] % M;
			}
		}
	}

	cout<<dp[n] % M<<" ";
}