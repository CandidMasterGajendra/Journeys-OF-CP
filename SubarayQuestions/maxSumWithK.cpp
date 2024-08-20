long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<long long>kadane(n);
        long long ans = 0;
        long long sum = 0;
        
        // kadane's to store the max sums with index i 
        for(int i = 0; i < n; i++){
            sum += a[i];
            if(sum < 0) sum = 0;
            kadane[i] = sum;
        }
        
        
        // now sliding window -> variable nhi h but variable hai dekho dhyan se 
        sum = 0;
        for(int i = 0; i < k; i++){
            sum += a[i];
        }
        
        ans = sum;
        
        for(int i = k; i < n; i++){
            sum += a[i];
            sum -= a[i-k];
            
            ans = max(ans, sum);
            
            ans = max(ans, sum + kadane[i-k]);
        }
        
        return ans;
    }
