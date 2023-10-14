#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int arr[41];
int n, s;
long long ans = 0;

map<int, int> subsum;

void left(int idx, int cnt) {
    if(idx == n/2) {
        subsum[cnt]++;
        
        return;
    }

    left(idx+1, cnt); // arr[idx] 값을 더하지 않는 경우
    left(idx+1, cnt+arr[idx]); // arr[idx] 값을 더하는 right
}

void right(int idx, int cnt) {
    if(idx == n) {
        ans += subsum[s-cnt];
        
        return;
    }

    right(idx+1, cnt); // arr[idx] 값을 더하지 않는 경우
    right(idx+1, cnt+arr[idx]); // arr[idx] 값을 더하는 경우
}

int main(void) {
    int i, j;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    left(0, 0);
    right(n/2, 0);

    if(s == 0) {
        cout << ans-1;
    }
    else {
        cout << ans;
    }

    return 0;
}