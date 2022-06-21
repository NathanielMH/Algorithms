#include<iostream>
#include<vector>
#include<stack>

using namespace std;
using Node = int;
using adjlist = vector<Node>;
using Graph = vector<adjlist>;

void explore(const Graph&G, vector<bool>&vis, int src, bool &cycle){
    vis[src] = true;
    for (Node u: G[src]){
        if (not vis[u]) explore(G,vis,u,cycle);
        else cycle = true;
    }
}

bool is_there_cycle(const Graph &G){
    int n = G.size();
    vector<bool> vis(n,false);
    bool cycle = false;
    for (Node v=0;v<n;v++){
        if (not vis[v] and not cycle) explore(G,vis,v,cycle);
    }
    return cycle;
}

Graph read_graph(){
    int n,m;
    cin>>n>>m;
    Graph G(n);
    for (int i=0;i<m;i++){
        Node u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    return G;
}

int main (){
Graph G = read_graph();
cout<<is_there_cycle(G)<<endl;
}