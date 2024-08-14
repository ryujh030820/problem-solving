#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int getParent(int set[], int x) {
    if(set[x] == x) {
        return x;
    }
    
    return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    
    if(a < b) {
        set[b] = a;
    } else {
        set[a] = b;
    }
}

bool find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);
    
    if(a == b) {
        return true;
    } else {
        return false;
    }
}

int solution(int n, vector<vector<int>> costs) {
    int set[100];
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    
    for(int i = 0; i < 100; i++) {
        set[i] = i;
    }
    
    for(int i = 0; i < costs.size(); i++) {
        if(!find(set, costs[i][0], costs[i][1])) {
            answer += costs[i][2];
            unionParent(set, costs[i][0], costs[i][1]);
        }
    }
    
    return answer;
}