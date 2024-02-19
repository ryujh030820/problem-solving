#include <iostream>
#include <vector>

using namespace std;

int n, m, edgeCount;
int arr[50];

vector<pair<int, int>> v;
vector<pair<int, int>> temp;

int getParent(int set[], int x) {
    if(set[x] == x) {
        return x;
    }

    return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if(a < b) {
        set[b] = a;
    } else {
        set[a] = b;
    }
}

int find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    if(a == b) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;

            cin >> c;

            if(c == 'Y' && i < j) {
                v.push_back({i, j});
            }
        }
    }

    int set[n];

    for(int i = 0; i < n; i++) {
        set[i] = i;
    }

    for(int i = 0; i < v.size(); i++) {
        if(!find(set, v[i].first, v[i].second)) {
            arr[v[i].first]++;
            arr[v[i].second]++;
            unionParent(set, v[i].first, v[i].second);
            edgeCount++;
        } else {
            temp.push_back({v[i].first, v[i].second});
        }
    }

    if(edgeCount == n - 1) {
        for(int i = 0; i < m - n + 1; i++) {
            if(i >= temp.size()) {
                break;
            }

            arr[temp[i].first]++;
            arr[temp[i].second]++;
            edgeCount++;
        }

        if(edgeCount == m) {
            for(int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
        } else {
            cout << -1;
        }
    } else {
        cout << -1;
    }

    return 0;
}