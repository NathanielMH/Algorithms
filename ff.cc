#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>

using Node = int;
using namespace std;

using Flow = vector<unordered_map<Node,int>>; //value is flow
using adjl = vector<Node>;
using Graph = vector<adjl>;

void read_graph(int m, Graph &G, Flow&F){
    for (int i=0;i<m;i++){
        Node src,dst;
        cin>>src>>dst>>F[src][dst];
        G[src].push_back(dst);
        G[dst].push_back(src);
    }
}

bool bfs(const Graph &G, Node src, vector<Node> &pre, Flow&f, int &mf){
    queue<Node> s;
    for (Node& v: pre) v = -1;
    s.push(src);
    while (not s.empty()){
        int visiting = s.front();
        s.pop();
        for (int& v : G[visiting)
        {
            if (f[visiting][v]!= 0 and pre[v]==-1)
            {
                s.push(v);
                pre[v] = visiting;
                mf = min(mf,f[visiting][v]);
                if (v == pre.size()-1) return true;
            }
        }
    }
    return false;
}

void update_edges(Flow&f,vector<Node>&pre, int mf){
    Node src = 0, dst = pre.size()-1;
    for (Node u = dst; u!=src; u=pre[u]){
        Node v = pre[u];
        f[v][u] -= mf;
        f[u][v] += mf;
    }
}

int ford_fulkerson(Graph &G, Flow &f){
    int maxflow = 0,mf=100000;
    vector<Node>pre(G.size(),-1);
    while (bfs(G,0,pre,f,mf)){
        maxflow+=mf;
        update_edges(f,pre,mf);
    }
    return maxflow;
}

int main (){
int n,m;
while (cin>>n>>m){
    Graph G(n);
    Flow f(n);
    read_graph(m,G,f);
    cout<<ford_fulkerson(G,f)<<endl;
}
}
