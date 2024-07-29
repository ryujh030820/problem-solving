#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> mapping(8);
set<string> id_list;

bool visited[6];

bool isFine(vector<string> user_id, vector<string> banned_id, int userIdx, int banIdx) {
    if(user_id[userIdx].size() != banned_id[banIdx].size()) {
        return false;
    }
    
    for(int i = 0; i < banned_id[banIdx].size(); i++) {
        if(user_id[userIdx][i] != banned_id[banIdx][i] && banned_id[banIdx][i] != '*') {
            return false;
        }
    }
    
    return true;
}

void DFS(int n, int size, int cnt, vector<int> idx) {
    if(cnt == size) {
        string str = "";
        
        sort(idx.begin(), idx.end());
        
        for(int i = 0; i < idx.size(); i++) {
            str += to_string(idx[i]);
        }
        
        id_list.insert(str);
        
        return;
    }
    
    for(int i = 0; i < mapping[n].size(); i++) {
        if(visited[mapping[n][i]] == false) {
            vector<int> newIdx = idx;
            newIdx.push_back(mapping[n][i]);
        
            visited[mapping[n][i]] = true;
            DFS(n + 1, size, cnt + 1, newIdx); 
            visited[mapping[n][i]] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<int> idx;
    
    // {0, 2}, {0, 2}, {3, 4}

    for(int i = 0; i < banned_id.size(); i++) {
        for(int j = 0; j < user_id.size(); j++) {
            if(isFine(user_id, banned_id, j, i)) {
                mapping[i].push_back(j);
            }
        }
    }
    
    DFS(0, banned_id.size(), 0, idx);
    
    answer = id_list.size();
    
    return answer;
}