//https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

void pushIntoStack(vector<int> v[],vector<int> &visited,int src,int N,stack<int>& s)
{
    visited[src] = true;
    
    for(vector<int>::iterator i=v[src].begin();i!=v[src].end();i++)
       if(!visited[*i])
          pushIntoStack(v,visited,*i,N,s);
          
    s.push(src);
}

void dfs(vector<int> v[],vector<int> &visited,int src)
{
    visited[src] = true;
    
    for(vector<int>::iterator it=v[src].begin();it!=v[src].end();it++)
       if(!visited[*it])
         dfs(v,visited,*it);
}

int kosaraju(vector<int> v[100001], int N, int M)
{
    vector<int> visited(N+1,false);
    stack<int> s;
    
    for(int i=1;i<=N;i++)
      if(!visited[i])
        pushIntoStack(v,visited,i,N,s);
        
    vector<int> transpose_v[N+1];
    
    for(int i=1;i<=N;i++){
        for(vector<int>::iterator j=v[i].begin();j!=v[i].end();j++)
            transpose_v[*j].push_back(i);
        visited[i] = false;
    }
        
    int ans=0;
    while(!s.empty())
    {
        int src=s.top();
        s.pop();
        if(!visited[src])
        {
          dfs(transpose_v,visited,src);
          ans++;
        }
    }
    
    return ans;
}