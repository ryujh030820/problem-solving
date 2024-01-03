#include <iostream>
#include <stack>

using namespace std;

string a, b, temp = "", ans = "";
stack<char> st;

int main(void) {
    cin >> a;

    cin >> b;

    char last = b[b.length() - 1];

    for(int i = 0; i < a.length(); i++) {
        st.push(a[i]);

        if(a[i] == last) {
            int idx = b.length() - 1;

            while(idx >= 0) {
                if(!st.empty() && st.top() == b[idx]) {
                    temp += b[idx];
                    st.pop();
                    idx--;
                } else {
                    break;
                }
            }

            if(idx >= 0) {
                for(int i = temp.length() - 1; i >= 0; i--) {
                    st.push(temp[i]);
                }
            }

            temp = "";
        }
    }

    if(!st.empty()) {
        while(!st.empty()) {
            char c = st.top();

            ans += c;

            st.pop();
        }

        for(int i = ans.length() - 1; i >= 0; i--) {
            cout << ans[i];
        }
    } else {
        cout << "FRULA";
    }

    return 0;
}