#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> graph[100001];
bool visited[100001];
int parent[100001];

void DFS(int n) {
    for(int i = 0; i < graph[n].size(); i++) {
        if(!visited[graph[n][i]]) {
            visited[graph[n][i]] = true;
            parent[graph[n][i]] = n;
            DFS(graph[n][i]);
        }
    }
}

int main(void) {
    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int a, b;

        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited[1] = true;

    DFS(1);

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}