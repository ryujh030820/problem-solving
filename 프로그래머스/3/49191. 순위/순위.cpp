#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dist[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for(int i = 0; i < results.size(); i++) {
        int winner = results[i][0];
        int loser = results[i][1];
        
        dist[winner][loser] = 1;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dist[i][j] == 0 && dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int row_sum = 0;
        int col_sum = 0;
        
        for(int j = 1; j <= n; j++) {
            int row = dist[i][j];
            int col = dist[j][i];
            
            row_sum += row;
            col_sum += col;
        }
        
        if(row_sum + col_sum == n - 1) {
            answer++;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dist[i][j] << " ";
        }
        
        cout << endl;
    }
    
    return answer;
}