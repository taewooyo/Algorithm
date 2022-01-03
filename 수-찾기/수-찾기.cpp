#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;

bool findNumber(int N){
    int left = 0;
    int right = vec.size() - 1;
    while(left<right){
        int mid = (left+right) / 2;
        if(vec[mid] < N){
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return vec[(left+right)/2] == N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin>>num;
        cout<<findNumber(num)<<'\n';
    }
    return 0;
}