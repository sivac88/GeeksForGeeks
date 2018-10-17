/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* The function prints V space separated integers where 
    the ith integer denote the shortest distance of ith vertex
    from source vertex */
void dijkstra(int graph[MAX][MAX], int s,int V)
{
   set<pair<int,int> > ss;
   ss.insert(make_pair(0,s));
   vector<int> dist(V,INT_MAX);
   dist[s] = 0;
   
   while(!ss.empty())
   {
       pair<int,int> shortest = *(ss.begin());
       ss.erase(ss.begin());
       int u=shortest.second;
       dist[u] = shortest.first;
       for(int i=0;i<V;i++)
       {
           if(dist[i] > dist[u]+graph[u][i])
           {
               if(dist[i]!=INT_MAX)
                ss.erase(ss.find(make_pair(dist[i],i)));
                
               dist[i] = dist[u]+graph[u][i];
               ss.insert(make_pair(dist[i],i));
           }
       }
   }
   
   for(int i=0;i<V;i++)
    cout<<dist[i]<<" ";
}