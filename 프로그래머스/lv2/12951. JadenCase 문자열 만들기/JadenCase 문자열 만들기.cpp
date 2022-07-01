#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool isFirst = true;
    
    for (int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            isFirst = true;
            continue;
        }
        if(isFirst) {
            s[i] = toupper(s[i]);
            isFirst = false;
        }
        else {
            s[i] = tolower(s[i]);
            isFirst = false;
        }
    }
    
    return s;
}