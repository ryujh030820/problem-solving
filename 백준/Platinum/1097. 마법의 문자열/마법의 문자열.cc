#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string words[8];
bool visited[8];
int ans, n, k;
map<string, bool> check;

vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;

    for(int i = 1; i < patternSize; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j-1];
        }

        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

int KMP(string parent, string pattern) {
    int cnt = 0;

    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;

    for(int i = 0; i < parentSize; i++) {
        while(j > 0 && parent[i] != pattern[j]) {
            j = table[j - 1];
        }
        if(parent[i] == pattern[j]) {
            if(j == patternSize - 1) {
                cnt++;
                j = table[j];
            } else {
                j++;
            }
        }
    }

    return cnt;
}

void solution(int a, int cnt, string s) {
    s += words[a];

    if(cnt == n - 1) {
        string temp = s + s;

        if(KMP(temp, s) == k + 1) {
            ans++;
        }
        
        return;
    }

    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            visited[i] = true;
            solution(i, cnt + 1, s);
            visited[i] = false;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cin >> k;

    for(int i = 0; i < n; i++) {
        fill(visited, visited + n, false);
        visited[i] = true;
        solution(i, 0, "");
    }

    cout << ans;

    return 0;
}