//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/21/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//For example, Given [100, 4, 200, 1, 3, 2], the longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//Your algorithm should run in O(n) complexity.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    template <typename T>
    int longestConsecutiveSequence(vector<T>& arr1){
        int sequence = 0;
        unordered_map<int, bool> data;
        for(int i=0; i<arr1.size(); i++){
            data[arr1[i]]=true;
        }
        for(auto i:arr1){
            int length = 1;
            if(data[i]){
                for(int j = i+1;data.find(j)!=data.end();j++){
                    length++;
                }
                for(int j = i-1;data.find(j)!=data.end();j--){
                    length++;
                }
            }else{
                continue;
            }
            sequence = sequence>length?sequence:length;
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
    cout<<s.longestConsecutiveSequence(arr2)<<endl;
    return 0;
}
