#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans(n);
    map<int,int> frq;
    vector<int> rem;
    vector<int> pu;
    bool check = true;

    for (int i = 0; i < n; i++) {
        cin >> ans[i];
        frq[ans[i]]++;
        if (ans[i] != -1) {
            pu.push_back(ans[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (find(pu.begin(), pu.end(), i) == pu.end()) {
            rem.push_back(i);
        }
    }

    for (auto p : frq) {
        if (p.first != -1 && p.second > 1) {
            check = false;
        }
    }

    if (check) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) {
                ans[i] = rem[j++];
            }
        }
        cout << "Yes"<<endl;
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout <<endl;
    } else {
        cout << "No"<<endl;
    }
}
