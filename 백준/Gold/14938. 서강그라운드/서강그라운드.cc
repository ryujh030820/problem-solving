#include <iostream>

#define INF 100000000

using namespace std;

int n, m, r;
int t[101];
int d[101][101];
int MAX;

void floydWarshall() {
    // 거쳐가는 노드
    for(int i = 1; i <= n; i++) {
        // 출발 노드
        for(int j = 1; j <= n; j++) {
            // 도착 노드
            for(int k = 1; k <= n; k++) {
                if(d[j][i] + d[i][k] < d[j][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> r;

    fill(&d[0][0], &d[n][n], INF);

    for(int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for(int i = 0; i < r; i++) {
        int a, b, l;

        cin >> a >> b >> l;

        d[a][b] = l;
        d[b][a] = l;
    }

    floydWarshall();

    for(int i = 1; i <= n; i++) {
        int temp = 0;

        for(int j = 1; j <= n; j++) {
            if(d[i][j] <= m) {
                temp += t[j];
            }
        }

        if(temp > MAX) {
            MAX = temp;
        }
    }

    cout << MAX;

    return 0;
}