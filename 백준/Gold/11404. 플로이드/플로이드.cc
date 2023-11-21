#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000

using namespace std;

int n, m;
vector<pair<int, int>> a[101];
int d[101][101];

void floydWarshall() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                d[i][j] = 0;
            } else {
                d[i][j] = INF;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < a[i].size(); j++) {
            d[i][a[i][j].first] = min(d[i][a[i][j].first], a[i][j].second);
        }
    }

    for(int i = 1; i <= n; i++) { // 거쳐가는 노드
        for(int j = 1; j <= n; j++) { // 출발 노드
            for(int k = 1; k <= n; k++) { // 도착 노드
                if(d[j][i] + d[i][k] < d[j][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    cin >> m;

    for(int i = 0; i < m; i++) {
        int start, dest, cost;

        cin >> start >> dest >> cost;

        a[start].push_back({dest, cost});
    }

    floydWarshall();

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d[i][j] != INF) {
                cout << d[i][j] << " ";
            } else {
                cout << 0 << " ";
            }
        }

        cout << endl;
    }

    return 0;
}