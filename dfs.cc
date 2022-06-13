#include <iostream>
#include <stack>
#include <list>
#include <vector>
using namespace std;
using Node = list<int>;
using Graph = vector<Node>;

void dfs(const Graph &G, const int &src)
// pre : src is a node from the Graph
{
    vector<bool> visited(G.size(), false);
    stack<int> s;
    s.push(src);
    while (not s.empty())
    {
        int visiting = s.top();
        s.pop();
        visited[visiting] = true;
        for (auto it = G[visiting].begin(); it != G[visiting].end(); it++)
        {
            if (not visited[*it])
            {
                s.push(*it);
            }
        }
    }
}

int main()
{
}