#ifndef PLAYER_H
#define PLAYER_H

#include <vector>


class Player{
protected:
    int id; 
    std::vector<int> numbers; // store selected number of each player.
public:
    Player(int id);
    virtual ~Player();
    int getID() const;
    virtual void selectNumber(std::vector<int> &box);
    bool checkWinner();
    void display() const;
    

};


#endif