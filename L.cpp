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

    string p;
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

    vector<int> fail, a(n), b(n);
    kmp(t, p, fail, a);
    reverse(p.begin(), p.end());
    reverse(t.begin(), t.end());
    kmp(t, p, fail, b);

    reverse(b.begin(), b.end());
    reverse(t.begin(), t.end());

    int good_i = -1, good_j = -1;

    if(b[0] == n-2) {
        good_i = n-2;
        good_j = n-1;
        if(s[x] == t[good_i] && s[y] == t[good_j]) {
            cout << "YES";
            return 0;
        }
    }

    if(b[1] == n-2) {
        good_i = 0;
        good_j = n-1;
        if(s[x] == t[good_i] && s[y] == t[good_j]) {
            cout << "YES";
            return 0;
        }
    }

    if(b[2] == n-2) {
        good_i = 0;
        good_j = 1;
        if(s[x] == t[good_i] && s[y] == t[good_j]) {
            cout << "YES";
            return 0;
        }
    }

    for(int i=0; i<n-3; i++) {
        if(a[i] + b[i+1] == n - 2) {
            good_i = n-2;
            good_j = n-1;
            if(s[x] == t[good_i] && s[y] == t[good_j]) {
                cout << "YES";
                return 0;
            }
        }
        else if(a[i] + b[i+2] == n - 2) {
            good_i = i+1;
            good_j = n-1;
            if(s[x] == t[good_i] && s[y] == t[good_j]) {
                cout << "YES";
                return 0;
            }
        }
        else if(a[i] + b[i+3] == n - 2) {
            good_i = i+1;
            good_j = i+2;
            if(s[x] == t[good_i] && s[y] == t[good_j]) {
                cout << "YES";
                return 0;
            }
        }
    }

    if(a[n-2] == n-2) {
        good_i = 0;
        good_j = n-1;
        if(s[x] == t[good_i] && s[y] == t[good_j]) {
            cout << "YES";
            return 0;
        }
    }

    if(a[n-1] == n-2) {
        good_i = 0;
        good_j = 1;
        if(s[x] == t[good_i] && s[y] == t[good_j]) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;
}