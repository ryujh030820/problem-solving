#include <iostream>
#include <algorithm>

#define NUMBER 1000000
#define endl "\n"

using namespace std;

int n, m;
long long A[NUMBER];
long long tree[4 * NUMBER];

// start: 시작 인덱스, end: 끝 인덱스
// left, right : 구간 합을 구하고자 하는 범위
long long sum(int start, int end, int node, int left, int right) {
    // 범위 밖에 있는 경우
    if(left > end || right < start) {
        return 0;
    }
    // 범위 안에 있는 경우
    if(left <= start && end <= right) {
        return tree[node];
    }
    // 그렇지 않다면 두 부분으로 나누어 합을 구하기
    int mid = (start + end) / 2;
    return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

// start: 시작 인덱스, end: 끝 인덱스
// index: 구간 합을 수정하고자 하는 노드
// dif: 수정할 값
void update(int start, int end, int node, int index, int dif) {
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

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int op, a, b;

        cin >> op >> a >> b;

        if(op == 0) {
            if(a > b) {
                swap(a, b);
            }

            cout << sum(1, n, 1, a, b) << endl;
        } else if(op == 1) {
            update(1, n, 1, a, b - A[a]);
            A[a] = b;
        }
    }

    return 0;
}