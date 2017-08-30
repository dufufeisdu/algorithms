//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/20/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//
//Leecode #Remove Duplicateds from Sorted Array.

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    template <typename T>
    int removeDuplicate(vector<T>& arr){
        int len = 0;
        if(arr.size()<2){
            return arr.size();
        }
        for(int i = 0,j = 0;j<arr.size()-1;j++){
            if(arr[j]!=arr[j+1]){
                arr[i]=arr[j];
                i++;
                len = i;
            }
        }
        swap(arr[len],arr[arr.size()-1]);
        return len+1;
    }
    
};
int main ()
{
    vector<int> arr = {1,2,2,3,3,3,4,5,5,5,5,5};
    Solution s;
    cout<<s.removeDuplicate(arr)<<endl;
    return 0;
}
