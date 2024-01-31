#include <iostream>
#include <algorithm>

using namespace std;

int n, result;
int arr[1000];
int DP[1000]; // 앞에서부터 찾는 부분 수열
int R_DP[1000]; // 뒤에서부터 찾는 부분 수열

int main(void) {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        DP[i] = 1;
        R_DP[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(arr[i] > arr[j]) {
                R_DP[i] = max(R_DP[i], R_DP[j] + 1);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        result = max(result, DP[i] + R_DP[i]);
    }

    cout << result - 1;

    return 0;
}