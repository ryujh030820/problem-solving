#include <string>
#include <vector>

using namespace std;

int M, N, B;

// 두 행렬을 더해서 lock이 모두 1이 될 시 true, 아니면 false
bool check(vector<vector<int>> newLock, vector<vector<int>> key, int row, int col) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            newLock[row + i][col + j] += key[i][j];
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(newLock[i + M - 1][j + M - 1] != 1) {
                return false;
            }
        }
    }
    
    return true;
}

// 오른쪽으로 90도 회전
void rotation(vector<vector<int>>& key) {
    vector<vector<int>> newKey(M, vector<int>(M, 0));
    
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            newKey[i][j] = key[M - (j + 1)][i];
        }
    }
    
    key = newKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    M = key.size();
    N = lock.size();
    B = 2 * (M - 1) + N;
    
    vector<vector<int>> newLock(B, vector<int>(B, 0));
    
    // newLock의 중앙에 lock이 위치
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            newLock[i + M - 1][j + M - 1] = lock[i][j];
        }
    }
    
    for(int i = 0; i < 4; i++) {
        rotation(key);
        
        for(int j = 0; j <= B - M; j++) {
            for(int k = 0; k <= B - M; k++) {
                if(check(newLock, key, j, k)) {
                    return answer;
                }
            }
        }
    }
    
    answer = false;
    
    return answer;
}