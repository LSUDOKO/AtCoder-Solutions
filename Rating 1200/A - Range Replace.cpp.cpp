#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    vector<pair<int, int>> runs;
    int ii = 1;
    while (ii <= N) {
        int val = A[ii];
        int jj = ii;
        while (jj <= N && A[jj] == val) jj++;
        runs.push_back({val, jj - ii});
        ii = jj;
    }
    int num_runs = runs.size();
    if (num_runs == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<int> run_start(num_runs);
    run_start[0] = 1;
    for (int k = 1; k < num_runs; k++) {
        run_start[k] = run_start[k - 1] + runs[k - 1].second;
    }
    vector<vector<int>> val_runs(N + 1);
    for (int k = 0; k < num_runs; k++) {
        int v = runs[k].first;
        val_runs[v].push_back(k);
    }
    vector<long long> later_same(num_runs, 0);
    for (int v = 1; v <= N; v++) {
        auto& rids = val_runs[v];
        int t = rids.size();
        if (t == 0) continue;
        vector<long long> suffix(t + 1, 0);
        for (int j = t - 1; j >= 0; j--) {
            int rid = rids[j];
            suffix[j] = suffix[j + 1] + runs[rid].second;
        }
        for (int j = 0; j < t; j++) {
            int rid = rids[j];
            later_same[rid] = suffix[j + 1];
        }
    }
    long long ans = 0;
    for (int k = 0; k < num_runs; k++) {
        int end_k = run_start[k] + runs[k].second - 1;
        long long length_after = N - end_k;
        long long local = 1 + (length_after - later_same[k]);
        ans += local;
    }
    ans -= (num_runs - 1);
    cout << ans << endl;
}