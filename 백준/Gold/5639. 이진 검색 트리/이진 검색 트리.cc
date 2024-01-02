#include <iostream>

using namespace std;

int tree[10000];
int cnt = 0;

void postorder(int start, int end) {
    int idx = start + 1;
    int root = tree[start];

    if(start > end) {
        return;
    } else if(start == end) {
        cout << root << "\n";
        return;
    }

    while(tree[idx] < root && idx < cnt) {
        idx++;
    }

    postorder(start + 1, idx - 1);
    postorder(idx, end);
    cout << root << "\n";
}

int main(void) {
    int n;

    while(cin >> n) {
        tree[cnt++] = n;
    }

    postorder(0, cnt - 1);

    return 0;
}