#include <bits/stdc++.h>
#define t second
#define w first
#define inf 1e20
#define eps 1e-10
#define pl pair<double,double>
using namespace std;
int main(){
        vector<pl> v(9);
        vector<vector<double>>t(9);
       for(int i=0;i<9;i++) cin>>v[i].w>>v[i].t;
       double maxx = 8*360/v[0].w;
       sort(v.begin(),v.end(),[](pl a, pl b)->bool{return a.w<b.w;});
       bool ok = 1;
       for(int i=1;i<v.size();i++){
            v[i].w-=v[0].w;
            if(fabs(v[i].w) < eps ){
                    if(fmod(fabs(v[i].t - v[0].t),180)>eps) ok = 0;
                    v.erase(v.begin()+i);i--;
                    continue;
            }
            double dt1 = (v[0].t-v[i].t), dt2 = (fmod(v[0].t+180,360)-v[i].t);
            double dt = (dt1 <0 ? (dt2 <0 ? min(dt1+360,dt2+360) : dt2 ) : (dt2<0 ? dt1 : min(dt1,dt2)));
            t[i].push_back(dt/v[i].w);
       }
       for(int p=1;p<v.size();p++)
       for(int i=1;t[p][i-1]<= maxx;i++)t[p].push_back(t[p][i-1]+(180.0)/v[p].w);
       double ans = ok*v.size() == 1 ? 0 : 2*inf;
        for(int i=0;i<t[1].size();i++){
            int cc = 0;
            for(int j=1;j<v.size();j++)
                for(int k=0;k< t[j].size();k++) cc+=  fabs(t[j][k]-t[1][i])<eps ;
                if(cc == v.size()-1)ans = min(t[1][i],ans);
        }
       if(!ok ||ans > maxx) cout<<"-1\n";
       else cout<<ans<<endl;
}
