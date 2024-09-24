#include <string>
#include <vector>

using namespace std;

int DP[100001];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    DP[0] = 1;
      
    for(int i = 0; i < money.size(); i++) {
        int coin = money[i];
        
        for(int j = coin; j <= n; j++) {
            DP[j] += DP[j - coin] % 1000000007;
        }
    }
    
    answer = DP[n];
    
    return answer;
}