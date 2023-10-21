#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2001
#define LOG 12

using namespace std;

int n, parent[MAX][LOG], d[MAX], order[2 * MAX];
bool c[MAX];
vector<int> a[MAX];

// 트리가 뒤집혀있다고 생각!

void dfs(int x, int depth) {
    c[x] = true;
    d[x] = depth;
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if(c[y]) continue;
        dfs(y, depth + 1);
    }
}

void setParent() {
    dfs(0, 0);
    for(int j = 1; j < LOG; j++) {
        for(int i = 0; i < n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int LCA(int x, int y) {
    if(d[x] > d[y]) {
        swap(x, y);
    }

    for(int i = LOG - 1; i >= 0; i--) {
        if(d[y] - d[x] >= (1 << i)) {
            y = parent[y][i];
        }
    }

    if(x == y) {
        return x;
    }

    for(int i = LOG - 1; i >= 0; i--) {
        if(parent[x][i] != parent[y][i]) {
            x = parent[x][i];
            y = parent[y][i];
        }
    }

    return parent[x][0];
}

int main(void) {
    int x, y, deleteApple, node = 0, p, idx = 0;
    string str;

    cin >> n;

    cin >> str;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') {
            p = node;
            node = ++idx;
            parent[node][0] = p;
            a[p].push_back(node);
            a[node].push_back(p);
            order[i] = node;
        } else {
            order[i] = node;
            node = parent[node][0];
        }
    }

    setParent();

    cin >> x >> y;

    if(order[x - 1] == order[y - 1]) {
        if(x < y) {
            cout << x << " " << y;
        }
        else {
            cout << y << " " << x;
        }
    } else {
        deleteApple = LCA(order[x - 1], order[y - 1]);

        for(int i = 0; i < 2 * n; i++) {
            if(order[i] == deleteApple) {
                cout << i + 1 << " ";
            }
        }
    }

    return 0;
}