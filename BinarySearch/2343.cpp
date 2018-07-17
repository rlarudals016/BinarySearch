#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXX_N 100000
typedef long long ll;

ll n,m,lesson[MAXX_N+1];

bool func(ll blueray){
    ll cnt=1;
    ll sum=0;
    for(ll i=0;i<n;i++){
        if(sum+lesson[i]>blueray){
            cnt++;
            sum=0;
        }
        sum+=lesson[i];
    }
    return cnt>m;
}

int main(){
    scanf("%lld%lld",&n,&m);
    ll lo=0;
    for(int i=0;i<n;i++){
        scanf("%lld",&lesson[i]);
        lo=max(lo,lesson[i]);
    }
    ll hi=2100000000;
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        if(func(mid))
            lo=mid+1;
        else
            hi=mid;
    }
    printf("%lld",lo);
}
