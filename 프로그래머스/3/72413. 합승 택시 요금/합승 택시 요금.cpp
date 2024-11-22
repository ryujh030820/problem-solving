#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int>> station[201];
int graph[201][201];
int INF = 1e9;

void floyd_warshall(int n) {
    for(int k = 1; k <= n; k++) { // 거쳐가는 노드
        for(int i = 1; i <= n; i++) { // 출발 노드
            for(int j = 1; j <= n; j++) { // 목적지 노드
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;      
            }
        }
    }
    
    for(int i = 0; i < fares.size(); i++) {
        for(int j = 0; j < 3; j++) {
            int c = fares[i][0];
            int d = fares[i][1];
            int f = fares[i][2];
            
            graph[c][d] = f;
            graph[d][c] = f;
        }
    }
    
    floyd_warshall(n);
    
    // 합승을 안하는 경우
    answer = graph[s][a] + graph[s][b];
    
    // i번까지 합승하는 경우를 고려
    for(int i = 1; i <= n; i++) {
        if(graph[s][i] != INF && graph[i][a] != INF && graph[i][b] != INF) {
            answer = min(answer, graph[s][i] + graph[i][a] + graph[i][b]);   
        }
    }
    
    return answer;
}