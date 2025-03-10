// 14235.cpp

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, a, gift;
    priority_queue <int> que;

    cin>>n;
    for (int i = 0; i<n; i++){
        cin>>a;
        if(a==0){
            if(que.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<que.top()<<'\n';
                que.pop();
            }
        }
        else{
            for(int j = 0; j<a; j++){
                cin>>gift;
                que.push(gift);
            }
        }
    }
    

}