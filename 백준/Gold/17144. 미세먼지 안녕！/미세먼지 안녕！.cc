#include <iostream>

using namespace std;

int r, c, t;
int A[1000][1000];
int add[1000][1000];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int up_row, down_row, ans;

void spreadDust() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            add[i][j] = 0;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(nx >= 0 && nx < c && ny >= 0 && ny < r) {
                    if(!(nx == 0 && (ny == up_row || ny == down_row))) {
                        add[ny][nx] += A[i][j] / 5;
                        add[i][j] -= A[i][j] / 5;
                    }
                }
            }
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            A[i][j] += add[i][j];
        }
    }
}

void airCleaner() {
    // 위쪽 공기청정기

    // 왼쪽 화살표
    for(int i = up_row - 1; i > 0; i--) {
        A[i][0] = A[i - 1][0];
    }

    // 위쪽 화살표
    for(int i = 0; i < c - 1; i++) {
        A[0][i] = A[0][i + 1];
    }

    // 오른쪽 화살표
    for(int i = 0; i < up_row; i++) {
        A[i][c - 1] = A[i + 1][c - 1];
    }

    // 아래쪽 화살표
    for(int i = c - 1; i > 1; i--) {
        A[up_row][i] = A[up_row][i - 1];
    }

    A[up_row][1] = 0;

    // 아래쪽 공기청정기

    // 왼쪽 화살표
    for(int i = down_row + 1; i < r - 1; i++) {
        A[i][0] = A[i + 1][0];
    }

    // 아래쪽 화살표
    for(int i = 0; i < c - 1; i++) {
        A[r - 1][i] = A[r - 1][i + 1];
    }

    // 오른쪽 화살표
    for(int i = r - 1; i > down_row; i--) {
        A[i][c - 1] = A[i - 1][c - 1];
    }

    // 위쪽 화살표
    for(int i = c - 1; i > 1; i--) {
        A[down_row][i] = A[down_row][i - 1];
    }

    A[down_row][1] = 0;
}

int main(void) {
    cin >> r >> c >> t;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> A[i][j];

            if(A[i][j] == -1) {
                if(A[i - 1][j] == -1) {
                    down_row = i;
                } else {
                    up_row = i;
                }
            }
        }
    }

    for(int i = 0; i < t; i++) {
        spreadDust();
        airCleaner();
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(A[i][j] > 0) {
                ans += A[i][j];
            }
        }
    }

    cout << ans;

    return 0;
}