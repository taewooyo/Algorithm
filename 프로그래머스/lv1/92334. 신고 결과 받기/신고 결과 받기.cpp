#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> idx_map;
    map<string, set<string>> report_map;
        
    for (auto i = 0; i < id_list.size(); i++) {
        idx_map[id_list[i]] = i;
    }
    
    stringstream ss;
    for(auto rep: report) {
        ss.str(rep);
        string a, b;
        ss >> a >> b;
        report_map[b].insert(a);
        ss.clear();
    }
    
    for(auto it: report_map) {
        if (it.second.size() >= k) {
            for(auto set_it: it.second) {
                int idx = idx_map[set_it];
                answer[idx]++;
            }
        }
    }
    return answer;
}