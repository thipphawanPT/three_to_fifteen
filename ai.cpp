#include <iostream>
#include "ai.h"

using namespace std;

AI::AI(){}
AI::~AI(){}

void AI::displayOther(std::vector<int> other)
{
     std::cout << "\n";
     for(auto num:other){
          std::cout<< num << " ";
     }
}


