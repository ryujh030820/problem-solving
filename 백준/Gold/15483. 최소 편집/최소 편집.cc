#include <iostream>
#include <algorithm>

#define INT_MAX 2e+9

using namespace std;

int DP[1001][1001];

int main(void) {
    string a, b;

    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    for(int i = 0; i < 1001; i++) {
        for(int j = 0; j < 1001; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    DP[0][0] = 0;

    for(int i = 1; i < a.size(); i++) {
        DP[i][0] = i;
    }

    for(int i = 1; i < b.size(); i++) {
        DP[0][i] = i;
    }

    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            if(a[i] == b[j]) {
                DP[i][j] = min(DP[i][j], DP[i - 1][j - 1]);
            } else {
                // 삽입 연산
                DP[i][j] = min(DP[i][j], DP[i][j - 1] + 1);

                // 삭제 연산
                DP[i][j] = min(DP[i][j], DP[i - 1][j] + 1);

                // 교체 연산
                DP[i][j] = min(DP[i][j], DP[i - 1][j - 1] + 1);
            }
        }
    }

    cout << DP[a.size() - 1][b.size() - 1];

    return 0;
}