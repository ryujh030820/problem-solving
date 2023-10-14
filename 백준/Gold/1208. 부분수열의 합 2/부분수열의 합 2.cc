#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[41];
int n, s;
long long ans = 0;

vector<int> l;
vector<int> r;

void left(int idx, int cnt) {
    if(idx == n/2) {
        l.push_back(cnt);
        
        return;
    }

    left(idx+1, cnt); // arr[idx] 값을 더하지 않는 경우
    left(idx+1, cnt+arr[idx]); // arr[idx] 값을 더하는 right
}

void right(int idx, int cnt) {
    if(idx == n) {
        r.push_back(cnt);
        
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

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    i = 0;
    j = r.size()-1;

    while(i < l.size() && j >= 0) {
        int lv = l[i];
        int rv = r[j];
        int sum = lv + rv;

        if(sum == s) {
            long long lc = 0, bc = 0;

            while(i < l.size() && lv == l[i]) {
                lc++;
                i++;
            }

            while(j >= 0 && rv == r[j]) {
                bc++;
                j--;
            }

            ans += lc*bc;
        }
        else if(sum < s) {
            i++;
        }
        else {
            j--;
        }
    }

    if(s == 0) {
        ans--;
    }

    cout << ans;

    return 0;
}