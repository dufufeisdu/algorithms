//
//  main.cpp
//  Stanford_greedy_1
//
//  Created by FUFEI DU on 7/11/17.
//  Copyright © 2017 FUFEI DU. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class MinimizeCompleteTime{
private:
    vector<vector<int>> jobs;
    int totalJobsNumber;
    long weightedSum;
  int probNum;
  
public:
    MinimizeCompleteTime(string fileName,int prob){
        readFile(fileName);
        weightedSum = 0;
        probNum = prob;
        setDataExeOrder(prob);
        processData();
    }
    void processData(){
      long completeTime = 0;
        for(int i = 0; i<totalJobsNumber; i++){
            completeTime+=jobs[i][1];
          weightedSum+=completeTime*jobs[i][0];
        }
    }
    void setDataExeOrder(int n){
        if(n==1){
            sort(jobs.begin(),jobs.end(),[](vector<int> a, vector<int> b){
                if((a[0]-a[1])==(b[0]-b[1])){
                    return a[0]>b[0];
                }
                return (a[0]-a[1])>(b[0]-b[1]);});
        }
        if(n==2){
            sort(jobs.begin(),jobs.end(),[](vector<int>a,vector<int> b){return (double)a[0]/a[1]>(double)b[0]/b[1];});
        }
    }
    
    void readFile(string name){
        fstream fin(name,ios::in);
        if(fin.is_open()){
            fin>>totalJobsNumber;
            int weight,length;
            while(fin>>weight>>length){
                vector<int> buk = {weight,length};
                jobs.push_back(buk);
            }
        }else{
            cout<<"Cannot open file"<<name<<endl;
        }
    }
  long getResult(){
    return weightedSum;
  }
};
int main(int argc, const char * argv[]) {
  string fileName = "jobs.txt";
  MinimizeCompleteTime mc(fileName,1);
  cout<<"Problem 1 output:"<<mc.getResult()<<endl;
  MinimizeCompleteTime m(fileName,2);
  cout<<"Problem 2 output:"<<m.getResult()<<endl;
    return 0;
}
