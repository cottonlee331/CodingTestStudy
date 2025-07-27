#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // abs()

#define EPS 1e-9

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<double> x1(2);
    vector<double> y1(2);
    vector<double> x2(2);
    vector<double> y2(2);
    double a, b, c, d;
    bool flag1 = false;
    bool flag2 = false;

    // 첫 번째 직선
    cin>>x1[0]>>y1[0]>>x2[0]>>y2[0];
    if(x1[0]>x2[0]){
        swap(x1[0],x2[0]);
        swap(y1[0],y2[0]);
    }
    if(x1[0]!=x2[0]){
        a = (y2[0]-y1[0])/(x2[0]-x1[0]);
    }
    else{
        a = 0;
        flag1 = true;
    }
    b = -a*x1[0]+y1[0];

    // 두 번째 직선
    cin>>x1[1]>>y1[1]>>x2[1]>>y2[1];
    if(x1[1]>x2[1]){
        swap(x1[1],x2[1]);
        swap(y1[1],y2[1]);
    }
    if(x1[1]!=x2[1]){
        c = (y2[1]-y1[1])/(x2[1]-x1[1]);
    }
    else{
        c = 0;
        flag2 = true;
    }
    d = -c*x1[1]+y1[1];

    if(x2[1]<x1[0] || x2[0]<x1[1]){
        cout<<0;
        return 0;
    }

    int ans = 0;
    if(flag1 && flag2){
        if(y1[0]>y2[0]){
            swap(y1[0],y2[0]);
        }
        if(y1[1]>y2[1]){
            swap(y1[1],y2[1]);
        }
        if(y2[1]<y1[0] || y2[0]<y1[1]){
            cout<<0;
        }
        else{
            cout<<1;
        }
        return 0;
    }
    else if(flag1){
        if(y1[0]>y2[0]){
            swap(y1[0],y2[0]);
        }
        double p = c*x1[0]+d;
        if(y1[0]<=p && p<=y2[0]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    else if(flag2){
        if(y1[1]>y2[1]){
            swap(y1[1],y2[1]);
        }
        double p = a*x1[1]+b;
        if(y1[1]<=p && p<=y2[1]){
            cout<<1;
        }
        else{
            cout<<0;
        }
        return 0;
    }
    
    if(abs(a-c)<EPS){
        if(abs(b-d)<EPS){
            ans = 1;
        }
    }
    else{
        double x = (d-b)/(a-c);
        if(x >= max(x1[0], x1[1]) - EPS && x <= min(x2[0], x2[1]) + EPS){
            ans = 1;
        }
    }

    cout<<ans;
}
