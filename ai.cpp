
#include <iostream>
#include "ai.h"
#include "player.h"

using namespace std;


AI::AI(Player &user){this->player = &user;}
AI::~AI(){delete player;}

void AI::selectNumber(std::vector<int> &box)
{
 

}

void AI::test()
{
     cout<<player->getID();
}
