#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    
    for(int i = 1; i < height; i++) {
        for(int j = 0; j < triangle[i].size(); j++) {
            if(j > 0 && j < triangle[i].size() - 1) {
                triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            } else if(j == 0) {
                triangle[i][j] += triangle[i - 1][j];
            } else {
                triangle[i][j] += triangle[i - 1][j - 1];
            }
        }
    }
    
    for(int i = 0; i < triangle[height - 1].size(); i++) {
        answer = max(answer, triangle[height - 1][i]);
    }
    
    return answer;
}