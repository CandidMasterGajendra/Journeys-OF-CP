#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int>arr(n);
    vector<int>dp(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // state -> dp[i] -> max sum from ith element till n-1 th element

    // transition ->
    // dp[i] = max(arr[i] + dp[i+2], dp[i+1])


    // base case 
    dp[n - 1] = arr[n - 1];
    dp[n - 2] = max(dp[n - 1], dp[n - 2]);

    for(int i = n - 3; i >= 0; i--){
        dp[i] = max(arr[i] + dp[i + 2], dp[i+1]);
    }

    // final subproblem
    // dp[0]

    cout<<dp[0]<<"\n";

}


void alighter(){
    int n;
    cin>>n;

    vector<int>arr(n);
    vector<vector<int>>dp(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    // state -> 
    // dp[i][0] -> max sum we cn get from ith house to n - 1 th house such that we pick up the ith house
    // dp[i][1] -> max sum " " " " such that we dont pick up the ith house 

    // transition ->
    // dp[i][1] = arr[i] + dp[i+1][0] 
    // dp[i][0] = max(dp[i + 1][1], dp[i + 1][0])


    // base case 
    dp[n - 1][1] = arr[n - 1];
    dp[n - 1][0] = 0;

    for(int i = n - 2; i >= 0; i--){
        dp[i][0] = arr[i] + dp[i+1][0];
        dp[i][1] = max(dp[i+1][0], dp[i+1][1]);
    }

    // final subproblem
    // max(dp[0][0], dp[0][1])

    cout<< max(dp[0][0], dp[0][1])<<"\n";


}

int main(){
    solve();

}
