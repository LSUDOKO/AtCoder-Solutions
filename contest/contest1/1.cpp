#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        if (i%2!=0){
            sum+=-pow(i,3);
        }
        else{
            sum+=pow(i,3);
        }
    }
    cout<<sum<<endl;
}