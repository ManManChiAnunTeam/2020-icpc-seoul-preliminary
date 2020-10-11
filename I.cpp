#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, w[10002] = {};
    cin >> n;

    for(int i=1; i<=2*n; i++) cin >> w[i];

    sort(w + 1, w + 2 * n + 1);

    int ans = 987654321;

    for(int i=1; i<=n; i++) {
        int sum = w[i] + w[2*n-i + 1];
        ans = min(ans, sum);
    }
    cout << ans;
}