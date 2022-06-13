#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

using Node = list<int>;
using Graph = vector<Node>;

void print_vector(const vector<int>&v){
    for (int i=0;i<v.size()-1;i++) cout<<v[i]<<" ";
    cout<<v[v.size()-1]<<endl;
}

Graph read_graph(int n, int m, vector<int> &pre){
    // pre[u] is the amount of edges pointing at u.
    Graph G(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        pre[v]++;
    }
return G;
}


vector<int> linearize(const Graph &G, vector<int>&pre){
//linearizes DAG taking into account lexicographic order.
int n=G.size();
vector<int> l;
priority_queue<int, vector<int>, greater<int>> pq;

for (int i=0; i<n;i++){
    if (pre[i]==0)pq.push(i);
}

while (not pq.empty()){
    int u =pq.top();
    pq.pop();
    l.push_back(u);
    for (Node a:G[u]){
        pre[a]--;
        if (pre[a]==0) pq.push(a);
    }
}
return l;
}

int main(){
int n,m;
while(cin>>n>>m){
vector<int> pre(n,0);
Graph G = read_graph(n,m,pre);
vector<int> v = linearize(G,pre);
print_vector(v);
}
}