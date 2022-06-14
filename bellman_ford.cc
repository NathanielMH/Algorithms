#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

struct Arc{
    int vert;
    int cost;
};
using AdjL = list<Arc>;
using Graph = vector<AdjL>;

using INF = 100000000;

Graph read_graph(int n,int m){
    Graph G(n);
    for (int i=0;i<m;i++){
        int u;
        Arc a;
        cin>>u>>a.vert>>a.cost;
        G[u].push_back(a);
    }
return G;
}

int bellmanford(const Graph &G, int src, int dest){
    int n=G.size();
    bool finished = false;
    vector<int> dist(n,INF), prev(n,-1);
    dist[src] = 0;
    int t=n-1;
    while (t-- and not finished){
        int changes=0;
        for (int i=0;i<n;i++){
            for (auto it = G[i].begin();it!=G[i].end();it++){
                int u=i;
                Arc v=*it;
                if (dist[v.vert] > dist[u] + v.cost){
                    dist[v.vert] = dist[u] + v.cost;
                    prev[v.vert] = u;
                    changes++;
                }
            }
        }
        finished = (changes == 0);
    }
    return dist[dest];
}

int main (){
    int n,m;
while (cin>>n>>m){
    Graph G = read_graph(n,m);
    int x,y;
    cin>>x>>y;
    int d = bellmanford(G,x,y); 
    (d != INF) ? cout << d << endl : cout << "no path from "<<x<<" to "<< y << endl;
}
}