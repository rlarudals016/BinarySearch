#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a,b,v;

bool func(ll day){
    return ((a-b)*(day-1)+a)<v;
}

int main(){
    scanf("%lld%lld%lld",&a,&b,&v);
    ll lo=1;
    ll hi=1100000000;
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        if(func(mid))
            lo=mid+1;
        else
            hi=mid;
    }
    printf("%lld",lo);
}
