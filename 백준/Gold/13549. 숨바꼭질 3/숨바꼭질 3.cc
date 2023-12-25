#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool visited[100001] = {false, };

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void BFS() {
    while(!pq.empty()) {
        int sec = pq.top().first;
        int loc = pq.top().second;
        pq.pop();

        if(loc == k) {
            cout << sec;
            return;
        }


        // 2*loc를 먼저 체크함으로서 가장 빠른 시간을 찾음
        if(2*loc <= 100000 && visited[2*loc] == false) {
            visited[2*loc] = true;
            pq.push({sec, 2*loc});
        }

        if(loc-1 >= 0 && visited[loc-1] == false) {
            visited[loc-1] = true;
            pq.push({sec+1, loc-1});
        }
        if(loc+1 <= 100000 && visited[loc+1] == false) {
            visited[loc+1] = true;
            pq.push({sec+1, loc+1});
        }
    }
}

int main(void) {
    cin >> n >> k;

    pq.push({0, n});
    visited[n] = true;

    BFS();

    return 0;
}