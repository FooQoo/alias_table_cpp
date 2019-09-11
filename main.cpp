#include <iostream>
#include <random>
#include <vector>
#include <map>

using namespace std;

class Alias_table
{
private:
    vector<double> a;
    vector<double> v;
    uniform_int_distribution<int> uid;
    uniform_real_distribution<> rid;
    mt19937 mt;
    
public:
    Alias_table(vector<int> input_table);
    ~Alias_table();
    int draw();
    map<int, int> draw_n(int num_samples);
};

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

