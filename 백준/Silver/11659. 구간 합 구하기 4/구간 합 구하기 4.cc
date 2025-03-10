// 백준 11659

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int sum =0 ;
    cin>>n>>m;
    vector<int> vec_sum;
    vec_sum.push_back(sum);
    for(int num = 0; num<n; num++){
        int tmp;
        cin>>tmp;
        sum+=tmp;
        vec_sum.push_back(sum);
    }
    for(int range_m = 0; range_m<m; range_m++){
        int i, j;
        cin>>i>>j;
        cout<<vec_sum[j]-vec_sum[i-1]<<'\n';
    }
}