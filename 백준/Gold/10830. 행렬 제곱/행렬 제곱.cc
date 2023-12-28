#include <iostream>
#include <algorithm>

using namespace std;

int n, arr[5][5], ans[5][5];
long long b;

void matrix_mult(int arr1[5][5], int arr2[5][5]) {
    int temp[5][5];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                temp[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            arr1[i][j] = temp[i][j] % 1000;
        }
    }
}

int main(void) {

    cin >> n >> b;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // 정답 행렬 단위 행렬로 초기화
    for(int i = 0; i < n; i++) {
        ans[i][i] = 1;
    }

    while(b > 0) { // 5 - 2 - 1 - 0
        if(b % 2 == 1) {
            matrix_mult(ans, arr);
        }

        matrix_mult(arr, arr);

        b /= 2;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}