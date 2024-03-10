#include <iostream>
#include <queue>

using namespace std;

int n, ans;
int arr[16][16];
int DP[16][16][3]; // 0 = 가로, 1 = 세로, 2 = 대각선

int main(void) {
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    DP[0][1][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            // 가로 방향일 때

            if(arr[i][j] == 0) {
                if(j - 1 >= 0) {
                    DP[i][j][0] += DP[i][j - 1][0] + DP[i][j - 1][2];
                }
            }

            // 세로 방향일 때

            if(arr[i][j] == 0) {
                if(i - 1 >= 0) {
                    DP[i][j][1] += DP[i - 1][j][1] + DP[i - 1][j][2];
                }
            }

            // 대각선 방향일 때

            if(arr[i][j] == 0 && arr[i - 1][j] == 0 && arr[i][j - 1] == 0) {
                if(i - 1 >= 0 && j - 1 >= 0) {
                    DP[i][j][2] += DP[i - 1][j - 1][0] + DP[i - 1][j - 1][1] + DP[i - 1][j - 1][2];
                }
            }
        }
    }

    ans = DP[n - 1][n - 1][0] + DP[n - 1][n - 1][1] + DP[n - 1][n - 1][2];

    cout << ans;

    return 0;
}