#include <string>
#include <vector>

using namespace std;

int accSum[1010][1010];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int N = board.size();
    int M = board[0].size();
    
    for(int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        
        if(type == 1) {
            degree *= -1;
        }
        
        accSum[r1][c1] += degree;
        accSum[r2 + 1][c1] += -degree;
        accSum[r1][c2 + 1] += -degree;
        accSum[r2 + 1][c2 + 1] += degree;
    }
    
    // 행 누적합
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < M; j++) {
            accSum[i][j] += accSum[i][j - 1];
        }
    }
    
    // 열 누적합
    for(int j = 0; j < M; j++) {
        for(int i = 1; i < N; i++) {
            accSum[i][j] += accSum[i - 1][j];
        }
    }
    
    // board와 더하기
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            board[i][j] += accSum[i][j];
            
            if(board[i][j] > 0) {
                answer++;
            }
        }
    }
    
    return answer;
}