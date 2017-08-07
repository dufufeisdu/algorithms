//
//  main.cpp
//  Stanford_greedy_3
//
//  Created by FUFEI DU on 7/12/17.
//  Copyright © 2017 FUFEI DU. All rights reserved.

//  ** SHOULD AVOID SIDE EFFECT **

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_map>
using namespace std;
#define TOTALNODE 500
class Prim{
private:
  int totalNode;
  int totalEdges;
  long minSpanTreeLength;
  vector<int> visited;
  vector<vector<vector<int>>> fileData;
public:
  Prim(string fileName){
    visited = vector<int>(TOTALNODE+1,0);
    fileData = readFile(fileName);
    for(auto da: fileData){
      for(auto dd:da){
        for(auto dc:dd){
          cout<<dc<<" ";
        }
        cout<<";";
      }
      cout<<endl;
    }
    minSpanTreeLength = minSpanTree(fileData, visited);
  }
 
  long minSpanTree(vector<vector<vector<int>>> da, vector<int>& alreadyVisited){
    long treeLength = 0;
    auto comp = [](vector<int> left, vector<int>right){return left[1]>right[1];};
    priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> heap(comp);
    //push the first [1] element to the heap;
    for (int i = 0; i<da[1].size(); i++) {
      heap.push(da[1][i]);
    }
    alreadyVisited[1]=1;
//    while (heap.size()>0) {
//      cout<<heap.top()[0]<<" "<<heap.top()[1]<<endl;
//      heap.pop();
//    }
    while (heap.size()>0) {
      vector<int> tuple = heap.top();
      int vetex = tuple[0];
      int edge = tuple[1];
      bool isVisited =alreadyVisited[vetex];
      if(isVisited){
        heap.pop();
      }else{
        treeLength+=edge;
        alreadyVisited[vetex]=true;
        heap.pop();
        for(int i = 0; i<da[vetex].size(); i++){
          if(!alreadyVisited[da[vetex][i][0]]){
            heap.push(da[vetex][i]);
          }
        }
      }
    }
    return treeLength;
  }
  
  
  vector<vector<vector<int>>> readFile(string fn){
    vector<vector<vector<int>>> data ;
    int vetex,connected,length;
    fstream fin(fn,ios::in);
    
    if(fin.is_open()){
      fin>>totalNode>>totalEdges;
      
      for (int i = 0; i<totalNode+1; i++) {
        vector<vector<int>> temp;
        data.push_back(temp);
      }
      while(fin>>vetex>>connected>>length){
        vector<int> temp1 = {connected,length};
        vector<int> temp2 = {vetex,length};
        data[vetex].push_back(temp1);
        data[connected].push_back(temp2);
        
      }
    }else{
      cout<<"File not Open!"<<endl;
    }
    return data;
  }
  
  
  long result(){
    return minSpanTreeLength;
  }
};
int main(int argc, const char * argv[]) {
  Prim pm("edges.txt");
  cout<<pm.result()<<endl;
  return 0;
}
