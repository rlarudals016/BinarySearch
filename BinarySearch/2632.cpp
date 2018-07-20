#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int demand,n,m,cnt;
int a[1001],b[1001];
vector<int> only_a,only_b;

int main(){
    scanf("%d%d%d",&demand,&n,&m);
    int sum_a=0;
    int sum_b=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum_a+=a[i];
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
        sum_b+=b[i];
    }
    if(sum_a==demand) cnt++;
    if(sum_b==demand) cnt++;
    if(sum_a<demand) only_a.push_back(sum_a);
    if(sum_b<demand) only_b.push_back(sum_b);
    
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<i+n-1;j++){
            sum+=a[j%n];
            if(sum==demand){
                cnt++;
                break;
            }
            if(sum>demand)
                break;
            
            only_a.push_back(sum);
        }
    }
    for(int i=0;i<m;i++){
        int sum=0;
        for(int j=i;j<i+m-1;j++){
            sum+=b[j%m];
            if(sum==demand){
                cnt++;
                break;
            }
            if(sum>demand)
                break;
            
            only_b.push_back(sum);
        }
    }

    sort(only_a.begin(),only_a.end());
    
    for(int i=0;i<only_b.size();i++){
        int r=upper_bound(only_a.begin(),only_a.end(),demand-only_b[i])-only_a.begin();
        int l=lower_bound(only_a.begin(),only_a.end(),demand-only_b[i])-only_a.begin();
        cnt+=(r-l);
    }
    printf("%d",cnt);
    
}
