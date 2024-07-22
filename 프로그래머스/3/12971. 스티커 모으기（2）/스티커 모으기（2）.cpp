#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP1[100000]; // 첫번째 스티커를 뗀 경우
int DP2[100000]; // 첫번째 스티커를 떼지 않은 경우

int solution(vector<int> sticker)
{
    int answer = 0;
    
    if(sticker.size() == 1) {
        answer = sticker[0];
        return answer;
    }
    
    DP1[0] = sticker[0];
    DP1[1] = sticker[0];
    
    for(int i = 2; i < sticker.size() - 1; i++) {
        DP1[i] = max(DP1[i - 2] + sticker[i], DP1[i - 1]);
    }
    
    DP1[sticker.size() - 1] = DP1[sticker.size() - 2];
    
    DP2[0] = 0;
    DP2[1] = sticker[1];
    
    for(int i = 2; i < sticker.size(); i++) {
        DP2[i] = max(DP2[i - 2] + sticker[i], DP2[i - 1]);
    }
    
    answer = max(DP1[sticker.size() - 1], DP2[sticker.size() - 1]);

    return answer;
}