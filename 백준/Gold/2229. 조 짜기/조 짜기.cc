#include <iostream>
#include <algorithm>

using namespace std;

int n;
int DP[1001];
int arr[1001];

int main(void) {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for(int i = 2; i <= n; i++) {
        int low = 10001;
        int high = -1;

        for(int j = i; j >= 1; j--) {
            low = min(low, arr[j]);
            high = max(high, arr[j]);
            DP[i] = max(DP[i], high - low + DP[j-1]);
        }
    }

    cout << DP[n];

    return 0;
}