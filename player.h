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
    bool checkWinner();
    void display() const;
    

};


#endif