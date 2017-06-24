//
//  main.cpp
//  findSCC
//
//  Created by FUFEI DU on 6/23/17.
//  Copyright © 2017 FUFEI DU. All rights reserved.
//  Find SCC in data.txt

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <stack>
using namespace std;
#define totalNumber 9
class FindSCC{
    int totalVertex;
    vector<list<int>> adjacenctList;
    vector<list<int>> rAdjacentList;
    vector<bool> isSearched;
    stack<int> order;
public:
    FindSCC(){
        readFile();
        vector<bool> temp(adjacenctList.size()+1,0);
        isSearched = temp;
        for(auto i:adjacenctList){
            for(auto j:i){
            cout<<j<<" ";
            }
            cout<<endl;
        }
        DFS(3);
        for (int i = 0; !order.empty(); i++) {
            cout<<order.top()<<endl;
            order.pop();
        }
    }
    void readFile(){

        string s ="dataTrail.txt";
        fstream f(s,ios::in );
        if(!f.is_open()){
            cout<<"fail to open "<<s<<endl;
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
    }
    
    void DFS(int n){
        const int len = (int)adjacenctList.size();
        if(n<0||n>len){
            cout<<"Invaild searchIndex"<<n<<endl;
        }else{
            int ele;
                ele = adjacenctList[n-1].front();
                if(ele!=0&&!isSearched[ele]){
                    isSearched[ele] = true;
                    adjacenctList[n-1].pop_front();
                    while(!adjacenctList[n-1].empty()){
                        DFS(adjacenctList[n-1].front());
                        adjacenctList[n-1].pop_front();
                    }
                    order.push(ele);
                }
            }

        
        
    }
    void reverseGraph(){
        
    
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    FindSCC findScc;
    
    return 0;
}
