#include <bits/stdc++.h>

using namespace std;

vector<int> getFail(string &str) {
    vector<int> fail(str.size(), 0);
    for(int i=1, j=0; i < (int)str.size(); ++i) {
        while(j > 0 && str[i] != str[j])
            j = fail[j-1];
        if(str[i] == str[j])
            fail[i] = ++j;
    }
    return fail;
}

void kmp(string &para, string &target, vector<int>& fail, vector<int> &found) {
    fail = getFail(target);
    // found.clear();

    for(int i=0, j=0; i< (int)para.size(); ++i) {
        while(j>0 && para[i] != target[j])
            j = fail[j-1];
        if(para[i] == target[j]) {
            if(j == (int)target.size() - 1) {
                // found.push_back(i - int(target.size()) + 2);
                j = fail[j];
            }
            else j++;
        }
        found[i] = j;
    }
}

int main() {
    freopen("1.in", "r", stdin);
    int n;
    string s, t;
    int x, y;

    cin >> n;
    cin >> s;
    cin >> t;
    cin >> x >> y;
    string p, q;
    p.reserve(n);
    for(int i=0; i<x; i++) {
        p.push_back(s[i]);
    }
    for(int i=x+1; i<y; i++) {
        p.push_back(s[i]);
    }
    for(int i=y+1; i<n; i++) {
        p.push_back(s[i]);
    }
    q = p;
    reverse(q.begin(), q.end());

    bool flag = false;
    vector<int> fail_l, fail_r, kmpl, kmpr;
    // 1
    if (t[0] == s[x] && t[1] == s[y]){
        string A = s.substr(2, s.size() - 2);
        string A_L = A;
        reverse(A_L.begin(), A_L.end());
        kmp(A, p, fail_l, kmpl);
        kmp(A_L, q, fail_r, kmpr);
        for (int i = 0; i < n - 3; i++) {
            if (kmpl[i] + kmpr[i + 1] == n - 2) flag = true;
        }
        if (kmpl[0] == n - 2) flag = true;
    }
    // 2 
    if (t[0] == s[x]){
        string A = s.substr(1, s.size() - 1);
        string A_L = A;
        reverse(A_L.begin(), A_L.end());
        kmp(A, p, fail_l, kmpl);
        kmp(A_L, q, fail_r, kmpr);
        for (int i = 0; i < n - 3; i++) {
            if (kmpl[i] + kmpr[i + 2] == n - 2 && A[i + 1] == s[y]) flag = true;
        }
        if (kmpl[n - 3] == n - 2 && A[n - 2] == s[y]) flag = true;
    }
    // 3
    if (t[0] == s[x]){
        string A = s;
        string A_L = A;
        reverse(A_L.begin(), A_L.end());
        kmp(A, p, fail_l, kmpl);
        kmp(A_L, q, fail_r, kmpr);



        if (t[n-1] == s[y]) {
            for (int i = 0; i < n - 1; i++) {
            if (kmpl[i] + kmpr[i + 1] == n - 2 && A[i + 1] == s[y]) flag = true;
            } 
        }
        

        for (int i = 0; i < n - 3; i++) {
            if (kmpl[i] + kmpr[i + 3] == n - 2 && t[i + 1] == s[x] && t[i + 2] == s[y]) flag = true;
            if (kmpl[n - 3] == n - 2 && A[n - 2] == s[y]) flag = true;
        }











        if (kmpl[n - 3] == n - 2 && t[n-2]== s[x] && t[n-1] == s[y]) flag = true;



    }
    
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}