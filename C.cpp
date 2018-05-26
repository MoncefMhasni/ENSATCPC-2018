#include<bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<char,int> m;
	string in;cin>>in;int ans = 0;
	for(auto i:in)m[i]++;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	sort(alpha.begin(),alpha.end(),[&m](char a,char b){return m[a]>m[b];});
	for(int i=0;i<26;i++)m[alpha[i]]=i/8+1;
	for(auto i:in)ans+=m[i];cout<<ans<<endl;
}