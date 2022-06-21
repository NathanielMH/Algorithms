#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using Node = int;
struct Arc;
using adjlist = vector<Arc>;
using Graph = vector<adjlist>;

struct Arc{
    Node dst;
    int cst;
};

bool operator<(const Arc&a, const Arc&b){
    return b.cst>a.cst;
}

void prim(const Graph&G, int src){
int n = G.size();
priority_queue<pair<Node,Arc>>q;
vector<bool>vis(n,false);
vector<Node>prev(n,-1);
int k = 1;
for (Arc u: G[src]) q.push({src,u});
while (k<n){
    pair<Node,Arc> p = q.top();
    q.pop();
    Node v = p.first;
    Arc u = p.second;
    if (not vis[u.dst]){
        k++;
        prev[u.dst] = v;
        vis[u.dst] = true;
        for (Arc a: G[u.dst]){
            if (not vis[a.dst]) q.push({u.dst,a});
        }
    }
}
}

int main (){
}