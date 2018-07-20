#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXX_N 500000

int n,m;
vector<int> vt;

int func(int num){
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=(lo+hi)>>1;
        if(vt[mid]<num)
            lo=mid+1;
        else if(vt[mid]>num)
            hi=mid-1;
        else
            return 1;
  
    }
    return 0;
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        vt.push_back(num);
    }
    sort(vt.begin(),vt.end());
    
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        if(func(num))
            printf("1 ");
        else
            printf("0 ");
        
    }
}
