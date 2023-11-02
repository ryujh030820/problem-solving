#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> arr[4][4];
int cnt, ans;
int dx[] = {0, -1, -1, -1, 0, 1, 1, 1}; // 0번 인덱스부터 ↑, ↖, ←, ↙, ↓, ↘, →, ↗ 순
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void piicopy(pair<int, int> src[4][4], pair<int, int> dest[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            dest[i][j].first = src[i][j].first;
            dest[i][j].second = src[i][j].second;
        }
    }
}

void fishMove(int sharkRow, int sharkCol) {
    int fish = 1;
    
    while(fish <= 16) {
        bool findFish = false;

        if(fish == arr[sharkRow][sharkCol].first) {
            fish++;
            continue;
        }

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(arr[i][j].first == fish) {
                    int num = arr[i][j].first;
                    int dir = arr[i][j].second;

                    fish++;

                    findFish = true;

                    for(int k = 0; k < 8; k++) {
                        int nextRow = i + dy[(k + dir) % 8];
                        int nextCol = j + dx[(k + dir) % 8];

                        if(nextRow >= 0 && nextRow < 4 && nextCol >= 0 && nextCol < 4) {
                            if(nextRow != sharkRow || nextCol != sharkCol) {
                                arr[i][j].first = arr[nextRow][nextCol].first;
                                arr[i][j].second = arr[nextRow][nextCol].second;

                                arr[nextRow][nextCol].first = num;
                                arr[nextRow][nextCol].second = (k + dir) % 8;

                                break;
                            }
                        }
                    }
                }
            }
        }

        if(findFish == false) {
            fish++;
        }
    }
}

void sharkMove(int row, int col, int dir, int cnt) { // DFS
    pair<int, int> save[4][4];

    fishMove(row, col);
    piicopy(arr, save);

    for(int i = 1; i <= 3; i++) {
        int nextRow = row + i * dy[dir];
        int nextCol = col + i * dx[dir];

        if(nextRow >= 0 && nextRow < 4 && nextCol >= 0 && nextCol < 4) {
            if(arr[nextRow][nextCol].first != 0 || arr[nextRow][nextCol].second != 0) {
                int sharkNum = arr[nextRow][nextCol].first;
                int sharkDir = arr[nextRow][nextCol].second;

                arr[nextRow][nextCol].first = 0;
                arr[nextRow][nextCol].second = 0;

                sharkMove(nextRow, nextCol, sharkDir, cnt + sharkNum);

                piicopy(save, arr);
            }
        }
    }

    ans = max(ans, cnt);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int a, b;

            cin >> a >> b; // 물고기의 번호, 방향

            arr[i][j].first = a;
            arr[i][j].second = b - 1;
        }
    }

    int sharkNum = arr[0][0].first;
    int sharkDir = arr[0][0].second;

    arr[0][0].first = 0;
    arr[0][0].second = 0;

    sharkMove(0, 0, sharkDir, sharkNum);

    cout << ans;

    return 0;
}