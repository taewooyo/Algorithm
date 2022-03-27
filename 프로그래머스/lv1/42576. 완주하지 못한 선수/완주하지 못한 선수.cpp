#include <bits/stdc++.h>

using namespace std;
map<string, int> mp;
string solution(vector<string> participant, vector<string> completion) {

    for(string a : participant){
        mp[a]++;
    }
    for(string a : completion){
        mp[a]--;
    }
    for(string a : participant){
        if(mp[a]==1) return a;
    }
}