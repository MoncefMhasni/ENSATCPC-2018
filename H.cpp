#include<bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,bool>> m;
int MAX = 200;
void gen(){
    unordered_map<int,unordered_map<int,bool>> p;
    unordered_map<int,int> r,c;
    for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++){
        if(m[i][j])continue;
        if(r[i]|| c[j]|| p[i-min(i,j)][j-min(i,j)])m[i][j]=1;
        else r[i] = c[j] = p[i-min(i,j)][j-min(i,j)]=1;
    }
}
int main(){
    gen();
    ios::sync_with_stdio(false);
    int tc;cin>>tc;
    while(tc--){
        int x,y;cin>>x>>y;
        cin>>x>>y;
        cout<<(m[x-1][y-1] == 1 ? "Menlo\n":"Hebby\n");
    }
}
