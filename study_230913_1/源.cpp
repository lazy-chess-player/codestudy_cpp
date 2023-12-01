#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> visited;
vector<int> ans;
bool valid = true;

void dfs(int u)
{
    visited[u] = 1;
    for (auto& v : edges[u])
    {
        if (visited[v] == 0)
        {
            dfs(v);
            if (!valid)
                return;
        }
        else if(visited[v]==1)
        {
            valid = false;
            return;
        }
    }
    visited[u] = 2;
    ans.push_back(u);
}


class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (auto& info : prerequisites)
        {
            edges[info[1]].push_back(info[0]);
        }
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
            if (!valid)
            {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
	
	return 0;
}