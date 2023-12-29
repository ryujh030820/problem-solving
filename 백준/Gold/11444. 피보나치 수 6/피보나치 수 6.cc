#include <iostream>

#define MODULAR 1000000007

using namespace std;

long long n;

long long matrix_temp[2][2] = {
    {1, 1},
    {1, 0}
};
long long matrix[2][2] = {
    {1, 0},
    {0, 1}
};

void matrix_mult(long long arr1[2][2], long long arr2[2][2]) {
    long long temp[2][2];

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            temp[i][j] = 0;
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                temp[i][j] += (arr1[i][k] % MODULAR)  * (arr2[k][j] % MODULAR);
            }
        }
    }

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            arr1[i][j] = temp[i][j] % MODULAR;
        }
    }
}

int main(void) {
    cin >> n;

    while(n > 0) {
        if(n % 2 == 1) {
            matrix_mult(matrix, matrix_temp);
        }

        matrix_mult(matrix_temp, matrix_temp);

        n /= 2;
    }

    cout << matrix[1][0];

    return 0;
}