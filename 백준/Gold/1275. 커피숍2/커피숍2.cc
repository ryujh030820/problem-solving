#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int n, q;
vector<long long> a;
long long tree[4 * MAX];

long long init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = a[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) {
        return 0;
    }
    if(left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long dif) {
    // 범위 밖에 있는 경우
    if(index < start || index > end) {
        return;
    }
    tree[node] += dif;
    if(start == end) {
        return;
    }
    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, dif);
    update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int num;

        cin >> num;

        a.push_back(num);
    }

    init(0, a.size() - 1, 1);

    for(int i = 0; i < q; i++) {
        int x, y, A, B;

        cin >> x >> y >> A >> B;

        if(x > y) {
            swap(x, y);
        }

        cout << sum(0, a.size() - 1, 1, x - 1, y - 1) << "\n";

        update(0, a.size() - 1, 1, A - 1, B - a[A - 1]);
        a[A - 1] = B;
    }

    return 0;
}