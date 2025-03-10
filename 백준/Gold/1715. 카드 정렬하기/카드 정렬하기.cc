// 백준 1715

#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    deque<int> vec;
    deque<int> sumvec;

    for(int i = 0; i<n; i++){
        int tmp;
        cin>>tmp;
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());

    int sum = 0;
    if(n!=1){
        sum = vec[0]+vec[1];
    }
    vec.pop_front();
    vec.pop_front();
    sumvec.push_back(sum);
    int a, b;
    while(!vec.empty()||!sumvec.empty()){
        if(n==1){
            break;
        }
        if(sumvec.empty()||(!vec.empty()&&vec.front()<sumvec.front())){
            a = vec.front();
            vec.pop_front();
        }
        else{
            a = sumvec.front();
            sumvec.pop_front();
        }
        if(sumvec.empty()&&vec.empty()){
            break;
        }
        if(sumvec.empty()||(!vec.empty()&&vec.front()<sumvec.front())){
            b = vec.front();
            vec.pop_front();
        }
        else{
            b = sumvec.front();
            sumvec.pop_front();
        }

        //cout<<a<<" "<<b<<"\t"<<sum<<endl;
        sumvec.push_back(a+b);
        sum += a+b;
    }

    cout<<sum;
}