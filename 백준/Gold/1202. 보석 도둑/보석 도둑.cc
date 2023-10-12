#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int, int>> gem;
vector<int> bag;
priority_queue<int, vector<int>, less<int>> pq;

int main(void) {
    int n, k, idx = 0;
    long long ans = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<n; i++) {
        int m, v;

        cin >> m >> v;

        gem.push_back({m, v});
    }

    sort(gem.begin(), gem.end());

    for(int i=0; i<k; i++) {
        int c;

        cin >> c;

        bag.push_back(c);
    }

    sort(bag.begin(), bag.end());

    for(int i=0; i<k; i++) {
        while(idx < n && bag[i] >= gem[idx].first) {
            pq.push(gem[idx].second);
            idx++;
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}