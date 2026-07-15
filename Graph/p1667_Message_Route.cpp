// Problem: Message Route
// Platform: CSES
// Difficulty: Easy
// Link: https://cses.fi/problemset/task/1667/
// Topics: Graph BFS with path tracker & parent Array
/*
Time limit: 1.00 s
Memory limit: 512 MB

Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, what is the minimum number of computers on such a route.
Input
The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,\dots,n. Uolevi's computer is 1 and Maija's computer is n.
Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
Every connection is between two different computers, and there is at most one connection between any two computers.
Output
If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
If there are no routes, print "IMPOSSIBLE".
Constraints

2 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 5
1 2
1 3
1 4
2 3
5 4

Output:
3
1 4 5
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool visited[100005];
int parrent[100005];

void bfs(int srcNd) {
    queue<int> q;
    q.push(srcNd);
    visited[srcNd] = true;

    while(!q.empty()) {
        int par = q.front();
        q.pop();

        for(int child : adj_list[par]) {
            if(!visited[child]) {
                q.push(child);
                visited[child] = true;
                parrent[child] = par;
            }
        }
    }

}

int main() {
    int nodes, edges; cin >> nodes >> edges;
    while(edges--) {
        int a, b; cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));
    memset(parrent, -1, sizeof(parrent));

    int src = 1, dst = nodes;
    bfs(src);

    int node = dst;
    vector<int> path;
    while(node != -1) {
        path.push_back(node);
        node = parrent[node];
    }
    reverse(path.begin(), path.end());

    if(!visited[dst]) cout << "IMPOSSIBLE" << endl;
    else {
        cout << path.size() << endl;
        for(int x : path) cout << x << " ";
        cout << endl;
    }

    return 0;
}