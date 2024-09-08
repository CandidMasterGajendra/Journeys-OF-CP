
void solve(){
 
int n;
cin>>n;
int a[n];
int ans =0;
for(int i =0; i<n; i++){
    cin>>a[i];
    ans+=a[i];
}
int deg[n] ={};
for(int i =0; i<n-1; i++){
    int u,v;
    cin>>u>>v;
    u--;
    v--;
    deg[u]++;
    deg[v]++;
}
 
vector<int> res ={};
//int ans =0;
for(int i =0; i<n; i++){
    for(int j =0; j<deg[i]-1; j++){
         //ans+=a[i];
        res.push_back(a[i]);
    }
}
 
sort(res.begin(),res.end());
reverse(res.begin(),res.end());
cout<<ans<<" ";
for(int i =0; i<res.size();  i++){
    cout<<ans+res[i]<<" ";
    ans = ans+res[i];
}
cout<<endl;
 
}
