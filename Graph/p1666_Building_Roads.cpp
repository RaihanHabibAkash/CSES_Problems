// Problem: Building Roads
// Platform: CSES
// Difficulty: Easy
// Link: https://cses.fi/problemset/task/1666/
// Topics: Udirected Graph DFS

/*
Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
Your task is to find out the minimum number of roads required, and also determine which roads should be built.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of required roads.
Then, print k lines that describe the new roads. You can print any valid solution.
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
4 2
1 2
3 4

Output:
1
2 3
*/

#include <bits/stdc++.h>
using namespace std;

bool vis[100005];
vector<int> adj_list[100005];

void dfs(int src) {
    vis[src] = true;

    for(int child : adj_list[src])
        if(!vis[child])
            dfs(child);
}

int main() {
    memset(vis, false, sizeof(vis));
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);
    }

    int cnt = -1;
    vector<int> ans;
    for(int i = 0; i < nodes; i++)
        if(!vis[i]) {
            cnt++;
            dfs(i);
            ans.push_back(i+1);
        }
    
    cout << cnt << endl;
    for(int i = 0; i + 1 < ans.size(); i++)
        cout << ans[i] << " " << ans[i+1] << endl;

    return 0;
}