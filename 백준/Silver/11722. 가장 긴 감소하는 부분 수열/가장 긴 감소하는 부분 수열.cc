#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int arr[1000];
int DP[1000];

int main(void) {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        DP[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] < arr[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }

        result = max(result, DP[i]);
    }

    cout << result;

    return 0;
}