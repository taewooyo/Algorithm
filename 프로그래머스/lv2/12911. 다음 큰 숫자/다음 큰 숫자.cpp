#include <string>
#include <vector>

using namespace std;

int GetCount(int n) {
    int cnt = 0;
    
    for(int i = 0; n > 0; i++) {
        if(n % 2 == 1) {
            cnt++;
        }
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int cnt = GetCount(n);
    
    while(true) {
        n++;
        if(GetCount(n) == cnt) break;
    }
    
    return n;
}