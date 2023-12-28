#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
int num[10001];

vector<int> v;

void DFS(int a, int cnt) {
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";

        return;
    } else {
        for(int i = 0; i < v.size(); i++) {
            if(num[v[i]] > 0) {
                arr[cnt] = v[i];
                num[v[i]]--;
                DFS(i, cnt + 1);
                num[v[i]]++;
            }
        }
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int dir;

        cin >> dir;

        if(num[dir] == 0) {
            v.push_back(dir);
        }

        num[dir]++;
    }

    sort(v.begin(), v.end());

    DFS(0, 0);

    return 0;
}