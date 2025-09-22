#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    vector<int> ans(n);
    for (int i=0;i<n;i++){
        cin>>ans[i];
    }
    sort(ans.begin(),ans.end());
    for (int i=0;i<n-1;i++){
        if (ans[i]!=ans[i+1]){
            count+=(n-i-1);
        }
    }
    cout<<count+1;
}