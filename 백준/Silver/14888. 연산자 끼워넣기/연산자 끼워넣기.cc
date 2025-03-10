// 14888.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector<int> oper(4);

int max_num = -1000000000;
int min_num = 1000000000;

int calcNum (int opr, int pos, int ans){
    switch (opr)
    {
    case 0:
        ans = ans+num[pos+1];
        break;
    case 1:
        ans = ans-num[pos+1];
        break;
    case 2:
        ans = ans*num[pos+1];
        break;
    case 3:
        ans = int(ans/num[pos+1]);
        break;
    default:
        break;
    }
    return ans;
}

void putOperator(int ans, int pos){
    if(pos==num.size()-1){
        max_num = max(ans,max_num);
        min_num = min(ans,min_num);
        return;
    }
    for(int i = 0; i<4; i++){
        if(oper[i]>0){
            oper[i]--;
            putOperator(calcNum(i,pos,ans),pos+1);
            oper[i]++;
        }
        
    }
}

int main(){
    int n, tmp;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>tmp;
        num.push_back(tmp);
    }
    for(int j = 0; j<4; j++){
        cin>>oper[j];
    }

    putOperator(num[0],0);
    cout<<max_num<<'\n'<<min_num;

}