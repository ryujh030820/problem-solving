#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;

vector<int> v[32001];
int inDegree[32001], visited[32001];
deque<int> q;

void topologySort() {
    int result[32001], i = 1;
    
    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) {
            q.push_back(i);
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop_front();

        if(inDegree[x] == 0 && visited[x] == 0) {
            result[i++] = x;
            visited[x] = 1;

            for(int j = 0; j < v[x].size(); j++) {
                int y = v[x][j];

                if(--inDegree[y] == 0) {
                    q.push_front(y);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        printf("%d ", result[i]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        inDegree[b]++;
        q.push_back(a);
    }

    topologySort();

    return 0;
}