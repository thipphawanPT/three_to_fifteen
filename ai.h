#ifndef AI_H
#define AI_H
#include "player.h"
#include <vector>







class AI:public Player{

public:
    AI(int id);
    virtual ~AI();
    virtual void selectNumber(std::vector<int> &box) override;
};



#endif