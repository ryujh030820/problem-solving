#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    char op;
    int num, cnt = 0;
    vector<int> answer;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < operations.size(); i++) {
        sscanf(operations[i].c_str(), "%c %d", &op, &num);
        
        if(op == 'I') {
            maxHeap.push(num);
            minHeap.push(num);
            cnt++;
        } else {
            if(num == 1) {
                if(maxHeap.size() > 0) {
                    maxHeap.pop();   
                    cnt--;
                }
            } else {
                if(minHeap.size() > 0) {
                    minHeap.pop();
                    cnt--;
                }
            }
        }
        
        if(cnt == 0) {
            while(maxHeap.size() > 0) {
                maxHeap.pop();
            }
            
            while(minHeap.size() > 0) {
                minHeap.pop();
            }
        }
    }
    
    if(cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }
    
    return answer;
}