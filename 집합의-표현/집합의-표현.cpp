#include <bits/stdc++.h>
using namespace std;

int uf[1000001];
int n, m;
int uf_find(int a) {
    return uf[a] == -1 ? a : uf[a] = uf_find(uf[a]);
}

void uf_union(int a, int b) {
    a = uf_find(a);
    b = uf_find(b);
    if(a == b) return;
    uf[b] = a;
}

int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    fill(uf, uf+1000001, -1);
    while(m--) { 
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) uf_union(b, c);
        else {
            if(uf_find(b) != uf_find(c)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}