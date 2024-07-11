#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int DP[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    DP[1][1] = 1;
    
    for(int i = 0; i < puddles.size(); i++) {
        DP[puddles[i][1]][puddles[i][0]] = -1;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int a = 0;
            int b = 0;
            
            if(DP[i][j] != -1) {   
                if(DP[i][j - 1] != -1) { // 오른쪽으로 이동한 경우
                    a = DP[i][j - 1];
                }

                if(DP[i - 1][j] != -1) { // 아래로 이동한 경우
                    b = DP[i - 1][j];
                }   
                
                DP[i][j] += (a + b) % 1000000007;
            }
        }
    }
    
    answer = DP[n][m];
    
    return answer;
}