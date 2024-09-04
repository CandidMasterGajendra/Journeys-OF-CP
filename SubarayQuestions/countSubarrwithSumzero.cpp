//Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        
        unordered_map<int, int>mp;
        long long k = 0;
        
        long long pfsum = 0;
        long long ans = 0;
        mp[pfsum]++;
        for(int i = 0; i < arr.size(); i++){
            pfsum += arr[i];
            if(mp.find(pfsum - k) != mp.end()){
                ans += mp[pfsum-k];
            }
            mp[pfsum]++;
        }
        
        
        return ans;
        
    }
