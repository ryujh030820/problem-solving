#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001

using namespace std;

vector<int> a[MAX];
int inDegree[MAX];
bool checked[MAX];

int n, m;

void topologySort() {
    int result[MAX];
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 1; i <= n; i++) {
        if(inDegree[i] == 0 || inDegree[i] == -1) {
            q.push(i);
        }
    }

    int i = 1;

    while(1) {
        if(q.empty()) {
            break;
        }

        int x = q.top();
        q.pop();

        if(!(inDegree[x] > 0)) {
            result[i] = x;
            checked[x] = true;
            for(int i = 0; i < a[x].size(); i++) {
                int y = a[x][i];

                if(--inDegree[y] == 0) {
                    q.push(y);
                }
            }

            i++;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}

int main(void) {
    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        inDegree[i] = -1;
    }

    for(int i = 0; i < m; i++) {
        int A, B;

        cin >> A >> B;

        a[A].push_back(B);

        if(inDegree[A] == -1) {
            inDegree[A] = 0;
        }
        
        if(inDegree[B] == -1) {
            inDegree[B] = 0;
        }

        inDegree[B]++;
    }

    topologySort();

    return 0;
}