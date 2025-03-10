// 백준 1744

#include<iostream>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    priority_queue<int> pque;
    priority_queue<int,vector<int>,greater<int>> mpque;
    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        if(tmp>0){
            pque.push(tmp);
        }
        else{
            mpque.push(tmp);
        }
    }

    int sum = 0;
    while(!pque.empty()){
        int a, b;
        a = pque.top();
        pque.pop();
        if(a == 1){
            sum+=a;
            continue;
        }
        else if(pque.empty()){
            sum+=a;
            break;
        }
        b = pque.top();
        pque.pop();
        if(b == 1){
            sum+=a+b;
            continue;
        }
        else{
            sum += (a*b);
        }
    }

    while(!mpque.empty()){
        int a, b;
        a = mpque.top();
        mpque.pop();
        if(mpque.empty()){
            sum+=a;
            break;
        }
        b = mpque.top();
        mpque.pop();
        sum += (a*b);
    }

    cout<<sum;
}