#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> sum(n,vector<int>(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int a;
            cin>> a;
            if(i>0 && j>0){
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a;
            }
            else if(i>0){
                sum[i][j] = sum[i-1][j]+a;
            }
            else if(j>0){
                sum[i][j] = sum[i][j-1]+a;
            }
            else{
                sum[i][j] = a;
            }
        }
    }
    
    for(int k = 0; k<m; k++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1-2>=0&&y1-2>=0){
            cout<<sum[x2-1][y2-1]-sum[x1-2][y2-1]-sum[x2-1][y1-2]+sum[x1-2][y1-2];
        }
        else if(x1-2>=0){
            cout<<sum[x2-1][y2-1]-sum[x1-2][y2-1];
        }
        else if(y1-2>=0){
            cout<<sum[x2-1][y2-1]-sum[x2-1][y1-2];
        }
        else{
            cout<<sum[x2-1][y2-1];
        }
        cout<<'\n';
    }
}