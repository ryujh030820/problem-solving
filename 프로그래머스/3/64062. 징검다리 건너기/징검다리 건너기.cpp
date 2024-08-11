#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 0, right = 200000000;
    
    // n^2보다 적어야 함
    // 이진 탐색 (nlogn)
    while(left <= right) {
        int mid = (left + right) / 2;
        int skipCount = 0;
        bool isPossible = true;
        
        vector<int> tmp(stones);
        
        for(int i = 0; i < tmp.size(); i++) {
            tmp[i] -= mid;
            
            if(tmp[i] < 0) {
                skipCount++;
            } else {
                skipCount = 0;
            }
            
            if(skipCount >= k) {
                isPossible = false;
                break;
            }
        }
        
        if(isPossible) {
            answer = max(answer, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}