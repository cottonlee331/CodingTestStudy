#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int> A(n);
    vector<int> B(n);
    vector<int> C(n);
    vector<int> D(n);
    for(int i = 0; i<n; i++){
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }

    int idx = 0;
    vector<int> AB(n*n);
    vector<int> CD(n*n);
    for(int j = 0; j<n; j++){
        for(int k = 0; k<n; k++){
            AB[idx] = A[j]+B[k];
            CD[idx] = C[j]+D[k];
            idx++;
        }
    }
    sort(AB.begin(),AB.end());
    sort(CD.begin(),CD.end());

    long long cnt = 0;
    int a = 0;
    int c = n*n-1;
    while(a<n*n && 0<=c){
        int sum = AB[a]+CD[c];
        if(sum<0){
            a++;
        }
        else if(0<sum){
            c--;
        }
        else{
            int ab = 1;
            int cd = 1;
            while(a<n*n-1 && AB[a]==AB[a+1]){
                a++;
                ab++;
            }
            a++;
            while(0<c && CD[c]==CD[c-1]){
                c--;
                cd++;
            }
            c--;
            cnt+=(long long)ab*cd;
        }
    }
    cout<<cnt;

}