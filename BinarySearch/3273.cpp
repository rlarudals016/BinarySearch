#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n,x,cnt;
vector<int> vt;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        vt.push_back(num);
    }
    sort(vt.begin(),vt.end());
    scanf("%d",&x);
    for(int i=0;i<n;i++){
        if(vt[i]*2==x) continue;
        if(binary_search(vt.begin(),vt.end(),x-vt[i]))
            cnt++;
    }
    printf("%d",cnt/2);
}
