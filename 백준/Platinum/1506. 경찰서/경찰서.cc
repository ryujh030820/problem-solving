#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstdio>

using namespace std;

int id, d[100], ans;
bool finished[100];
int cost[100];
vector<pair<int, int>> info;
vector<int> v[100];
stack<int> s;

int dfs(int x) {
    d[x] = ++id; // 노드마다 고유한 번호를 할당
    s.push(x); // 스택에 자기 자신을 삽입

    int parent = d[x];

    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];

        if(d[y] == 0) {
            parent = min(parent, dfs(y));
        }
        else if(!finished[y]) {
            parent = min(parent, d[y]);
        }
    }

    if(parent == d[x]) { // 부모노드가 자기 자신인 경우
        int MIN = 1000001;

        while(1) {
            int t = s.top();
            s.pop();
            finished[t] = true;

            MIN = min(MIN, cost[t]);

            if(t == x) {
                break;
            }
        }

        ans += MIN;
    }

    // 자신의 부모 값을 반환합니다.
    return parent;
}

int main(void) {
    int n;

    cin >> n;

    for(int i=0; i<n; i++) {
        int n;

        cin >> n;

        cost[i] = n;
        info.push_back({cost[i], i});
    }

    sort(info.begin(), info.end());

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int n;

            scanf("%1d", &n);

            if(n == 1) { // 그 도시로 갈 수 있는 경우
                v[i].push_back(j);
            }
        }
    }

    for(int i=0; i<n; i++) {
        int idx = info[i].second;

        if(d[idx] == 0) {
            dfs(idx);
        }
    }

    cout << ans;

    return 0;
}