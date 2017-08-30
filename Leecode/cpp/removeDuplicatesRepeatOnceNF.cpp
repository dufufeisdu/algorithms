//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/20/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//
//Leecode #Remove Duplicateds from Sorted Array.
//mutate: element can repeat once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    template <typename T>
    int removeDuplicate(vector<T>& arr){
        int len = 0;
        if(arr.size()<3){
            return arr.size();
        }
        for(int i = 0,repeat = 0,j = 1;j<arr.size();j++){
            if(arr[i]!=arr[j]){
                arr[++i]=arr[j];
                repeat=0;
                len = i;
            }else if(repeat==0){
                i++;
                repeat++;
                len = i;
            }
        }
        //        for(auto i:arr){
        //        cout<<i<<" ";
        //        }
        return len+1;
    }
    
};
int main ()
{
    vector<int> arr = {1,2,2,3,3,3,4,5,5,5,5,5,6};
    Solution s;
    cout<<s.removeDuplicate(arr)<<endl;
    return 0;
}
