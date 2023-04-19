#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v;
    v.push_back(-1);
    for(int i = 0 ; i < N; i++) {
        int aux;
        cin >> aux;
        v.push_back(aux);
    }
    vector<int> visited2;
    visited2.assign(N + 1, 0);
    int maxim = 0;
    for (int i = 1 ; i < N + 1; i++) {
        if(visited2[i] != 1) {
            int counter = 0;
            int x = i;
            vector<int> visited;
            visited.assign(N + 1, 0);
            while (visited[x] != 1) {
                visited[x] = 1;
                visited2[x] = 1;
                counter++;
                x = v[x];
            }
            if (counter > maxim) {
                maxim = counter;
            }
        }
    }
    cout << maxim << endl;
    return 0;
}
