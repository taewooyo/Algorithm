#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
using namespace std;

int n, k;
int idx;
vector<tuple<int, int, int>> frame; // 추천수, 시간, 번호
vector<int> input;

bool isBlank() {
    if(frame.size() < n) return true;
    return false;
}

void updateFrame(int target) {
    sort(frame.begin(), frame.end());
    frame[0] = make_tuple(1, idx++, target);
}

int isContain(int target) {
    for(int i = 0; i < frame.size(); i++) {
        int vote, times, number;
        tie(vote, times, number) = frame[i];
        if(target == number) {
            return i;
        }
    }
    return -1;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        int number;
        cin >> number;
        input.push_back(number);
    }

    for(int rep = 0; rep < input.size(); rep++) {
        int target = input[rep];

        int check = isContain(target);
        if(check != -1) {
            int vote, times, number;
            tie(vote, times, number) = frame[check];
            frame[check] = make_tuple(vote+1, times, number);
        }
        else {
            bool flag = isBlank();
            if(flag == false) {
                updateFrame(target);
            }
            else {
                frame.push_back(make_tuple(1, idx++, target));
            }
        }
    }

    set<int> s;
    for(int i = 0; i < frame.size(); i++) {
        int number;
        tie(ignore, ignore, number) = frame[i];
        s.insert(number);
    }
    for(auto it: s) cout << it << ' ';
    return 0;
}