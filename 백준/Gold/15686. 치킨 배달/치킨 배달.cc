#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INT_MAX 2e9

using namespace std;

int n, m, ans = INT_MAX;
int arr[50][50];
bool visited[100];

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> selected;

int calculateChickenDistance() {
    int distance = 0, MIN;

    for(int i = 0; i < house.size(); i++) {
        MIN = INT_MAX;

        for(int j = 0; j < chicken.size(); j++) {
            if(selected[j] == 1) {
                int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);

                MIN = min(MIN, dist);
            }
        }

        distance += MIN;
    }

    return distance;
}

void selectChicken() {
    for(int i = 0; i < chicken.size() - m; i++) {
        selected.push_back(0);
    }

    for(int i = 0; i < m; i++) {
        selected.push_back(1);
    }

    do {
        ans = min(ans, calculateChickenDistance());
    } while(next_permutation(selected.begin(), selected.end()));
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if(arr[i][j] == 1) {
                house.push_back({i, j});
            } else if(arr[i][j] == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    selectChicken();

    cout << ans;

    return 0;
}