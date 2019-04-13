#include <iostream>
#include <random>
#include <vector>
#include "alias_table.h"
#include <map>

using namespace std;

int main(){
    vector<int> vec = {1,1,100,1,1,100};
    Alias_table* tbl;
    tbl = new Alias_table(vec);
    map<int, int> dict;
    dict = tbl->draw_n(1000000);
    for(map<int, int>::iterator it=dict.begin(); it!=dict.end(); it++){
        cout << it->first << "=>" << it->second << endl;
    }
}

