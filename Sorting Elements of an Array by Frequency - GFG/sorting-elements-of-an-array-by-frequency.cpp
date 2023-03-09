#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p,pair<int,int> q){
    if(p.first!=q.first){
        return p.first>q.first;
    }
    return p.second<q.second;
}

vector<int> sortByFreq(vector<int> &a){
    unordered_map<int,int> freq;
    for(int i=0;i<a.size();i++){
        freq[a[i]]++;
    }
    vector<pair<int,int>> v;
    for(auto it:freq){
        v.push_back({it.second,it.first});
    }
    sort(v.begin(),v.end(),cmp);
    vector<int> ans;
    for(auto it:v){
        int f=it.first;
        int n=it.second;
        while(f--){
            ans.push_back(n);
        }
    }
    return ans;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        } 
        vector<int> ans;
        ans=sortByFreq(a);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}