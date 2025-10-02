#include <iostream>
#include <set>
#include <fstream>
#include <unordered_map>
#include <vector>
using namespace std;
const string FIRSTDAY = "firstday.csv";
const string SECONDDAY = "secondday.csv";
int main(){
    unordered_map<int, set<int>> map;
    set<int> visitedSame;
    set<int> visitedNew;
    ifstream firstDay;
    ifstream secondDay;
    string line ="";
    int first;
    int second;
    int loc =0;
    
    firstDay.open(FIRSTDAY);
    getline(firstDay, line);
    while(getline(firstDay, line)){ 
        loc = line.find(',');
        first = stoi(line.substr(0,loc));
        line = line.substr(loc+1, line.length());
        loc = line.find(',');
        second = stoi(line.substr(0,loc));

        if(map.find(first)==map.end()){
            map[first]={second};
        }else{
            map[first].insert(second);
        };
    };
    firstDay.close();
    secondDay.open(SECONDDAY);
    getline(secondDay, line);
    while (getline(secondDay, line))
    {
        loc = line.find(',');
        first = stoi(line.substr(0,loc));
        line = line.substr(loc+1, line.length());
        loc = line.find(',');
        second = stoi(line.substr(0,loc));

        if(map.find(first)!=map.end()){
            if(map[first].count(second)==1){
                visitedSame.insert(first);
            }else{
                visitedNew.insert(first);
            }
        }
    }
    secondDay.close();
    cout << "Users that visited the same page:" << endl;
    for (auto Id : visitedSame){
        cout << Id<<endl;
    };
    cout << "Users that visited a new page:" << endl;
    for (auto Id : visitedNew){
        cout << Id<<endl;
    };
};