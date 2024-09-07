#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int palindrome(string s, int left, int right) {
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    
    return right - left - 1;
}

int solution(string s)
{
    int answer=1;
    
    for(int i = s.size() - 1; i >= 0; i--) {
        answer = max(answer, palindrome(s, i, i)); // 홀수인 경우
        answer = max(answer, palindrome(s, i, i + 1)); // 짝수인 경우
    }

    return answer;
}