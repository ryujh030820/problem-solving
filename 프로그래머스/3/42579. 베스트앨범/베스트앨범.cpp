#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> music;
    map<string, map<int, int>> musicList;
    
    for(int i = 0; i < genres.size(); i++) {
        music[genres[i]] += plays[i];
        musicList[genres[i]][i] = plays[i];
    }
    
    while(music.size() > 0) {
        string genre;
        int max = 0;
        
        for(auto mu : music) {
            if(mu.second > max) {
                max = mu.second;
                genre = mu.first;
            }
        }
        
        for(int i = 0; i < 2; i++) {
            int val = 0;
            int idx = -1;
            
            for(auto ml : musicList[genre]) {
                if(ml.second > val) {
                    val = ml.second;
                    idx = ml.first;
                }
            }
            
            // 노래가 0~1곡밖에 없는 경우
            if(idx == -1) {
                break;
            }
            
            answer.push_back(idx);
            musicList[genre].erase(idx);
        }
        
        // map에서 사용한 genre 삭제
        music.erase(genre);
    }
    
    return answer;
}