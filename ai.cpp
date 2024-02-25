
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "ai.h"

int minimax()
{
    if(){
        
    }
}


AI::AI(int id):id{id}
{

}

AI::~AI()
{

}

void AI::selectNumber(std::vector<int> &box)
{
    int num{};
    if (num >= 1 && num <= 9)
    {
        vector<int>::iterator it = find(box.begin(),box.end(),num);
        if(it != box.end())
        {
            result = *it;
            this->numbers.push_back(result); 
            box.erase(it);
            break;

        }
    }

        
}
