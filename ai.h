#ifndef AI_H
#define AI_H
#include <vector>

class Player{};





class AI:public Player{
private:
public:
    AI();
    virtual ~AI();
    virtual void selectNumber(std::vector<int> &box) override;
    void test();

};



#endif