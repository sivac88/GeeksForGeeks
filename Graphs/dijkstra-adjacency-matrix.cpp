//https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

int minDistVertex(int distance[],bool visited[],int V)
{
    int min_idx,min=INT_MAX;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && distance[i] <= min)
        {
            min=distance[i];
            min_idx=i;
        }
    }
    return min_idx;
}


/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   int dist[V];
   bool visited[V];
   
   for(int i=0;i<V;i++)
   dist[i]=INT_MAX,visited[i]=false;
   
   dist[s] = 0;
   
   for(int i=0;i<V-1;i++)
   {
       int u=minDistVertex(dist,visited,V);
       visited[u] = true;
       
       for(int j=0;j<V;j++)
       {
           if(graph[u][j] && !visited[j] && dist[u]+graph[u][j] < dist[j])
           dist[j] = dist[u]+graph[u][j];
       }
   }
   
   for(int i=0;i<V;i++)
   cout<<dist[i]<<" ";
}