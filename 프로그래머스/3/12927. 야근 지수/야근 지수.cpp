#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q;
    
    for(int i = 0; i < works.size(); i++) {
        q.push(works[i]);
    }

    while(n > 0) {
        int work = q.top();
        
        if(work == 0) {
            break;
        }
        
        q.pop();
        work--;
        n--;
        q.push(work);
    }
    
    while(!q.empty()) {
        answer += q.top() * q.top();
        q.pop();
    }
    
    return answer;
}