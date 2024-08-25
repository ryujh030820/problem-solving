#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int sum = 0;
    int time = 0;
    int cnt = 0;
    priority_queue<pair<int, int>> pq;
    
    while(cnt < jobs.size()) {
        for(int i = 0; i < jobs.size(); i++) {
            if(jobs[i][0] <= time) {
                pq.push({-jobs[i][1], jobs[i][0]});
                jobs[i][0] = 999999;
            }
        }
        
        if(!pq.empty()) {
            int duration = -pq.top().first;
            int requestTime = pq.top().second;
            pq.pop();

            time += duration;
            sum += time - requestTime;
            cnt++;   
        } else {
            time++;
        }
    }
        
    answer = sum / jobs.size();
    
    return answer;
}