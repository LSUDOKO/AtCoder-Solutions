// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, Q;
//     cin >> n >> Q;
//     vector<int> ans(n);
//     for (int i = 0; i < n; i++) {
//         cin >> ans[i];
//     }

//     while (Q--) {
//         long long sum = 0;
//         int type;
//         cin >> type;

//         if (type == 1) {
//             int c;
//             cin >> c;
//             rotate(ans.begin(), ans.begin() + c, ans.end());
//         } else {
//             int l, r;
//             cin >> l >> r;
//             for (int i = l - 1; i <= r - 1; i++) {
//                 sum += ans[i];
//             }
//             cout << sum << endl;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, Q;
    cin >> n >> Q;
    vector<long long> A(n), prefix(n+1, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        prefix[i+1] = prefix[i] + A[i];
    }

    int shift = 0; 

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int c;
            cin >> c;
            shift = (shift + c) % n;
        } else {
            int l, r;
            cin >> l >> r;

            int realL = (shift + (l-1)) % n;
            int realR = (shift + (r-1)) % n;

            long long ans = 0;
            if (realL <= realR) {
                ans = prefix[realR+1] - prefix[realL];
            } else {
                ans = (prefix[n] - prefix[realL]) + prefix[realR+1];
            }
            cout << ans << endl;
        }
    }
}
