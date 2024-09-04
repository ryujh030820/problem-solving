#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> purse(vector<int> v, int num) {
    for(int i = 0; i < v.size(); i++) {
        v[i] = v[i] * num;
        num *= -1;
    }
    
    return v;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    vector<int> seq1 = purse(sequence, 1); // [1, -1, 1, -1 ...] 펄스 수열이 적용된 경우
    vector<int> seq2 = purse(sequence, -1); // [-1, 1, -1, 1 ...] 펄스 수열이 적용된 경우
    long long DP1[500001]; // seq1에서 인덱스 i번째 원소까지 탐색했을 때의 최댓값
    long long DP2[500001]; // seq2에서 인덱스 i번째 원소까지 탐색했을 때의 최댓값
    
    DP1[0] = (long long)seq1[0];
    DP2[0] = (long long)seq2[0];
    
    for(int i = 1; i < seq1.size(); i++) {
        DP1[i] = max(DP1[i - 1] + (long long)seq1[i], (long long)seq1[i]);
        
        answer = max(answer, DP1[i]);
    }
    
    for(int i = 1; i < seq2.size(); i++) {
        DP2[i] = max(DP2[i - 1] + (long long)seq2[i], (long long)seq2[i]);
        
        answer = max(answer, DP2[i]);
    }
    
    if(sequence.size() == 1) {
        answer = abs(sequence[0]);
    }
    
    return answer;
}