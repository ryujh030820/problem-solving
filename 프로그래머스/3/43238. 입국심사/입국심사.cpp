#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0, right = 1000000000000000000;
    
    while(left <= right) {
        long long mid = (left + right) / 2;
        long long cnt = 0;
        
        for(int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }

        if(cnt >= n) {
            if(answer == 0) {
                answer = mid;
            } else {
                answer = min(answer, mid);
            }
            
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}