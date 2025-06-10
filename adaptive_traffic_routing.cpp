#include<bits/stdc++.h>
using namespace std;
const int inf=INT_MAX;
const int city_count=10;
vector<string> citynames={"Chennai","Viluppuram","Dindigul","Trichy","Madurai","Coimbatore","Salem","Tuticorin","Tirunelveli","Nagercoil"};
int getindex(string city)
{
    for(int i=0;i<city_count;i++)
        if(citynames[i]==city) return i;
    return -1;
}
class Graph
{
  int V;
  vector<vector<pair<int,int>>> adj;//(edge,cost)
  public:
  Graph(int V)
  {
      this->V=V;
      adj.resize(V);
  }
  void addedge(int u,int v,int time)
  {
      adj[u].push_back({v,time});
      adj[v].push_back({u,time});
  }
  void updatetraffic(int u,int v,int newtime)
  {
      for(auto &edge:adj[u])
      {
          if(edge.first==v) edge.second=newtime;
      }
      for(auto &edge:adj[v])
      {
          if(edge.first==u) edge.second=newtime;
      }
  }
  void printpath(vector<int>&parent,int src,int dest,int dist)
  {
      vector<int> path;
      for(int i=dest;i!=-1;i=parent[i])
      {
          path.push_back(i);
      }
      reverse(path.begin(),path.end());
      int n=path.size();
      cout<<"\nShortest path:";
      for(int i=0;i<n-1;i++)
      {
          cout<<citynames[path[i]]<<"->";
      }
      cout<<citynames[path[n-1]];
      cout<<"\nTime:"<<dist<<" minutes\n";
  }
  void findshortestpath(int src,int dest)
  {
      vector<int> dist(V,inf),parent(V,-1);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
      dist[src]=0;
      pq.push({0,src});
      while(!pq.empty())
      {
          int curdist=pq.top().first;
          int u=pq.top().second;
          pq.pop();
          for(auto &edge:adj[u])
          {
              int v=edge.first;
              int time=edge.second;
              if(dist[v]>curdist+time)
              {
                  dist[v]=curdist+time;
                  parent[v]=u;
                  pq.push({dist[v],v});
              }
          }
      }
      if(dist[dest]==inf)
      {
          cout<<"No path from "<<citynames[src]<<" to "<<citynames[dest]<<endl;
          return;
      }
      printpath(parent,src,dest,dist[dest]);
  }
};
int main()
{
    Graph g(city_count);
    int ch=0;
    cout<<"Menu:\n1.Add path\n2.Update traffic\n3.Find shortest path\n4.Exit\n";
    while(1)
    {
        cout<<"\nEnter choice:";
        cin>>ch;
        if(ch==4) break;
        string s,d;
        cout<<"Enter source city:";
        cin>>s;
        cout<<"Enter destination city:";
        cin>>d;
        int u=getindex(s),v=getindex(d);
        if(u==-1 or v==-1) cout<<"Invalid city name\n";
        if(ch==1 or ch==2)
        {
            int t;
            cout<<"Enter time (in minutes):";
            cin>>t;
            if(ch==1) g.addedge(u,v,t);
            else g.updatetraffic(u,v,t);
        }
        else if(ch==3)
        {
            g.findshortestpath(u,v);
        }
        else
        {
            cout<<"Invalid choice.\n";
        }
    }
    return 0;
}
