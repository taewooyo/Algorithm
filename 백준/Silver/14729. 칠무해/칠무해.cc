#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
double temp;
priority_queue<double> pq;
vector<double> v;
void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }
    while(pq.size() != 7) pq.pop();
}

void Pro() {
    while(pq.size()) {
        v.push_back(pq.top());
        pq.pop();
    }
    reverse(v.begin(), v.end());
    for(double it: v) printf("%.3lf\n", it);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Input();
    Pro();
}