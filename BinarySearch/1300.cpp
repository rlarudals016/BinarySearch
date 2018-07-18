#include <cstdio>
#include <algorithm>
using namespace std;

int n,k;

bool func(int num){
    int tmp=0;
    for(int i=1;i<=n;i++){
        tmp+=min(n,num/i);
    }
    return tmp<k;
}

int main(){
    scanf("%d%d",&n,&k);
    int lo=0;
    int hi=k;
    while(lo<hi){
        int mid=(lo+hi)>>1;
        if(func(mid))
            lo=mid+1;
        else
            hi=mid;
    }
    printf("%d",lo);
}
