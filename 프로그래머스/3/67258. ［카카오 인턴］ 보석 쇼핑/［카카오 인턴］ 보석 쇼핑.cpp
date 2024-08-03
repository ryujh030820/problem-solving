#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string, int> gemList; // map 정렬 필요 없으므로
set<string> kind;

vector<int> solution(vector<string> gems) {
    // 투포인터 알고리즘, 보석 개수 계산해가며 구간 좁히기
    
    vector<int> answer(2);
    
    int start = 0;
    int end = 0;
    int min = 100001;
    
    for(int i = 0; i < gems.size(); i++) {
        kind.insert(gems[i]);
    }
    
    while(1) {
        for(int i = end; i < gems.size(); i++) { // 구간이 모든 보석을 포함하도록 end를 증가
            gemList[gems[i]]++;
            
            if(gemList.size() == kind.size()) {
                end = i;
                break;
            }
            
            if(i == gems.size() - 1) {
                return answer;
            }
        }
        
        while(gemList[gems[start]] > 1) { // start를 증가시키면서 구간 좁히기
            gemList[gems[start]]--;
            start++;
        }
        
        if(end - start < min) {
            min = end - start; // end - start가 min보다 작으면 min과 answer 업데이트
            answer[0] = start + 1;
            answer[1] = end + 1;
        }
        
        gemList.erase(gems[start]);
        start++;
        end++; // 새로운 구간합을 구하기 위해 start와 end 추가
        
        if(end >= gems.size()) {
            break;
        }
    }
    
    return answer;
}