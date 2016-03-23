nclude <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

struct ErrorLog{
    string name;
    string line;
    int count;
};
ErrorLog CreateErrorLog(string name,string line){
    ErrorLog log;
    int nameSize = name.size();
    int index = -1;
    for(int i = nameSize - 1;i >= 0;--i){
        if(name[i] == '\\'){
            index = i;
            break;
        }
    }
    name = name.substr(index+1);
    nameSize = name.size();
    if(nameSize > 16){
        name = name.substr(nameSize-16);
    }
    log.name = name;
    log.line = line;
    log.count = 1;
    return log;
}
void RecordErrorLog(int &number,ErrorLog log,vector<ErrorLog> &result){
    int size = result.size();
    bool isRepeat = false;
    for(int i = 0;i < size;++i){
        if(log.name == result[i].name && log.line == result[i].line){
            ++result[i].count;
            isRepeat = true;
            break;
        }
    }
    if(!isRepeat){
        if(size < 8){
            result.push_back(log);
        }
        else{
            result[number%8] = log;
        }
        ++number;
    }
}

int main(){
    string str;
    vector<ErrorLog> result;
    string name,line;

    int number = 0;
    while(cin>>name>>line){
        ErrorLog log = CreateErrorLog(name,line);
        RecordErrorLog(number,log,result);
    }
    for(int i = 0;i < result.size();++i){
        cout<<result[i].name<<" "<<result[i].line<<" "<<result[i].count<<endl;
    }
    return 0;
}
