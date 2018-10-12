//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
bool dfs(int cur,list<int> *adj,vector<bool>& visited)
{
    visited[cur] = true;
    for(auto it=adj[cur].begin();it!=adj[cur].end();it++)
    {
        if(visited[*it])
        return true;
        
        if(dfs(*it,adj,visited))
        return true;
    }
    
    visited[cur] = false;
    return false;
}

/*You are required to complete this method*/
bool Graph :: isCyclic()
{
   vector<bool> visited(V,false);
   for(int i=0;i<V;i++){
      if(!visited[i])
      {
        if(dfs(i,adj,visited))
        return true;
      }
   }
   return false;
}