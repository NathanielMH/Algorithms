#include <iostream>
#include <queue>
#include <list>
#include <vector>
using namespace std;
using Node = list<int>;
using Graph = vector<Node>;

void bfs(const Graph &G, const int &src)
// pre : src is a node from the Graph
{
    vector<bool> queued(G.size(), false);
    queue<int> s;
    s.push(src);
    queued[src] = true;
    while (not s.empty())
    {
        int visiting = s.front();
        s.pop();
        for (auto it = G[visiting].begin(); it != G[visiting].end(); it++)
        {
            if (not queued[*it])
            {
                s.push(*it);
                queued[*it] = true;
            }
        }
    }
}

int main() {}