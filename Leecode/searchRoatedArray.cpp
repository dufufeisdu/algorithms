//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/20/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//
//Leecode #Search in Rotated Sorted Array
//Suppose a sorted array is rotated at some pivot unknown to you beforehand.
//(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//You are given a target value to search. If found in the array
//return its index, otherwise return -1. You may assume no duplicate exists in the array.
//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/20/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    template <typename T>
    int searchRotatedSortedArray(vector<T>& arr, T target, int first,int last){
        int findIndex = -1;
        while (first<=last) {
            int mid = (last+first)/2;
            if(arr[mid]==target){
                return mid;
            }
            if(arr[first]==target){
                return first;
            }
            if(arr[last]==target){
                return last;
            }
            if(arr[first]<=arr[mid]){
                if(target<arr[mid]&&target>arr[first]){
                    last = mid-1;
                }else{
                    first = mid+1;
                }
                continue;
            }
            if(arr[mid]<=arr[last]){
                if(target>arr[mid]&&target<arr[first]){
                    first = mid+1;
                }else{
                    last = mid-1;
                }
                continue;
            }
            
        }
        return findIndex;
    }
    
};
int main ()
{
    vector<int> arr = {8,9,1,2,3,4,5,6};
    Solution s;
    int target = 9;
    cout<<s.searchRotatedSortedArray(arr,target,0,7)<<endl;
    return 0;
}
