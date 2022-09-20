#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <climits>
#include <vector>
using namespace std;

struct Arc
{
    int dest;
    int cost;
    bool operator<(const Arc &b) const
    {
        if (cost == b.cost)
            return dest > b.dest;
        return cost > b.cost;
    }
};

using Node = list<Arc>;
using Graph = vector<Node>;

Graph build_graph(const int &n, const int &m)
{
    Graph G(n);
    int u, v, c;
    for (int j = 0; j < m; j++)
    {
        cin >> u >> v >> c;
        Arc p;
        p.dest = v;
        p.cost = c;
        G[u].push_back(p);
    }
    return G;
}

int dijkstra(const Graph &G, const int &start, const int &finish)
{
    int n = G.size();
    vector<int> dist(n, INT_MAX), prev(n, -1);
    dist[start] = 0;
    priority_queue<Arc> Q;
    Q.push({start, 0});

    while (not Q.empty())
    {
        int u = Q.top().dest;
        Q.pop();
        for (auto it = G[u].begin(); it != G[u].end(); it++)
        {
            Arc v = *it;
            if (dist[v.dest] > dist[u] + v.cost)
            {
                dist[v.dest] = dist[u] + v.cost;
                prev[v.dest] = u;
                Q.push({v.dest, dist[v.dest]});
            }
        }
    }
    return dist[finish];
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        Graph G = build_graph(n, m);
        int start, finish;
        cin >> start >> finish;
        int d = dijkstra(G, start, finish);
        (d == INT_MAX) ? cout << "no path from " << start << " to " << finish << endl : cout << d << endl;
    }
}
