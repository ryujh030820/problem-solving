#include <iostream>
#include <algorithm>

using namespace std;

int t, n;

int arr[2][100000];
int DP[2][100000];

int main(void) {
    cin >> t;

    for(int i = 0; i < t; i++) {
        int ans;

        cin >> n;

        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }

        // i = 0 일시
        DP[0][0] = arr[0][0];
        DP[1][0] = arr[1][0];

        // i = 1 일시
        DP[0][1] = DP[1][0] + arr[0][1];
        DP[1][1] = DP[0][0] + arr[1][1];

        for(int i = 2; i < n; i++) {
            DP[0][i] = max(DP[1][i - 1] + arr[0][i], DP[1][i - 2] + arr[0][i]);
            DP[1][i] = max(DP[0][i - 1] + arr[1][i], DP[0][i - 2] + arr[1][i]);
        }

        ans = max(DP[0][n - 1], DP[1][n - 1]);

        cout << ans << endl;
    }

    return 0;
}