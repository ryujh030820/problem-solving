#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> edge;
int set[1000001];

int n, m, MAX = -999, ans;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second <= b.second;
}

int getParent(int x) {
    if(set[x] == x) {
        return x;
    }

    return set[x] = getParent(set[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);

    if(a < b) {
        set[b] = a;
    } else {
        set[a] = b;
    }
}

int find(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a == b) {
        return 1;
    } else {
        return 0;
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        set[i] = i;
    }

    for(int i = 0; i < m; i++) {
        int a, b, c;

        cin >> a >> b >> c;

        edge.push_back({c, {a, b}});
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++) {
        if(!find(edge[i].second.first, edge[i].second.second)) {
            ans += edge[i].first;
            unionParent(edge[i].second.first, edge[i].second.second);
            MAX = max(MAX, edge[i].first);
        }
    }

    cout << ans - MAX;

    return 0;
}