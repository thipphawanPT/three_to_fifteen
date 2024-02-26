#ifndef PLAYER_H
#define PLAYER_H

#include <vector>


class Player{
private:
    int id; 
public:
    Player();
    Player(int id); 
    virtual ~Player();
    int getID() const;
    std::vector<int> numbers; // store selected number of each player.
    virtual void selectNumber(std::vector<int> &box);
    bool checkWinner();
    void display() const;
    

};


#endif