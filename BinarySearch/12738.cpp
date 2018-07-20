#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> vt,ans;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        vt.push_back(num);
    }
    ans.push_back(vt[0]);
    int size=0;
    
    for(int i=1;i<n;i++){
        if(ans[size]<vt[i]){
            size++;
            ans.push_back(vt[i]);
            continue;
        }
        int idx=lower_bound(ans.begin(), ans.end(),vt[i])-ans.begin();
        ans[idx]=vt[i];
    }
    printf("%d",size+1);
}
