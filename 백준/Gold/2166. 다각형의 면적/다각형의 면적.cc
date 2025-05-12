#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pair<double,double>> points;
    for(int i = 0; i<n; i++){
        double x, y;
        cin>>x>>y;
        points.push_back({x,y});
    }

    double sum = 0;
    for(int j = 0; j<n; j++){
        double x1 = points[(j+1)%n].first;
        double y1 = points[(j+1)%n].second;
        double x2 = points[j].first;
        double y2 = points[j].second;

        sum+=x1*y2-x2*y1;
    }
    sum = abs(sum)/2.0f;
    cout<<fixed<<setprecision(1)<<sum;
}