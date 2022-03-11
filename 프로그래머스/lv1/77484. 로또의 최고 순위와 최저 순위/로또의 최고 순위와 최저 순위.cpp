#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int hit = 0;
    int none = 0;
    
    for(auto& num: win_nums) {
        for(int i = 0; i < lottos.size(); i++) {
            if(num == lottos[i]) hit++;
        }
    }
    
    for (auto& num: lottos) {
        if(num == 0) none++;
    }
    
    int max_hit = hit + none;
    int min_hit = hit;
    
    if(min_hit < 2) min_hit = 1;
    if(max_hit == 0) max_hit = 1;
    answer.push_back(7-max_hit);
    answer.push_back(7-min_hit);
    return answer;
}