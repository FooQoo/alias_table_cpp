#include "rn_gen.h"
#include <random>

using namespace std;

Rn_gen::Rn_gen(int n)
{
    this->mt.seed(0);
    uniform_int_distribution<> int_dist(0,n-1);
    uniform_real_distribution<> real_dist(0.0, 1.0);
    this->uid = int_dist;
    this->rid = real_dist;
}

Rn_gen::Rn_gen()
{
    Rn_gen(1);
}

Rn_gen::~Rn_gen()
{
}

int Rn_gen::get_int()
{
    return this->uid(this->mt);
}

double Rn_gen::get_real()
{
    return this->rid(this->mt);
}



