// 1213.cpp

#include <iostream>
#include <vector>

using namespace std;

string getPalindrome(string org){
    string pal;
    int odd=0, odd_idx;
    vector <int> alph(26,0);
    for(int i=0;i<org.size();i++){
        alph[org[i]-'A']++;
    }
    for(int j=0;j<26;j++){
        if(alph[j]%2){
            odd++;
            odd_idx = j;
        }
        if(odd>1){
            return "I'm Sorry Hansoo";
        }
        for(int n = 0;n<alph[j]/2;n++){
            pal.push_back(j+'A');
        }
    }

    int pal_size = pal.size();
    if(org.size()%2){
        pal.push_back(odd_idx+'A');
    }
    for(int k = pal_size-1; k>=0; k--){
        pal.push_back(pal[k]);
    }

    return pal;

}

int main(){
    string org,pal;
    cin>>org;

    cout<<getPalindrome(org);


}