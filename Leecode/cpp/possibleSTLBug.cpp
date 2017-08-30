//
//  main.cpp
//  Test
//
//  Created by FUFEI DU on 6/22/17.
//  Copyright (c) 2017 FUFEI DU. All rights reserved.
//  Leecode practice:
// Bug of the STL or Xcode
// Description: the first element will always be 0 when using time(0) and %7

#include <iostream>
#include <ctime>
using namespace std;
class Solution {
public:
    void randBug(int start, int end){
        int ran_num;
        srand((unsigned)time(0));
        for(int i=0;i<10;i++){
            ran_num=rand() % 7;
            cout<<ran_num<<" ";
        }
    }
    
};
int main ()
{
    Solution s;
    s.randBug(0, 7);
    return 0;
}
