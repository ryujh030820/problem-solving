#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string convertTime(int time) {
    string answer = "";
    
    int hour = time / 60;
    int minute = time % 60;
    
    if(hour < 10) {
        answer += "0";
    }
    
    answer += to_string(hour);
    answer += ":";
    
    if(minute < 10) {
        answer += "0";
    }
    
    answer += to_string(minute);
    
    return answer;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int answerNum = 0;
    vector<int> timeTable;
    vector<vector<int>> bus(10);
    int currentTime = 540, busCount = 0, startIdx = 0; // 09:00 -> 00:00부터 540분이 지남
    
    sort(timetable.begin(), timetable.end());
    
    for(int i = 0; i < timetable.size(); i++) {
        timeTable.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2)));
    }
    
    // 모든 timetable에 존재하는 크루를 버스에 배정
    while(busCount < n) {
        int passengerCount = 0;
        
        busCount++;
        
        for(int i = startIdx; i < timeTable.size(); i++) {
            if(timeTable[i] <= currentTime && passengerCount < m) {
                bus[busCount - 1].push_back(timeTable[i]);
                passengerCount++;
                startIdx = i + 1;
            } else {
                break;
            }
        }
        
        currentTime += t;
    }
    
    // 마지막 버스에 인원이 가득 차있으면, 마지막으로 탄 크루의 시간에서 1을 뺌
    if(bus[busCount - 1].size() == m) {
        answerNum = bus[busCount - 1][m - 1] - 1;
    } else { // 마지막 버스에 인원이 가득 차지 않았을 시, 셔틀이 도착한 시간
        answerNum = currentTime - t;
    }
    
    answer = convertTime(answerNum);
    
    return answer;
}