#ifndef PLAYER_H
#define PLAYER_H

#include <vector>


class Player{
private:
    int id;
    std::vector<int> numbers {1,2,3}; // store selected number of each player. 
public:
    Player();
    Player(int id); 
    virtual ~Player();
    int getID() const;
    std::vector<int> getNumbers() const;
    virtual void selectNumber(std::vector<int> &box);
    bool checkWinner();
    void display() const;
    

};


class AI:public Player{

public:
    AI();
    ~AI();
    //virtual void selectNumber(std::vector<int> &box) override;
    void displayOther(std::vector<int> other);

};

#endif