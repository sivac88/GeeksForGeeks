int minSwaps(int a[], int n){
    
    pair<int,int> b[n];
    
    for(int i=0;i<n;i++)
    {
        b[i].first  = a[i];
        b[i].second = i;
    }
    
    sort(b,b+n);
    
    vector<bool> vis(n,false);
    int ans=0;
    
    for(int i=0;i<n;i++)
    {
        if(vis[i] || b[i].second == i)
        continue;
        
        int j=i,cycles=0;
        while(!vis[j])
        {
           vis[j] = 1;
           j=b[j].second;
           cycles++;
        }
        if(cycles>0)
        {
            ans+=(cycles-1);
        }
    }
    return ans;
}