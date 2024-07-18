#include<bits/stdc++.h>
using namespace std;


#define int long long
const int N = 5000;
int dp[N][N], arr[N], n;


// state -> dp(l, r) -> max score alice can had when array is from index l to r
// transition -> dp(l, r) = max(arr[l] + min(), arr[r] + min())
// base case -> when l == r
// final subproblem => dp[0][n - 1]

int solve(int l, int r){
	// base case
	dp[n-1][n-1] = arr[n-1];

	// transition in iterative 
	// dp[i][j] depends on (dp[i+1][j+1], dp[i+2][j], dp[i][j-2])
	// i depends on its ahead values, j on its prev values
	// i have to build dp such that i moves from n - 1 to 0
	// && j moves from i to n - 1 why not 0 remember i <= j

	for(int l = n - 1; l >= 0; l--){
		for(int r = l; r < n; r++){

			if(l == r) dp[l][r] = arr[l];

			// handle few cases as can go out of bound -> crux of iterative
			int A = 0;
			if(l + 1 <= r - 1) A = dp[l+1][r-1];
			int B = 0;
			if(l + 2 <= r) B = dp[l+2][r];
			int C = 0;
			if(l <= r - 2) C = dp[l][r-2];

			dp[l][r] = max(arr[l] + min(A, B), arr[r] + min(A, C));
		}
	}

	return dp[0][n-1];
}


signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;

	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	// arr is ready

	memset(dp, -1, sizeof(dp));

	cout<<solve(0, n - 1)<<"\n";
}
