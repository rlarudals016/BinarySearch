#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int t,n,m;

int main(){
    scanf("%d",&t);
    while(t--){
        vector<int> vt;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            int num;
            scanf("%d",&num);
            vt.push_back(num);
        }
        int cnt=0;
        sort(vt.begin(),vt.end());
        for(int i=0;i<m;i++){
            int num;
            scanf("%d",&num);
            int tmp=upper_bound(vt.begin(),vt.end(),num)-vt.begin();
            cnt+=(n-tmp);
        }
        printf("%d\n",cnt);
    }
}
