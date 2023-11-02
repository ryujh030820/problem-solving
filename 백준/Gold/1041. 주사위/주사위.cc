#include <iostream>
#include <algorithm>

using namespace std;

long long dice[6];
long long n, diceMin = 51, diceMax, twoFace = 101, threeFace = 151;
long long ans;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < 6; i++) {
        cin >> dice[i];

        diceMin = min(diceMin, dice[i]);
        diceMax = max(diceMax, dice[i]);
    }
    
    if(n > 1) {
        ans += diceMin * ((n - 2) * (n - 2) * 5 + 4 * (n - 2));

        // twoFace 구하기

        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                if(i != j && i + j != 5) {
                    twoFace = min(twoFace, dice[i] + dice[j]);
                }
            }
        }

        ans += twoFace * ((n - 2) * 8 + 4);

        // threeFace 구하기

        threeFace = min(threeFace, dice[0] + dice[1] + dice[3]);
        threeFace = min(threeFace, dice[0] + dice[3] + dice[4]);
        threeFace = min(threeFace, dice[1] + dice[3] + dice[5]);
        threeFace = min(threeFace, dice[3] + dice[4] + dice[5]);
        threeFace = min(threeFace, dice[0] + dice[1] + dice[2]);
        threeFace = min(threeFace, dice[0] + dice[2] + dice[4]);
        threeFace = min(threeFace, dice[1] + dice[2] + dice[5]);
        threeFace = min(threeFace, dice[2] + dice[4] + dice[5]);

        ans += threeFace * 4;
    } else {
        for(int i = 0; i < 6; i++) {
            ans += dice[i];
        }

        ans -= diceMax;
    }

    cout << ans;

    return 0;
}