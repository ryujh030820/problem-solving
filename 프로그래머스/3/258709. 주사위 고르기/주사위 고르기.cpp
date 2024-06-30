#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void getDiceSum(vector<vector<int>> dice, vector<int> diceIdx, vector<int>* diceSum, int n, int cnt, int sum) {
    if(cnt == n / 2) {
        (*diceSum).push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++) {
        getDiceSum(dice, diceIdx, diceSum, n, cnt + 1, sum + dice[diceIdx[cnt]][i]);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int MAX = -1;
    vector<int> answer;
    vector<int> v;
    vector<int> visit;
    
    for(int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    
    for(int i = 1; i <= n / 2; i++) {
        visit.push_back(0);
    }
    
    for(int i = 1; i <= n / 2; i++) {
        visit.push_back(1);
    }
    
    do {
        int sum = 0;
        vector<int> Aidx, Asum;
        vector<int> Bidx, Bsum;
        
        for(int i = 0; i < v.size(); i++) {
            if(visit[i] != 0) {
                Aidx.push_back(i); // A가 뽑은 주사위들의 index
            } else {
                Bidx.push_back(i); // B가 뽑은 주사위들의 index
            }
        }
        
        getDiceSum(dice, Aidx, &Asum, n, 0, 0);
        getDiceSum(dice, Bidx, &Bsum, n, 0, 0);
        
        sort(Asum.begin(), Asum.end());
        sort(Bsum.begin(), Bsum.end());
        
        for(int i = 0; i < Asum.size(); i++) {
            sum += lower_bound(Bsum.begin(), Bsum.end(), Asum[i]) - Bsum.begin();
        }
        
        if(sum > MAX) {
            MAX = sum;
            
            for(int i = 0; i < n / 2; i++) {
                if(answer.size() != n / 2) {
                    answer.push_back(Aidx[i] + 1);
                } else {
                    answer[i] = Aidx[i] + 1;   
                }
            }
        }
    } while(next_permutation(visit.begin(), visit.end())); // 조합 구하는 로직
    
    return answer;
}