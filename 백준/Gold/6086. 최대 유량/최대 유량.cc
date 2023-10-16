#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 52
#define INF 1000000000

using namespace std;

int result;
int c[MAX][MAX]; // 용량
int f[MAX][MAX]; // 유량
int d[MAX]; // 방문 확인
vector<int> graph[MAX];

void maxFlow(int start, int end) {
    while(1) {
        fill(d, d + MAX, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int i = 0; i < graph[x].size(); i++) {
                int y = graph[x][i];
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x;
                    if(y == end) {
                        break;
                    }
                }
            }
        }

        if(d[end] == -1) {
            break;
        }

        int flow = INF;

        for(int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }

        for(int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow;
        }

        result += flow;
    }
}

int main(void) {
    int n;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int capacity;
        char a, b;

        cin >> a >> b >> capacity;

        if(a >= 'a' && a <= 'z') {
            a -= 6;
        }

        if(b >= 'a' && b <= 'z') {
            b -= 6;
        }

        c[a - 'A'][b - 'A'] += capacity;

        c[b - 'A'][a - 'A'] = c[a - 'A'][b - 'A'];

        graph[a - 'A'].push_back(b - 'A');
        graph[b - 'A'].push_back(a - 'A');
    }

    maxFlow(0, 25);

    cout << result;

    return 0;
}