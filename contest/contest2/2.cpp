// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,m;
//     cin>>n>>m;
//     string s;
//     cin>>s;
//     string t;
//     cin>>t;
//     int mini=INT_MAX;
//     for (int i=0;i<=(n-m);i++){
//         string b = s.substr(i, m);
//         int count=0;
//         for (int j=0;j<m;j++){
//             int x=b[j]-'0';
//             int y=t[j]-'0';
//             if (x<y){
//                 count+=(9-(y)+(x)+1);
//             }
//             else if (b[i]>t[i]){
//                 count+=(x-y);
//             }
//             else{
//                 count+=0;
//             }
//         }
//         mini=min(mini,count);
//     }
//     cout<<mini;
// }

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    string t;
    cin>>t;
    int ans=INT_MAX;
    for (int i=0;i<=n-m ;i++){
        int count=0;
        for(int j=0;j<m;j++){
            int S=s[i+j]-'0';
            int T=t[j]-'0';
            count+=(S-T+10)%10;

        }
        ans=min(ans,count);
    }
    cout<<ans<<endl;
}