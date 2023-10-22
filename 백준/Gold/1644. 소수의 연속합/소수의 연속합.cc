#include <iostream>
#include <vector>

using namespace std;

int n;
bool check[4000001];
vector<int> primeNum;

void getPrimeNumber() {
    for(int i = 2; i * i <= 4000000; i++) {
        if(check[i] == true) {
            continue;
        }

        for(int j = 2 * i; j <= 4000000; j += i) {
            check[j] = true;
        }
    }

    for(int i = 2; i <= 4000000; i++) {
        if(check[i] == false) {
            primeNum.push_back(i);
        }
    }
}

int main(void) {
    int cnt = 0;

    cin >> n;

    getPrimeNumber();

    for(int i = 0; i < primeNum.size(); i++) {
        int sum = 0;

        for(int j = i; j < primeNum.size(); j++) {
            sum += primeNum[j];

            if(sum == n) {
                cnt++;
            }
            else if(sum > n) {
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}