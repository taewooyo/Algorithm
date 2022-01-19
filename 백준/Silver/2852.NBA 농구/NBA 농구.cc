#include <bits/stdc++.h>
using namespace std;

int win, n, a_score, b_score;
int asum, bsum;
string s, pervious;


int convertTime(string a) {
    return atoi(a.substr(0, 2).c_str()) * 60 + atoi(a.substr(3, 2).c_str());
}

void go(int &sum, string s) {
    sum += (convertTime(s) - convertTime(pervious));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> win >> s;
        if(a_score > b_score) go(asum, s);
        else if(a_score < b_score) go(bsum, s);
        
        win == 1 ? a_score++ : b_score++;
        pervious = s;
    }

    if(a_score > b_score) go(asum, "48:00");
    else if(a_score < b_score) go(bsum, "48:00");

    string h = "00" + to_string(asum / 60);
    string m = "00" + to_string(asum % 60);
    cout << h.substr(h.size()-2, 2) + ":" + m.substr(m.size()-2, 2) << "\n";

    h = "00" + to_string(bsum / 60);
    m = "00" + to_string(bsum % 60);
    cout << h.substr(h.size()-2, 2) + ":" + m.substr(m.size()-2, 2) << "\n";

    return 0;
}