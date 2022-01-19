#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int max_n = 1501;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1}; 
int visited_swan[max_n][max_n], visited[max_n][max_n], R, C, day, swanY, swanX;
char _map[max_n][max_n];
bool isSwanMeet;
queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
string s;

void water_melting(){
    while(waterQ.size()){
        int y = waterQ.front().first;
        int x = waterQ.front().second;  
        waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited[ny][nx])continue;
            if(_map[ny][nx] == 'X'){
                visited[ny][nx] = 1; 
                water_tempQ.push({ny, nx});
                _map[ny][nx] = '.'; 
            } 
        }
    }
}
void move_swan(){
    while(swanQ.size()){
        int y = swanQ.front().first;
        int x = swanQ.front().second;  
        swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= R || nx < 0 || nx >= C || visited_swan[ny][nx])continue;
            if(_map[ny][nx] == '.')swanQ.push({ny, nx});
            else if(_map[ny][nx] == 'X') swan_tempQ.push({ny, nx});
            else if(_map[ny][nx] == 'L'){isSwanMeet = true; return;}
            visited_swan[ny][nx] = 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C;
    for(int i = 0; i < R; i++){
        cin >> s;
        for(int j = 0; j < C; j++){
            _map[i][j] = s[j];
            if(_map[i][j] == 'L'){swanY = i; swanX = j;}
            if(_map[i][j] == '.' || _map[i][j] == 'L')visited[i][j] = 1, waterQ.push({i, j});
        }
    } 
    swanQ.push({swanY, swanX}); 
    visited_swan[swanY][swanX] = 1; 
    while(!isSwanMeet){ 
        move_swan(); 
        if(isSwanMeet) break;
        water_melting();
        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        while(water_tempQ.size()) water_tempQ.pop();
        while(swan_tempQ.size()) swan_tempQ.pop();
        day++;
    }
    cout << day << "\n";

    return 0;
}
