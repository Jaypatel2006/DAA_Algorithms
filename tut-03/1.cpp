#include <iostream>
#include <vector>
using namespace std;

int invcount = 0;

void merge(vector<int> &vec,int left,int mid,int right){
    vector<int> temp(vec.size(),0);
    int k = left;
    for(k;k<=right;k++){
        temp[k] = vec[k];
    }
    int l = left;
    int r = mid+1;
    int i = left;
    while(i<vec.size() && l<=mid && r<=right){
        if(temp[l]<=temp[r]){
            vec[i] = temp[l];
            l++;
            i+=1;
        }
        else{
            vec[i] = temp[r];
            r++;
            invcount+=(mid - l + 1);
            i++;
        }
    }
    while(l<=mid){
        vec[i] = temp[l];
        l+=1;
        i+=1;
    }
    while(r<=right){
        vec[i] = temp[r];
        r++;
        i++;
    }


}

void mergesort(vector<int> &vec,int st,int en){

    if(st<en){
        int mid = (st+en)/2;
        mergesort(vec,st,mid);
        mergesort(vec,mid+1,en);
        merge(vec,st,mid,en);

    }

}

int main(){
    int n;
    
    cout<<"Enter The size of Array : ";
    cin>>n;
    vector<int> vec(n,0);
    cout<<"Enter The Elements ";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    int st = 0;
    int en = vec.size()-1;
    mergesort(vec,st,en);
    cout<<"The Number of Inersions = ";
    cout<<invcount<<endl;
    return 0;
}