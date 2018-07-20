#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n,s;
vector<int> vt,a,b;

void func(int stpos,int endpos,int num,vector<int>& vvt){
    if(stpos==endpos){
        vvt.push_back(num);
        return ;
    }
    func(stpos+1,endpos,num,vvt);
    func(stpos+1,endpos,num+vt[stpos],vvt);
}

int main(){
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        vt.push_back(num);
    }
    func(0,n/2,0,a);
    func(n/2,n,0,b);
    
    sort(a.begin(),a.end());
    
    ll ans=0;
    for(int i=0;i<b.size();i++){
        int r=upper_bound(a.begin(),a.end(),s-b[i])-a.begin();
        int l=lower_bound(a.begin(),a.end(),s-b[i])-a.begin();
        ans+=(r-l);
    }
    if(s==0)
        ans--;
    printf("%lld",ans);
}
