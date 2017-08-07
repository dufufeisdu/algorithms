//
//  main.cpp
//  findDistance_Dijkstra
//
//  Created by FUFEI DU on 6/27/17.
//  Copyright © 2017 FUFEI DU. All rights reserved.
//
//1 read Data
//2 search
//3 output certain value

#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <fstream>
#include <unordered_map>
#include <queue>
using namespace std;
#define MAX_DISTANCE 1000000

class FindDistance_Dijkstra{
private:
    int start;
    string fileName;
    vector<vector<vector <int>>> data;
    unordered_map<int, int> distanceToStart;
    unordered_map<int, int> router;
public:
    FindDistance_Dijkstra(int start,string fileName){
        this->fileName = fileName;
        this->start = start;
        readFile();
        //key algorithem start here:
        calDistance(start);
    }
    void calDistance(int start){
        //init start point's parent and distance
        router[start] = 0;
        distanceToStart[start] = 0;
        auto comp = [](vector<int> left,vector<int>right){return left[1]>right[1];};
        priority_queue<vector<int>,vector<vector<int>>,decltype(comp)> heapNode(comp);
        //the first node is the start point
        //data structure: [[[itself,0][vetex,edge],[...],[...]],[..],[..]]
        vector<vector<int>> node = data[0];
            for(int i = 1; i<node.size(); i++){
                   heapNode.push(node[i]);
                   router[node[i][0]] = node[0][0];
            }
        //
        unordered_map<int, int> distanceToSta;
            while(!heapNode.empty()){
                vector<int> current = heapNode.top();
                int vetex = current[0];
                int distance = current[1];
                //
                distanceToSta = distanceToStart;
                if(distanceToStart.find(vetex)==distanceToStart.end()){
                    distanceToStart[vetex] = distance;
                }
                heapNode.pop();
                vector<vector<int>> next = data[vetex-1];
                for(int i = 1; i<next.size();i++){
                    if(distanceToStart.find(next[i][0])==distanceToStart.end()){
                        next[i][1] = next[i][1]+distance;
                        heapNode.push(next[i]);
                        router[next[i][0]]=vetex;
                    }
                }
                
           }
    }
    int distance(int point){
        return distanceToStart[point];
    }
    void readFile(){
        fstream f(fileName,ios::in);
        string dataLine;
        if(f.is_open()){
            while (f.good()) {
                getline(f,dataLine);
                if(dataLine!=""){
                   data.push_back(extractDataFromLine(dataLine)) ;
                }
            }
            
        }else{
            cout<<"Cannot open file "<<fileName<<endl;
        }
    }
    vector<vector<int>> extractDataFromLine(string s){
        int vertex;
        vector<vector<int>> line;
        vector<int> tup;
        //extract head:
        int i = 0;
        for(; i<s.length(); i++){
            if(s[i]==' '||s[i]=='\t'){
                break;
            }
        }
        vertex = stoi(s.substr(0,i));
        tup.push_back(vertex);
        tup.push_back(MAX_DISTANCE);
        line.push_back(tup);
        //extract nodes
        while(i<s.length()){
            int count=0;
            while(i+count<s.length()&&s[i+count]!=','){
                count++;
            }
            int ver;
            if(s.substr(i,count)!="\t\r"){
                ver= stoi(s.substr(i,count));
            }else{
                break;
            }
            tup.clear();
            tup.push_back(ver);
            i+=count;
            count = 0;
            while (i+count<s.length()&&s[i+count]!=' '&&s[i+count]!='\t') {
                count++;
            }
            int dist = stoi(s.substr(i+1,count));
            tup.push_back(dist);
            line.push_back(tup);
            i+=count;
        }
        return line;
    }
};
int main(int argc, const char * argv[]) {
    int startPoint = 1;
    string fileName = "dijkstraData.txt";
    FindDistance_Dijkstra f(startPoint,fileName);
    vector<int> des = {7,37,59,82,99,115,133,165,188,197};
    for (int i = 0; i<des.size(); i++) {
        cout<<f.distance(des[i])<<",";
    }
    return 0;
}
