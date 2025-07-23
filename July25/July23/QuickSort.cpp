#include<bits/stdc++.h>
using namespace std;

void quickSort(vector<int>&arr,int start, int end){
    if(start>=end){
        return;
    }

    int i=start-1;
    int piviot = end;
    int j=start;

    while(j<arr.size()){
        if(arr[j] < arr[piviot]){
            i++;
            swap(arr[i],arr[j]);
            j++;
        }
        else{
            j++;
        }
    }

    i++;
    cout<<i<<endl;
    swap(arr[i],arr[piviot]);
    quickSort(arr,start,i-1);
    quickSort(arr,i+1,end);

}

int main(){
    vector<int>arr={9,2,19,85,2,-1,4};

    quickSort(arr,0,arr.size()-1);

    for(auto x:arr){
        cout<<x<<" ";
    }

    return 0;
}