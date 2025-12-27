// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     vector<int>ans(n);
//     for (int i=0;i<n;i++){
//         cin>>ans[i];
//     }
//     int i=0;
//     while(i+3<ans.size()){
//         if (ans[i]==ans[i+1] && ans[i+1]==ans[i+2] && ans[i+2]==ans[i+3]){
//             ans.erase(ans.begin()+i,ans.begin()+i+4);
//             i=0;
//         }
//         else{
//             i++;
//         }
//     }
//     cout<<ans.size();
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<int,int>> st;

    for (int x : a) {
        if (!st.empty() && st.back().first == x) {
            st.back().second++;
            if (st.back().second == 4) {
                st.pop_back(); 
            }
        } else {
            st.push_back({x, 1});
        }
    }

    int result = 0;
    for (auto &p : st) {
        result += p.second;
    }

    cout << result;
}
