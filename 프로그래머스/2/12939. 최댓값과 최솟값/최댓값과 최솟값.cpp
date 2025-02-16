#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    string token;
    
    int min = 1000000000, max = -1000000000;
    
    while(ss >> token) {
        int number = stoi(token);
        
        if(number < min) {
            min = number;
        }
        
        if(number > max) {
            max = number;
        }
    }
    
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);
    
    return answer;
}