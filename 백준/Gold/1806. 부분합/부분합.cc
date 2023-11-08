#include <iostream>
#include <algorithm>
#define INT_MAX 2147483647

using namespace std;

int n, s;
int arr[100001];

int main(void) {
    int start = 1;
    int end = 1;
    int ans = INT_MAX;
    
    cin >> n >> s;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int sum = arr[1];

    while(start <= end && end <= n) {
        if(sum >= s) {
            ans = min(ans, end - start + 1);
        }

        if(sum < s) {
            end++;
            sum += arr[end];
        } else {
            sum -= arr[start];
            start++;
        }
    }
    
    if(ans == INT_MAX) {
        cout << 0;
    } else {
        cout << ans;
    }

    return 0;
}