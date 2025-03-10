// 백준 1991

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void Preorder(vector<pair<char,char>>* vec, int idx){
    cout<<(char)(idx+'A');
    if((*vec)[idx].first!='.'){
        Preorder(vec,(*vec)[idx].first-'A');
    }
    if((*vec)[idx].second!='.'){
        Preorder(vec,(*vec)[idx].second-'A');
    }
}

void Postorder(vector<pair<char,char>>* vec,int idx){
    if((*vec)[idx].first!='.'){
        Postorder(vec,(*vec)[idx].first-'A');
    }
    if((*vec)[idx].second!='.'){
        Postorder(vec,(*vec)[idx].second-'A');
    }
    cout<<(char)(idx+'A');
}

void Inorder(vector<pair<char,char>>* vec, int idx){
    if((*vec)[idx].first!='.'){
        Inorder(vec,(*vec)[idx].first-'A');
    }
    cout<<(char)(idx+'A');
    if((*vec)[idx].second!='.'){
        Inorder(vec,(*vec)[idx].second-'A');
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;


    vector<pair<char,char>>vec(26);
    
    for(int i = 1; i<n+1; i++){
        char mid, lft, rgt;
        cin>>mid>>lft>>rgt;
        vec[mid-'A'].first = lft;
        vec[mid-'A'].second = rgt;
    }

    Preorder(&vec,0);
    cout<<'\n';
    Inorder(&vec,0);
    cout<<'\n';
    Postorder(&vec,0);
}