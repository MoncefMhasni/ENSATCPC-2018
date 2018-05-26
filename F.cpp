#include<bits/stdc++.h>
using namespace std;
const int MAX =1e6+1,NMAX = 1000;
inline int hsh(int x,int y){return NMAX*x+y;}
struct unionfind {
int p[MAX], r[MAX]; // r contains the population
unionfind() { for(int i=0;i<MAX;i++) p[i] = i, r[i] = 1; }
int find( int x ) { if( p[x] == x ) return x; else return p[x] = find( p[x] ); }
void Union(int x, int y) {
int px = find( x ), py = find( y );
if( px == py ) return; //already joined
if( r[ px ] < r[ py ] ) p[px] = py, r[py] += r[px];
else p[ py ] = px, r[px] += r[py];
}
};
int main(){
    ios::sync_with_stdio(false);
    int N,M;cin>>N>>M;
    unordered_map<int,unordered_map<int,int>>G;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)cin>>G[i][j];
    unionfind U;
    queue<int> Q;
    Q.push(0);
    vector<int> vis(MAX,0);
    while(!Q.empty()){
        int x = Q.front()/NMAX;
        int y = Q.front()%NMAX;
        Q.pop();
        int u = hsh(x,y);
        vis[u]=1;
        for(int i=-1;i<2;i++){
            for(int j=-1;j<2;j++){
                if((abs(i)+abs(j))!=1 || x+i<0 || y+j <0 || x+i>N-1 || y+j > M-1)continue;
                int v = hsh(x+i,y+j);
                if(G[x][y]==G[x+i][y+j]) U.Union(u,v);
                if(vis[v])continue;
                Q.push(v);vis[v]=1;
            }
        }
    }
    int q;cin>>q;
    while(q--){
        int x,y,a,b;cin>>x>>y>>a>>b;
        cout<<(U.find(hsh(x-1,y-1))==U.find(hsh(a-1,b-1)) ? "YES" : "NO")<<endl;
    }
}
