#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int dir[8];
bool visited[8];

void DFS(int a, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";

        return;
    } else {
        for(int i = 0; i < n; i++) {
            if(visited[i] == false) {
                arr[cnt] = dir[i];
                visited[i] = true;
                DFS(i, cnt + 1);
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> dir[i];
    }

    sort(dir, dir + n);

    DFS(0, 0);

    return 0;
}