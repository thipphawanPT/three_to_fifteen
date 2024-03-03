#ifndef PLAYER_H
#define PLAYER_H

#include <vector>


class Player{
private:
    int id;
    std::vector<int> numbers; // store selected number of each player. 
public:
    Player();
    Player(int id); 
    ~Player();
    int getID() const;
    std::vector<int> getNumbers() const;
    bool selectNumber(std::vector<int> &box);
    void pushNum(int num); // push integer into vector numbers
    void popNum(); // pop last integer out from vector numbers
    bool checkWinner(); // check that this player is winner or not
    void display() const; // display integer in vector numbers
    

};


#endif