#include <string>
#include <vector>

using namespace std;

int INF = 2e9;
int leftMinArray[1000000];
int rightMinArray[1000000];
int leftMin = INF;
int rightMin = INF;

int solution(vector<int> a) {
    int answer = 0;
    
    // 해당 풍선보다 더 작은 풍선이 최대 1개까지만 가능
    // 양 옆으로 나누어 무조건 더 큰 애들만 터뜨려서 비교 대상 정함
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < leftMin) {
            leftMin = a[i];
        }
        
        leftMinArray[i] = leftMin;
    }
    
    for(int i = a.size() - 1; i >= 0; i--) {
        if(a[i] < rightMin) {
            rightMin = a[i];
        }
        
        rightMinArray[i] = rightMin;
    }
    
    for(int i = 0; i < a.size(); i++) {
        if(i == 0 || i == a.size() - 1) {
            answer++;   
        } else {
            if(a[i] < leftMinArray[i - 1] || a[i] < rightMinArray[i + 1]) {
                answer++;
            }
        }
    }
    
    return answer;
}