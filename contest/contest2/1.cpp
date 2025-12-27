#include<bits/stdc++.h>
using namespace std ;
int main(){
    int d,f;
    cin>>d>>f;
    int sum=f;
    while(sum<d){
        sum+=7;
    }
    int ans=sum-d;
    if (ans==0) ans=7;
    cout<<ans;
    

}