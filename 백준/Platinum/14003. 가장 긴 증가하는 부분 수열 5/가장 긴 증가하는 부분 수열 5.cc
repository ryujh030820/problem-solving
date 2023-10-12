#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v = {1001};
vector<int> lis;
vector<int> ans;
vector<int> backtrace;

int main(void) {
    int n;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0; i<n; i++) {
        int input;

        cin >> input;

        lis.push_back(input);

        if(input > v.back()) {
            v.push_back(input);
            backtrace.push_back(v.size() - 1);
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), input) - v.begin();

            v[idx] = input;
            backtrace.push_back(idx);
        }
    }

    int temp = v.size()-1;

    for(int i=backtrace.size()-1; i>=0; i--) {
        if(backtrace[i] == temp) {
            temp--;
            ans.push_back(lis[i]);
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}