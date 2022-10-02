#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    
    for(int h = 3; ; h++) {
        int w = sum / h;
        if((w-2)*(h-2) == yellow){
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    return answer;
}