// 1436.cpp

#include <iostream>

using namespace std;

int getMovieNum(int n){
    int movie_num = 665, count = 0, check_num = 0;
    while(count<n){
        movie_num++;
        check_num = movie_num;
        while(check_num/100>=1){
            if(check_num%1000==666){
                count++;
                break;
            }
            check_num/=10;
        }
    }
    return movie_num;

}

int main(){
    int n, result;
    cin>>n;
    result = getMovieNum(n);
    cout<<result;
}