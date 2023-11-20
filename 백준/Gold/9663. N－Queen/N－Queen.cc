#include <iostream>
#include <cmath>

using namespace std;

int n, ans;
int col[15]; 

bool check(int level) {
    for(int i = 0; i < level; i++) {
        if(col[i] == col[level]) {
            return false;
        }

        if(col[i] == col[level] - level + i) { // 왼쪽 위 대각선
            return false;
        }

        if(col[i] == col[level] + level - i) { // 오른쪽 위 대각선
            return false;
        }
    }

    return true;
}

void DFS(int x) {
    if(x == n) {
        ans++;
    } else {
        for(int i = 0; i < n; i++) {
            col[x] = i;

            if(check(x)) {
                DFS(x + 1);
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    DFS(0);

    cout << ans;

    return 0;
}