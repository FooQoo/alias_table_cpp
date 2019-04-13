#include "alias_table.h"
#include <random>
#include <vector>
#include <numeric>
#include <iostream>
#include <map>

using namespace std;

Alias_table::Alias_table(vector<int> input_table)
{
    int n = input_table.size();
    int sum = accumulate(input_table.begin(), input_table.end(), 0);
    vector<double> smaller;
    vector<double> larger;
    
    // step 1 and 2
    for(int i=0; i<n; i++){
        double vk = (double)input_table[i]/sum*n;
        a.emplace_back(0);
        v.emplace_back(vk);
        if (vk >= 1){
            larger.emplace_back(i);
        } else {
            smaller.emplace_back(i);
        }
    }

    // step 3 - 6
    while (larger.size()>0 && smaller.size()>0){
        int l = larger.back();
        larger.pop_back();
        int s = smaller.back();
        smaller.pop_back();
        a[s] = l;
        v[l] = v[l]-(1.0-v[s]);

        if (v[l]<1.0){
            smaller.emplace_back(l);
        } else {
            larger.emplace_back(l);
        }
    }
}

Alias_table::~Alias_table()
{
}

int Alias_table::draw()
{
    int n = v.size();
    // 乱数部分 {}:一様初期化?
    mt19937 mt;
    mt.seed(0);
    uniform_int_distribution<int> int_dist(0,n-1);
    uniform_real_distribution<> real_dist(0.0, 1.0);
    int k = int_dist(mt);

    if (real_dist(mt)<v[k]){
        return k;
    } else {
        return a[k];
    }
}

map<int, int> Alias_table::draw_n(int num_samples)
{
    int n = v.size();
    // 乱数部分 {}:一様初期化?
    mt19937 mt;
    mt.seed(0);
    uniform_int_distribution<int> int_dist(0,n-1);
    uniform_real_distribution<> real_dist(0.0, 1.0);
    map<int, int> counter;
    int s, k;

    for(int i=0; i<num_samples; i++){
        k = int_dist(mt);

        if (real_dist(mt)<v[k]){
            s = k;
        } else {
            s = a[k];
        }

        if (counter.count(s) == 0){
            counter[s] = 0;
        } else {
            counter[s] += 1;
        }
    }
    return counter;
}