#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, whiteMax = -999, blackMax = -999, ans;

int arr[10][10]; // 0 = 비숍을 놓을 수 없는 곳, 1 = 비숍을 놓을 수 있는 곳
bool visited[10][10];

vector<pair<int, int>> v;

// 비숍을 둘 수 있는지 확인
bool isPossible(int x, int y) {
    // 왼쪽 위 대각선 이동
    int nx = x - 1;
    int ny = y - 1;

    while(nx >= 0 && ny >= 0) {
        if(visited[nx][ny]) return false;
        nx--;
        ny--;
    }

    // 오른쪽 위 대각선 이동
    nx = x - 1;
    ny = y + 1;
    while(nx >= 0 && ny < n) {
        if(visited[nx][ny]) return false;
        nx--;
        ny++;
    }

    return true;
}

void whiteDFS(int idx, int cnt) {
    whiteMax = max(whiteMax, cnt);

    for(int i = idx; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if(x % 2 == 0 && y % 2 == 0) {
            continue;
        }
        if(x % 2 == 1 && y % 2 == 1) {
            continue;
        }

        if(!visited[x][y] && isPossible(x, y)) {
            visited[x][y] = true;
            whiteDFS(i + 1, cnt + 1);
            visited[x][y] = false;
        }
    }
}

void blackDFS(int idx, int cnt) {
    blackMax = max(blackMax, cnt);

    for(int i = idx; i < v.size(); i++) {
        int x = v[i].first;
        int y = v[i].second;

        if(x % 2 == 0 && y % 2 == 1) {
            continue;
        }
        if(x % 2 == 1 && y % 2 == 0) {
            continue;
        }

        if(!visited[x][y] && isPossible(x, y)) {
            visited[x][y] = true;
            blackDFS(i + 1, cnt + 1);
            visited[x][y] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == 1) {
                v.push_back({i, j});
            }
        }
    }

    whiteDFS(0, 0);
    blackDFS(0, 0);
    
    ans = whiteMax + blackMax;

    cout << ans;

    return 0;
}