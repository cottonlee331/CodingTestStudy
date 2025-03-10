// 백준 12891

#include <iostream>
#include <vector>

using namespace std;

int main(){
    // [0]A, [1]C, [2]G, [3]T
    vector<int> dna_vec;
    vector<int> cnt_vec(4,0);
    int s, p;
    cin>>s>>p;
    vector<char> str_vec;
    for(int i = 0; i<s; i++){
        char tmp;
        cin>>tmp;
        str_vec.push_back(tmp);
    }

    for(int k = 0; k<p; k++){
        switch(str_vec[k]){
            case 'A':
                cnt_vec[0]++;
                break;
            case 'C':
                cnt_vec[1]++;
                break;
            case 'G':
                cnt_vec[2]++;
                break;
            case 'T':
                cnt_vec[3]++;
                break;
            default:
                break;
        }
    }
    
    for(int j = 0; j<4; j++){
        int n;
        cin>>n;
        dna_vec.push_back(n);
    }
    
    int result = 0;
    int left = 0;
    int right = p;
    while(right<=s){
        if(cnt_vec[0]>=dna_vec[0]&&cnt_vec[1]>=dna_vec[1]&&cnt_vec[2]>=dna_vec[2]&&cnt_vec[3]>=dna_vec[3]){
            result++;
        }
        switch(str_vec[left]){
            case 'A':
                cnt_vec[0]--;
                break;
            case 'C':
                cnt_vec[1]--;
                break;
            case 'G':
                cnt_vec[2]--;
                break;
            case 'T':
                cnt_vec[3]--;
                break;
            default:
                break;
        }
        switch(str_vec[right]){
            case 'A':
                cnt_vec[0]++;
                break;
            case 'C':
                cnt_vec[1]++;
                break;
            case 'G':
                cnt_vec[2]++;
                break;
            case 'T':
                cnt_vec[3]++;
                break;
            default:
                break;
        }
        left++;
        right++;
    }
    cout<<result;
}