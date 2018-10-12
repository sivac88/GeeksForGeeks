//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* You have to complete this function*/
void bfs(int s,vector<int> adj[],bool vis[])
{
    queue<int> st;
    st.push(s);
    vis[s] = true;
    while(!st.empty())
    {
        int front = st.front();
        cout<<front<<" ";
        st.pop();
        for(auto it=adj[front].begin();it!=adj[front].end();++it)
        {
            if(!vis[*it])
            {
                st.push(*it);
                vis[*it] = true;
            }
        }
        
    }
}