#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "cell.h"

class Animal : public Cell{
    public:
    double similarity(Animal& another);
    bool operator==(Animal& animal);
    Animal asexual_reproduction();
    Animal operator+(Animal& partner);
    void cell_death();
};
