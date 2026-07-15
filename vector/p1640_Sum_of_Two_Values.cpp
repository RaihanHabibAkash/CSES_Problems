// Problem: Sum of Two Values
// Platform: CSES
// Difficulty: Easy
// Link: https://cses.fi/problemset/task/1640/
// Topics: Vector sorting, Pair

/*
Time limit: 1.00 s
Memory limit: 512 MB

You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print two integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le x,a_i \le 10^9

Example
Input:
4 8
2 7 5 1

Output:
2 4
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int len, target; cin >> len >> target;
    vector<pair<int,int>> v;
    for(int i = 0; i < len; i++) {
        int val; cin >> val;
        v.push_back({val, i+1});
    }

    int l = 0, r = v.size()-1;
    sort(v.begin(), v.end());
    while(l < r) {
        if(v[l].first + v[r].first == target) {
            cout << v[l].second << " " << v[r].second << endl;
            return 0;
        }
        else if(v[l].first + v[r].first < target) l++;
        else r--;
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}