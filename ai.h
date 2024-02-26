#ifndef AI_H
#define AI_H
#include <vector>
#include "player.h"


class AI:public Player{

public:
    AI();
    ~AI();
    //virtual void selectNumber(std::vector<int> &box) override;
    void displayOther(std::vector<int> other);

};




#endif