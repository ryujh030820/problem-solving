#include <iostream>

using namespace std;

int arr[1025][1025];
int n, m;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];

            arr[i][j] += arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }

    for(int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        int result;

        cin >> x1 >> y1 >> x2 >> y2;

        result = arr[x2][y2] - arr[x2][y1 - 1] - arr[x1 - 1][y2] + arr[x1 - 1][y1 - 1];

        cout << result << "\n";
    }

    return 0;
}