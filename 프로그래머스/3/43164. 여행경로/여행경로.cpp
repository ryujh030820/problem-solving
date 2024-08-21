#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> route;
bool isFind = false;
bool isUsed[1000000]; 

void DFS(string airport, vector<vector<string>> tickets, vector<string>& answer) {
    if(route.size() == tickets.size() + 1) {
        isFind = true;
        answer = route;
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++) {
        if(tickets[i][0] == airport) {
            if(!isUsed[i]) {
                isUsed[i] = true;
                route.push_back(tickets[i][1]);
                DFS(tickets[i][1], tickets, answer);
                
                if(!isFind) {
                    isUsed[i] = false;
                    route.pop_back();
                }
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end());
    
    route.push_back("ICN");
    
    DFS("ICN", tickets, answer);
    
    return answer;
}