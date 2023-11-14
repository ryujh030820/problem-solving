#include <iostream>
#include <algorithm>
#include <cstring>

#define INT_MAX 2000000000

using namespace std;

int n;
int w[16][16];
int DP[16][1 << 16];

int DFS(int start, int visited) { // 출발점은 0으로 고정
    if(visited == (1 << n) - 1) {
        if(w[start][0] != 0) {
            DP[start][visited] = w[start][0];
            return w[start][0];
        } else {
            return INT_MAX;
        }
    }

    if(DP[start][visited] != -1) {
        return DP[start][visited];
    }

    DP[start][visited] = INT_MAX;

    for(int i = 0; i < n; i++) {
        if(((1 << i) | visited) != visited && w[start][i] != 0) {
            DP[start][visited] = min(DP[start][visited], w[start][i] + DFS(i, visited | (1 << i)));
        }
    }

    return DP[start][visited];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }

    memset(DP, -1, sizeof(DP));

    cout << DFS(0, 1);

    return 0;
}