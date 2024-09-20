#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> graph[100001];
int d[100001];
int INF = 100000000;

void dijkstra(int start) {
    d[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        if(d[current] < distance) {
            continue;
        }
        
        for(int i = 0; i < graph[current].size(); i++) {
            int next = graph[current][i];
            int nextDistance = distance + 1;
            
            if(nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push({-nextDistance, next});
            }
        }
    }
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    
    for(int i = 0; i < roads.size(); i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dijkstra(destination);
    
    for(int i = 0; i < sources.size(); i++) {
        if(d[sources[i]] == INF) {
            answer.push_back(-1);
        } else {
            answer.push_back(d[sources[i]]);   
        }
    }    
    
    return answer;
}