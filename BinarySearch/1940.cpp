#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,cnt;
vector<int> vt;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        vt.push_back(num);
    }
    sort(vt.begin(),vt.end());
    
    for(int i=0;i<n;i++){
        if(2*vt[i]==m) continue;
        if(binary_search(vt.begin(),vt.end(),m-vt[i]))
            cnt++;
    }
    printf("%d",cnt/2);
}
