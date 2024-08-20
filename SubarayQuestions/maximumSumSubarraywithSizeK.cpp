long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        long ans = 0;
        long sum = 0;
        int index = 0;
        for(;index < K; index++){
            sum += Arr[index];
        }
        
        if(index == K) ans = sum;
        
        for(int i = K; i < N; i++){
            sum += Arr[i];
            sum -= Arr[i-K];
            
            ans = max(ans, sum);
        }
        
        return ans;
        
        
    }
