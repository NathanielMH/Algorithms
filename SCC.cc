#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

using Node = int;
using adjlist = list<Node>;
using Graph = vector<adjlist>;

Graph reverse(const Graph &G){
    int n=G.size();
    Graph R(n);
    for (int i=0;i<n;i++){
        for (auto it=G[i].begin();it!=G[i].end();it++){
            R[*it].push_back(i);
        }
    }
    return R;
}

void explore(const Graph &G, stack<Node>&s, Node src, vector<bool> &vis){
        vis[src]=true;
        for (Node u: G[src]){
            if (not vis[u])
                explore(G,s,u,vis);
        }
    s.push(src);
}

void dfs(const Graph &G, stack<Node>&s){
    vector<bool> vis(G.size(),false);
    for (int i = 0;i<G.size();i++){
        if (not vis[i]){
            explore(G,s,i,vis);
        }
    }
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

stack<Node> postnum(const Graph &G){
    stack<Node>s;
    dfs(G,s);
    return s;
}

void explore_cc(const Graph &G, vector<int> &ccnum, Node src, int cc){
ccnum[src]=cc;
for (Node u: G[src]){
    if (ccnum[u]==-1){
        explore_cc(G,ccnum,u,cc);
    }
}
}

int CC(const Graph &G, stack<Node>&s){
    int n = G.size();
    vector<int> ccnum(n, -1);
    int cc = 0;
    while (not s.empty()){
        Node u = s.top();
        s.pop();
        if (ccnum[u]==-1){
            explore_cc(G,ccnum,u,cc++);
        }
    }
 return cc;
}

int SCC(const Graph &G){
    Graph R = reverse(G);
    stack<Node>s = postnum(R);
    return CC(G,s);
}


int main (){
}