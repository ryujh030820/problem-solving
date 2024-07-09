#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s) {
        answer.push_back(-1);
        return answer;
    }
    
    int minValue = s / n;
    int modValue = s % n;
    
    for(int i = 0; i < n; i++) {
        answer.push_back(minValue);
    }
    
    for(int i = answer.size() - 1; i >= 0 && modValue > 0; i--) {
        answer[i]++;
        modValue--;
    }
    
    return answer;
}