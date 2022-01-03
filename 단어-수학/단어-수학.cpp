#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int numbers[30];
    fill(numbers, numbers + 30, 0);
    for(int i = 0; i < N; i++) {
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++) {
            // ACDEG -> 5글자 4~0
            numbers[s[j] - 'A'] += pow(10, s.size() - 1 - j);
        }
    }
    // for(auto i : numbers) cout << i << ' ';
    // cout << '\n';
    sort(numbers, numbers + 30, greater<int>());

    int answer = 0;
    for(int i = 0; i < 10; i++)
        answer += (9 - i) * numbers[i];
    cout << answer;
}
