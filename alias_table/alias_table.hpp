#ifndef _ALIAS_TABLE_H_
#define _ALIAS_TABLE_H_

#include <random>
#include <vector>
#include <map>

// 標準ライブラリはstdに保存される
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
#endif