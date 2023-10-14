#include <iostream>
#include <algorithm>

using namespace std;

int c, n;
int cost[21];
int client[21];
int DP[100001] = {0, }; // i원으로 늘릴 수 있는 최대 고객 수

int main(void) {
    int ans = 0;

    cin >> c >> n;

    for(int i=1; i<=n; i++) {
        cin >> cost[i] >> client[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=100000; j++) {
            if(j - cost[i] >= 0) {
                DP[j] = max(DP[j], DP[j-cost[i]] + client[i]);
            }
        }
    }

    while(DP[ans] < c) {
        ans++;
    }

    cout << ans;

    return 0;
}