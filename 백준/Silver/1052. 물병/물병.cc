#include <iostream>
#include <cmath>

using namespace std;

int n, k, ans;

int main(void) {
    int temp;

    cin >> n >> k;

    temp = n;

    while(1) {
        int i = 0, cnt = 0;

        while((temp >> i) != 0) {
            if((temp >> i) & 1 == 1) {
                cnt++;
            }

            i++;
        }

        if(cnt <= k) {
            ans = temp - n;
            break;
        } else {
            temp++;
        }
    }

    cout << ans;

    return 0;
}