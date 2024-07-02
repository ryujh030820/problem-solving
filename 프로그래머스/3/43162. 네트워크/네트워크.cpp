#include <string>
#include <vector>

using namespace std;

void DFS(int pos, int n, vector<vector<int>> computers, vector<bool>& visited) {
    visited[pos] = true;
    
    for(int i = 0; i < n; i++) {
        if(computers[pos][i] == 1) {
            if(visited[i] == false) {
                DFS(i, n, computers, visited);
            }   
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            DFS(i, n, computers, visited);
            answer++;
        }
    }
    
    return answer;
}