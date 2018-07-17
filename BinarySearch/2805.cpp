#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define MAXX_N 1000000

int n,m;
ll arr[MAXX_N+1];

bool func(ll h){
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=max(0LL,arr[i]-h);
    }
    return sum>=m;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    
    ll lo=0;
    ll hi=1100000000;
    while(lo<hi){
        ll mid=(lo+hi)>>1;
        if(func(mid)){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    printf("%lld",lo-1);
}
