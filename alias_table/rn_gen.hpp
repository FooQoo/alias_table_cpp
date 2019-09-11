#ifndef _RN_GEN_TABLE_H_
#define _RN_GEN_TABLE_H_

#include <random>

// 標準ライブラリはstdに保存される
using namespace std;

class Rn_gen
{
private:
    uniform_int_distribution<int> uid;
    uniform_real_distribution<> rid;
    mt19937 mt;
public:
    Rn_gen();
    Rn_gen(int n);
    ~Rn_gen();
    int get_int();
    double get_real();
};
#endif