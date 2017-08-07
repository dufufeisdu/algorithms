//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/21/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    template <typename T>
    int findMedianOfTwoSortedArray(vector<T>& arr1,vector<T> & arr2){
        int median = 0;
        
        return median;
    }
    
};
int main ()
{
    vector<int> arr1 = {1,3,5,7,8,9};
    vector<int> arr2 = {2,4,6,8,9};
    vector<int> arr3 = {11,13,15,17,19};
    Solution s;
    cout<<s.findMedianOfTwoSortedArray(arr1,arr2)<<endl;
    return 0;
}
