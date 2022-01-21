#include <bits/stdc++.h>
using namespace std;

int recommand[104], during[104];
vector<int> photo;
int n, m;

bool cmp(const int a, const int b) {
    if(recommand[a] != recommand[b]) 
        return recommand[a] < recommand[b];
    return during[a] > during[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        recommand[x]++;

        for(int j = 0; j < photo.size(); j++) {
            during[photo[j]]++;
        }

        bool exist = false;
        for(int j = 0; j < photo.size(); j++) {
            if(photo[j] == x) {
                exist = true;
                break;
            }            
        }

        if(!exist) {
            if(photo.size() < n)
                photo.push_back(x);
            else {
                sort(photo.begin(), photo.end(), cmp);
                recommand[photo[0]] = 0;
                during[photo[0]] = 0;
                photo[0] = x;
            }
        }
    }
    sort(photo.begin(), photo.end());
    for(auto& it: photo) cout << it << ' ';
}