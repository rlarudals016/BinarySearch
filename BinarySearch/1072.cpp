#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll x,y,z;

bool func(ll num){
    ll tmp=(100*(y+num))/(x+num);
    return tmp==z;
}

int main(){
    while(scanf("%lld%lld",&x,&y)!=EOF){
        z=100*y/x;
        
        if(z==99||z==100){
            puts("-1");
            continue;
        }
        ll lo=0;
        ll hi=11100000000;
        while(lo<hi){
            ll mid=(lo+hi)>>1;
            if(func(mid))
                lo=mid+1;
            else
                hi=mid;
        }
        printf("%lld\n",lo);
    }
}
