#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G;
    for (int i = 0 ; i < N + 1; i++) {
        vector<int> a;
        G.push_back(a);
    }
    for (int i = 0 ; i < M; i++) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    vector<int> visited;
    visited.assign(N + 1, 0);
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()) {
        int x = q.front();
        for(int i = 0 ; i < G[x].size(); i++) {
            if (visited[G[x][i]] == 0) {
                if (visited[x] == 1)
                    visited[G[x][i]] = 2;
                else
                    visited[G[x][i]] = 1;
                q.push(G[x][i]);
            }
        }
        q.pop();
    }

    int n1 = 0, n2 = 0;
    for(int i = 1; i < N + 1; i++) {
        if(visited[i] == 1) {
            n1++;
        } else n2++;
    }
    if(n1 < n2)
        cout << n1 << endl;
    else cout << n2 << endl;
    
    return 0;
}
