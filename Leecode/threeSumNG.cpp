//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/21/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//  Leecode practice:
//Given an array S of n integers, are there elements a,b,c in S such that a+b+c = 0? Find all unique triplets in the array which gives the sum of zero.
//Note:
//• Elements in a triplet (a, b, c) must be in non-descending order. (ie, a ≤ b ≤ c) the solution set must not contain duplicate triplets.
//For example, given array S = {-1 0 1 2 -1 -4}.
//A solution set is:
//(-1, 0, 1)
//(-1, -1, 2)
//steps:
//0 sort
//1 hash table for every element
//2 brutal force
//3 check for repeat
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    template <typename T>
    vector<vector<int>> threeSum(vector<T>& arr1){
        vector<vector<int>> sequence ;
        unordered_map<int, int> data;
        for(auto i : arr1){
            if(data.find(i)!=data.end()){
                data[i]++;
            }else{
                data[i]=1;
            }
        }
        for(int i = 0; i<arr1.size(); i++){
            data[arr1[i]]--;
            for(int j = i; j<arr1.size();j++){
                if(data[arr1[j]]==0){
                    continue;
                }
                data[arr1[j]]--;
                int target =0-arr1[j]-arr1[i];
                if(data.find(target)!=data.end()&&data[target]){
                    vector<int> sum = {arr1[i],arr1[j],target};
                    sort(sum.begin(),sum.end());
                    for(auto arr :sequence){
                        int flag = 0;
                        for(int k = 0; k<arr.size();k++){
                            if(arr[k]==sum[k]){
                                flag++;
                            }
                        }
                        if(flag!=3){
                            
                        }
                    }
                    
                }
                data[arr1[j]]++;
            }
            data[arr1[i]]++;
        }
        return sequence;
    }
    
};
int main ()
{
    vector<int> arr1 = {1,6,3,5,7,8,9};
    vector<int> arr2 = {2,4,6,8,10};
    vector<int> arr3 = {11,13,15,17,19};
    Solution s;
    for(auto i:s.threeSum(arr1)){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
