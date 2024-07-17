#include<bits/stdc++.h>
using namespace std;

void solve(){
    int m, n;
    cin>>m>>n;
    vector<vector<int>>grid(n, vector<int>(m));
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>grid[i][j];
        }
    }


    // init dp 
    vector<vector<int>>dp(n, vector<int>(m));

    // state -> dp[i][j] = min sum path from {(i,j) to (n-1, m-1)}

    // transition 
    // dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j]

    // base case
    dp[n-1][m-1] = grid[n-1][m-1];

    // final subproblem 
    // dp[0][0] -> min sum path from (0, 0) to (n-1, m - 1)
    for(int i = n-1; i>=0; i--){
        for(int j = m - 1; j >= 0; j--){
            if(i == n - 1 && j == m - 1){
                continue;
            }

            if(i == n -1){
                dp[i][j] = dp[i][j+1] + grid[i][j];
            }

            else if(j == m - 1){
                dp[i][j] = dp[i][j+1] + grid[i][j];
            }

            else{
                dp[i][j] = min(dp[i][j+1], dp[i+1][j]) + grid[i][j];
            }
        }
    }

    cout<<dp[0][0]<<" \n";



}



int main(){
   
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

 
    solve();
    
}