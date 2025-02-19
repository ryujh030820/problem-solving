#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    if(a[0] > b[0]) {
        return true;
    } else if(a[0] == b[0]) {
        return a[1] < b[1];
    } else {
        return false;
    }
}

int solution(vector<vector<int>> scores) {
    int answer = 1;
    int targetA = scores[0][0];
    int targetB = scores[0][1];
    int targetScore = targetA + targetB;
    int maxB = -1;
    
    sort(scores.begin(), scores.end(), compare);
    
    for(int i = 0; i < scores.size(); i++) {
        int a = scores[i][0];
        int b = scores[i][1];
        
        if(b >= maxB) {
            maxB = b;
            
            if(a + b > targetScore) {
                answer++;
            }
        } else if(b < maxB) {
            if(a == targetA && b == targetB) { // 만약 그게 완호인 경우
                answer = -1;
                break;
            }
        }
    }
    
    return answer;
}