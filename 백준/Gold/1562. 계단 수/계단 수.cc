#include <iostream>

using namespace std;

#define mod 1000000000

int DP[101][10][1 << 10] = {0, };

int main(void) {
    int n;
    int full = (1 << 10) - 1;
    long long ans = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=1; i<=n; i++) {
        for(int j=0; j<=9; j++) {
            if(i == 1 && j == 0) {
                continue;
            }
            else {
                for(int k=0; k<=full; k++) {
                    if(i == 1) {
                        DP[i][j][(1 << j)] = 1;
                    }

                    if(j == 0) {
                        DP[i][j][(1 << j) | k] += DP[i-1][j+1][k] % mod;
                    }
                    else if(j == 9) {
                        DP[i][j][(1 << j) | k] += DP[i-1][j-1][k] % mod;
                    }
                    else {
                        DP[i][j][(1 << j) | k] += DP[i-1][j-1][k] % mod;
                        DP[i][j][(1 << j) | k] += DP[i-1][j+1][k] % mod;
                    }
                }
            }
        }
    }

    for(int i=0; i<=9; i++) {
        ans += DP[n][i][full];
    }

    cout << ans % mod;

    return 0;
}