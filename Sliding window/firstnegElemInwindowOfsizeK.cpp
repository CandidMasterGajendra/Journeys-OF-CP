// #include<bits/stdc++.h>
// using namespace std;

// vector<long long> printFirstNegativeInteger(long long int v[],
//                                              long long int n, long long int k) {
    
//     vector<long long>ans;
//     queue<long long>q;
    
//     for(int i = 0; i < k; i++){
//         if(v[i] < 0) q.push(v[i]);
//     }
    
//     if(q.size()) ans.push_back(q.front());
//     else ans.push_back(0);
    
//     for(int i = k; i < n; i++){
//         if(v[i - k] < 0) q.pop();
//         if(v[i] < 0) q.push(v[i]);
        
//         if(q.size()) ans.push_back(q.front());
//         else ans.push_back(0);
//     }
    
//     return ans;
                                                 
//  }

 


//     int main(){

//     }

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;

		vector<int>v(n);
		for(auto& i: v){
			cin>>i;
		}

		int sum = 0;

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		if(n & 1){
			for(int i = 0; i < n-1; i+=2){
				sum += v[i] - v[i+1];
			}
			sum = max(sum - k, 0);
			sum += v[n-1];

		} else{
			for(int i = 0; i < n; i+=2){
				sum += v[i] - v[i+1];
			}
			sum = max(sum-k, 0);
		}

		// sum = max(0, sum - k);

		cout<<sum<<"\n";
	}
}