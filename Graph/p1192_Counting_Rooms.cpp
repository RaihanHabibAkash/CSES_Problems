// Problem: Counting Rooms
// Platform: CSES
// Difficulty: Medium
// Link: https://cses.fi/problemset/task/1192
// Topics: 2D Grid DFS, Components count
/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
vector<pair<int,int>> mv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int rows, cols;

bool valid(int i, int j) {
    if(i < 0 || i >= rows || j < 0 || j >= cols)
        return false;
    return true;
}

void dfs(int si, int sj) {
    visited[si][sj] = true;

    for(int i = 0; i < 4; i++) {
        int ci = si + mv[i].first,
            cj = sj + mv[i].second;

        if(valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] == '.')
            dfs(ci, cj);
    }
}

int main() {
    cin >> rows >> cols;
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            cin >> grid[i][j];
    
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(!visited[i][j] && grid[i][j] == '.') {
                dfs(i, j); cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}