#include <iostream>
#include <algorithm>

#define NUMBER 100000
#define MAX 1000000001
#define MIN 0

using namespace std;

int n, m, ans_min, ans_max;

int a[NUMBER];
int minTree[4 * NUMBER];
int maxTree[4 * NUMBER];

int minInit(int start, int end, int node) {
    if(start == end) {
        minTree[node] = a[start];
        return minTree[node];
    }

    int mid = (start + end) / 2;

    minTree[node] = min(minInit(start, mid, node * 2), minInit(mid + 1, end, node * 2 + 1));

    return minTree[node];
}

int maxInit(int start, int end, int node) {
    if(start == end) {
        maxTree[node] = a[start];
        return maxTree[node];
    }

    int mid = (start + end) / 2;

    maxTree[node] = max(maxInit(start, mid, node * 2), maxInit(mid + 1, end, node * 2 + 1));

    return maxTree[node];
}

void getMinMax(int start, int end, int node, int left, int right) {
    // 범위 밖에 있는 경우
    if(left > end || right < start) {
        return;
    }

    // 범위 안에 있는 경우
    if(left <= start && end <= right) {
        ans_min = min(ans_min, minTree[node]);
        ans_max = max(ans_max, maxTree[node]);
        return;
    }

    int mid = (start + end) / 2;
    
    getMinMax(start, mid, node * 2, left, right);
    getMinMax(mid + 1, end, node * 2 + 1, left, right);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    minInit(0, n - 1, 1);
    maxInit(0, n - 1, 1);

    for(int i = 0; i < m; i++) {
        int a, b;

        ans_min = MAX;
        ans_max = MIN;

        cin >> a >> b;

        getMinMax(0, n - 1, 1, a - 1, b - 1);

        cout << ans_min << " " << ans_max << "\n";
    }

    return 0;
}