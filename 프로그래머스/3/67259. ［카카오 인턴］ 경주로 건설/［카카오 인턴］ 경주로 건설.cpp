#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
bool visited[25][25][4];

int solution(vector<vector<int>> board) {
    int answer = 0;
    priority_queue<pair<pair<int, int>, pair<int, int>>> q; // 비용, 방향, row, col 순, 최소 비용을 지닌 도로가 아닌 다른 도로가 선택될 수 있으므로 힙 자료구조 사용
    
    q.push({{0, 0}, {0, 0}});
    q.push({{0, 1}, {0, 0}});
    q.push({{0, 2}, {0, 0}});
    q.push({{0, 3}, {0, 0}});
    
    while(!q.empty()) {
        int expense = -q.top().first.first;
        int direction = q.top().first.second;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();
        
        if(visited[row][col][direction]) {
            continue;
        }
        
        visited[row][col][direction] = true;
        
        if(row == board.size() - 1 && col == board.size() - 1) {
            answer = expense;
            break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nextRow = row + dy[i];
            int nextCol = col + dx[i];
            
            if(nextRow >= 0 && nextCol >= 0 && nextRow < board.size() && nextCol < board.size() && board[nextRow][nextCol] == 0) {
                int newExpense;
                
                if(i == direction) {
                    newExpense = expense + 100;
                } else {
                    newExpense = expense + 600;
                }
                
                q.push({{-newExpense, i}, {nextRow, nextCol}});
            }
        }
    }
    
    return answer;
}