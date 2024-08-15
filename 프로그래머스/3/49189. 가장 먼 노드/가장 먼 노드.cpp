#include <string>
#include <vector>
#include <queue>

using namespace std;

int d[20001];
int INF = 100000000;
vector<int> graph[20001];

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start}); // 거리, 정점 순 (거리는 음수로 저장, 최대힙이 디폴트이므로)
    
    while(!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if(d[current] < distance) {
            continue;
        }
        
        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            // 선택된 노드를 인접 노드로 거쳐서 가는 비용
            int nextDistance = distance + 1;
            
            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxDistance = -1;
    
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    
    for(int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dijkstra(1);
    
    for(int i = 1; i <= n; i++) {
        if(d[i] > maxDistance) {
            maxDistance = d[i];
            answer = 1;
        } else if(d[i] == maxDistance) {
            answer++;
        }
    }
    
    return answer;
}