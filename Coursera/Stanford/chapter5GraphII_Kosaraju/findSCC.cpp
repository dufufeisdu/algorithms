//
//  main.cpp
//  findSCC
//
//  Created by FUFEI DU on 6/23/17.
//  Copyright © 2017 FUFEI DU. All rights reserved.
//  Description: Find six biggest SCC length in data.txt graph
//  Note: If you are using XCode you should add "-Wl,-stack_size,10000000" (without quote) to the "other link flag" in Xcode
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;
class FindSCC{
    string fileName;
    int SCCLength;
    vector<list<int>> adjacenctList;
    vector<bool> isSearched;
    vector<int> order;
    vector<int> result;
public:
    FindSCC(){
        fileName ="data.txt";
        SCCLength = 0;
        readFile();
        vector<bool> temp(adjacenctList.size()+1,false);
        isSearched = temp;
        search();
        reverseGraph();
        checkGraph();
        reverseSerach();
    }
    void readFile(){
        fstream f(fileName,ios::in );
        if(!f.is_open()){
            cout<<"fail to open "<<fileName<<endl;
        }else{
            int vertex;
            int cVertex;
            int i = 1;
            list<int> ls;
            ls.push_back(i);
            while (f>>vertex>>cVertex) {
                //this while loop is for vertex that have not point to other vertex
                while(vertex>i+1){
                    adjacenctList.push_back(ls);
                    ls.clear();
                    ls.push_back(++i);
                }
                //this happens when vertex changes in data file
                if(vertex==(i+1)){
                    adjacenctList.push_back(ls);
                    ls.clear();
                    ls.push_back(vertex);
                    ls.push_back(cVertex);
                    i++;
                }else{
                    ls.push_back(cVertex);
                }
            }
            adjacenctList.push_back(ls);
        }
        f.close();
    }
    void DFS(int n){
        if(!adjacenctList[n-1].empty()){
            int ele = adjacenctList[n-1].front();
            if(!isSearched[ele]){
                isSearched[ele] = true;
                adjacenctList[n-1].pop_front();
                while(!adjacenctList[n-1].empty()){
                    DFS(adjacenctList[n-1].front());
                    adjacenctList[n-1].pop_front();
                }
                order.push_back(ele);
            }
        }
        
    }
    void search(){
        for (int i = 1; i<=adjacenctList.size(); i++) {
            DFS(i);
        }
    }
    //the Data is tooooo big, repeat this to save memory
    void RDFS(int n){
        if(!adjacenctList[n-1].empty()){
            int ele = adjacenctList[n-1].front();
            //now isSearched contains all true value
            if(isSearched[ele]){
                isSearched[ele] = false;
                SCCLength++;
                adjacenctList[n-1].pop_front();
                while (!adjacenctList[n-1].empty()) {
                    RDFS(adjacenctList[n-1].front());
                    adjacenctList[n-1].pop_front();
                }
            }
        }
        
    }
    void reverseSerach(){
        for (int i = 0; !order.empty(); i++) {
            RDFS(order.back());
            order.pop_back();
            if(result.size()<6){
                result.push_back(SCCLength);
            }else{
                result.push_back(SCCLength);
                sort(result.begin(),result.end(),[](int a,int b){
                    return b<a;
                });
                result.pop_back();
                
            }
            SCCLength = 0;
        }
    }
    void reverseGraph(){
        //to avoid using too much memory, use adjecentlist and reading from file again;
        fstream f(fileName,ios::in);
        int vertex;
        int cVertex;
        if(!f.is_open()){
            cout<<"fail to open"<<fileName<<endl;
        }else{
            while(f>>vertex>>cVertex){
                if(adjacenctList[cVertex-1].empty()){
                    adjacenctList[cVertex-1].push_back(cVertex);
                    adjacenctList[cVertex-1].push_back(vertex);
                }else{
                    adjacenctList[cVertex-1].push_back(vertex);
                }
            }
        }
    }
    void checkGraph(){
        for(int i = 0; i<adjacenctList.size();i++){
            if(!adjacenctList[i].size()){
                adjacenctList[i].push_back(i+1);
            }
        }
    }
    vector<int> getResult(){
        return result;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    FindSCC findScc;
    vector<int> results =  findScc.getResult();
    for(auto result:results){
        cout<<result<<" ";
    }
    return 0;
}
