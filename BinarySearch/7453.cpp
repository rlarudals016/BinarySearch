#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXX_N 4000
typedef long long ll;

int n,a[MAXX_N+1],b[MAXX_N+1],c[MAXX_N+1],d[MAXX_N+1];
vector<int> vt1,vt2;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=a[i]+b[j];
            vt1.push_back(sum);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int sum=c[i]+d[j];
            vt2.push_back(sum);
        }
    }
    sort(vt2.begin(),vt2.end());
    ll ans=0;
    for(int i=0;i<vt1.size();i++){
        int r=upper_bound(vt2.begin(),vt2.end(),-vt1[i])-vt2.begin();
        int l=lower_bound(vt2.begin(),vt2.end(),-vt1[i])-vt2.begin();
        ans+=(r-l);
    }
    printf("%lld",ans);
}
