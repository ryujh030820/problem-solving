#include <iostream>
#include <cmath>

#define MAX 1000001

using namespace std;

int n, m, k;

long long tree[MAX];
long long A[MAX];

long long sum(long long i) {
    long long result = 0;
    while(i > 0) {
        result += tree[i];
        i -= (i & -i);
    }

    return result;
}

void update(long long i, long long dif) {
    while(i <= n) {
        tree[i] += dif;
        i += (i & -i);
    }
}

long long getSection(long long start, long long end) {
    return sum(end) - sum(start - 1);
}

int main(void) {

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        long long number;

        cin >> number;

        A[i] = number;
        update(i, number);
    }

    for(int i = 0; i < m + k; i++) {
        long long a, b, c;

        cin >> a >> b >> c;

        if(a == 1) {
            long long diff = c - A[b];
            A[b] = c;
            update(b, diff);
        } else {
            cout << getSection(b, c) << endl;
        }
    }

    return 0;
}