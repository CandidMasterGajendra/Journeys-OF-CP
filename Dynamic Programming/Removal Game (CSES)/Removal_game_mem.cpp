#include<bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 5000;
int arr[N], dp[N][N], n;


int solve(int l, int r){
	if(l > r) return 0;
	if(dp[l][r] != -1) return dp[l][r];

	dp[l][r] = max(arr[l] + min(solve(l + 2, r), solve(l + 1, r - 1)), arr[r] + min(solve(l + 1, r - 1), solve(l, r - 2)));

	return dp[l][r];
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	// arr is ready 
	cout<<solve(0, n - 1)<<"\n";
}