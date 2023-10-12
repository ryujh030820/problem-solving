#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int arr[4][8]; // 2번째 인덱스가 3시 방향, 6번째 인덱스가 9시 방향
bool rotated[5];

void rotateGear(int n, int dir) {
    rotated[n] = true;

    if(n-1 > 0 && rotated[n-1] == false) {
        if(arr[n-2][2] != arr[n-1][6]) {
            rotateGear(n-1, -dir);
        }
    }

    if(n+1 <= 4 && rotated[n+1] == false) {
        if(arr[n][6] != arr[n-1][2]) {
            rotateGear(n+1, -dir);
        }
    }

    if(dir == 1) {
        int temp[8];

        for(int i=0; i<8; i++) {
            if(i == 0) {
                temp[i] = arr[n-1][7];
            }
            else {
                temp[i] = arr[n-1][i-1];
            }
        }

        for(int i=0; i<8; i++) {
            arr[n-1][i] = temp[i];
        }
    }
    else if(dir == -1) {
        int temp[8];

        for(int i=0; i<8; i++) {
            if(i == 7) {
                temp[i] = arr[n-1][0];
            }
            else {
                temp[i] = arr[n-1][i+1];
            }
        }

        for(int i=0; i<8; i++) {
            arr[n-1][i] = temp[i];
        }
    }
}

int main(void) {
    int k, ans = 0;

    for(int i=0; i<4; i++) {
        for(int j=0; j<8; j++) {
            scanf("%1d", &arr[i][j]); // i번째 톱니바퀴 입력 (N극은 0, S극은 1)
        }
    }

    cin >> k;

    for(int i=0; i<k; i++) {
        int n, dir; // dir이 1인 경우 시계 방향, -1인 경우는 반시계 방향

        cin >> n >> dir;

        for(int j=0; j<5; j++) {
            rotated[j] = false;
        }

        rotateGear(n, dir);
    }

    for(int i=0; i<4; i++) {
        if(arr[i][0] == 1) {
            ans += pow(2, i);
        }
    }


    cout << ans;

    return 0;
}