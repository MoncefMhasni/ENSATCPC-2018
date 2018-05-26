#include<bits/stdc++.h>
using namespace std;
int main(){
	struct c{
		string name;
		int pb;
		int p;
	};
	int n;cin>>n;
	vector<c> v(n);
	for(int i=0;i<n;i++)cin>>v[i].name>>v[i].pb>>v[i].p;
	sort(v.begin(),v.end(),[](c a, c b)->bool{return (a.pb!=b.pb ?a.pb>b.pb:(a.p!=b.p ? a.p<b.p : a.name<b.name));});
	for(auto i:v)cout<<i.name<<endl;
	
}