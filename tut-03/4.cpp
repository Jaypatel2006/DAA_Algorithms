//Brute Force

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec = {1, 3, 20, 4, 1, 0};
    if(vec.size()<=2){
        cout<<"No peak Index"<<endl;
        return 0;
    }
    for(int i=0;i<vec.size()-1;i++){
        if(vec[i]>=vec[i-1] && vec[i]>=vec[i+1]){
            cout<<"Peak Index : "<<i<<endl;
            return 0;
        }
    }
    cout<<"No peak Index"<<endl;
    return 0;

}
