#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>

using Node = int;
using namespace std;

using Flow = vector<unordered_map<Node,Node>>; //value is flow
using adjl = list<Node>;
using Graph = vector<adjl>;

void read_graph(int n,int m, Graph &G, Flow&F){
    G = Graph(n);
    F= Flow(n);
    for (int i=0;i<m;i++){
        Node src,dst;
        int fl;
        cin>>src>>dst>>fl;
        G[src].push_back(dst);
        F[src][dst] = fl;
        F[dst].insert({src,0}); //only happens if none was inserted before.
    }
}

bool bfs(const Graph &G, Node src, vector<Node> &pre, Flow&f){
    vector<bool> queued(G.size(), false);
    queue<Node> s;
    s.push(src);
    queued[src] = true;
    pre[src] = -1;
    while (not s.empty())
    {
        int visiting = s.front();
        s.pop();
        for (auto it = G[visiting].begin(); it != G[visiting].end(); it++)
        {
            if (not queued[*it] and  f[visiting][*it]!= 0)
            {
                s.push(*it);
                queued[*it] = true;
                pre[*it] = visiting;
            }
        }
    }
    return queued[G.size()-1];
}

int min_edge(const vector<Node>&pre, Flow&f){
    Node src = 0, dst = pre.size()-1;
    int mf=100000;
    for (Node u = dst; u!=src; u=pre[u]){
        Node v = pre[u];
        mf = min(mf,f[v][u]);
    }
    return mf;
}

void update_edges(Flow &f, vector<Node>&pre, int mf, Graph &G){
    Node src = 0, dst = pre.size()-1;
    for (Node u = dst; u!=src; u=pre[u]){
        Node v = pre[u];
        f[v][u] -= mf;
        f[u][v] += mf;
        if (f[u][v] == mf) G[u].push_back(v);
    }
}

int ford_fulkerson(Graph &G, Flow &f){
    int maxflow = 0,n=G.size();
    vector<Node>pre(G.size());
    while (bfs(G,0,pre,f)){
        int mf = min_edge(pre,f);
        maxflow+=mf;
        update_edges(f,pre,mf,G);
    }
    return maxflow;
}

int main (){
int n,m;
while (cin>>n>>m){
    Graph G;
    Flow f;
    read_graph(n,m,G,f);
    cout<<ford_fulkerson(G,f)<<endl;
}
}