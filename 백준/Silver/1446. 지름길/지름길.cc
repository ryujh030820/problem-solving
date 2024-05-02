#include <iostream>
#include <vector>
#include <queue>

#define INF 2e9

using namespace std;

vector<pair<int, int>> a[10001];
int d[10001];
int N, D;

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int current = pq.top().second;
        int distance = -pq.top().first;
        pq.pop();

        if(d[current] < distance) {
            continue;
        }

        for(int i = 0; i < a[current].size(); i++) {
            int next = a[current][i].first;
            int nextDistance = distance + a[current][i].second;

            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

int main(void) {
    cin >> N >> D;

    for(int i = 0; i <= D; i++) {
        d[i] = INF;
        a[i].push_back({i + 1, 1});
    }

    for(int i = 0; i < N; i++) {
        int start, end, length;

        cin >> start >> end >> length;

        a[start].push_back({end, length});
    }

    dijkstra(0);

    cout << d[D];

    return 0;
}