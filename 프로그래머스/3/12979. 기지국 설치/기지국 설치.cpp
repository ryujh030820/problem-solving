#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    for(int i = 0; i < stations.size(); i++) {
        if(i == 0) {
            if(stations[i] - w - 1 > 0) {
                answer += (stations[i] - w - 1 + 2 * w) / (2 * w + 1);
            }   
        } else {
            int prevStation = stations[i - 1];
            
            answer += (stations[i] - w - 1 - prevStation - w + 2 * w) / (2 * w + 1);
        }
    }
    
    // 마지막 기지국으로부터 전파가 도달하지 못한 아파트들 계산
    int lastStation = stations[stations.size() - 1];
    
    if(lastStation + w < n) {
        answer += (n - lastStation - w + 2 * w) / (2 * w + 1);
    }

    return answer;
}