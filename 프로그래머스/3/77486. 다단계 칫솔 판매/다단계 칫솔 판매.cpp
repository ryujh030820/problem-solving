#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, int> members;
vector<int> graph[10001];

void DFS(int a, int profit, vector<int>& answer) {
    if(profit * 0.1 >= 1 && graph[a].size() > 0) {
        int distribution = profit * 0.1;
        int ownProfit = profit - distribution;
        answer[a] += ownProfit;
        
        for(int i = 0; i < graph[a].size(); i++) {
            if(graph[a][i] != -1) {
                DFS(graph[a][i], distribution, answer);   
            }
        }
    } else {
        answer[a] += profit;
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);
    
    for(int i = 0; i < enroll.size(); i++) {
        members[enroll[i]] = i;
    }
    
    for(int i = 0; i < referral.size(); i++) {
        if(referral[i] == "-") {
            graph[i].push_back(-1);
        } else {
            graph[i].push_back(members[referral[i]]);;
        }
    }
    
    for(int i = 0; i < seller.size(); i++) {
        string sellerName = seller[i];
        int profit = amount[i] * 100;
        
        DFS(members[sellerName], profit, answer);
    }
    
    return answer;
}