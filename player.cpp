#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "player.h"

using namespace std;


Player::Player(){}
Player::Player(int id): id{id} {}
Player::~Player(){}




int Player::getID() const { return this->id; }




bool Player::selectNumber(std::vector<int> &box)
{
    string str;
    int result{};
    /* Loop until user enter validated input*/
    while(true){
        int letterCount {};
        
        // get input from user.
        cout << endl << "You select: ";
        cin >> ws; // extract whitespace
        getline(cin,str,'\n');
        // check that are there letter in input
        for(size_t i {} ; i < str.length(); i++)
        {
            if (isdigit(str[i]) == false)
            {
                letterCount += 1;
            }   
        }

        if(letterCount > 0)
        {
            cout << "Error: only digit is required\n";
            continue;
        }
        else
        {
            int num = stoi(str);
            // get input to vector numbers
            if (num >= 1 && num <= 9)
            {
                vector<int>::iterator it = find(box.begin(),box.end(),num);
                if(it != box.end())
                {
                    result = *it;
                    this->numbers.push_back(result); 
                    box.erase(it);
                    return true;

                }
                else
                {
                    cout << "Error: your selected number is none\n";
                }
            }
            else
            {
                cout << "Error: your selected number is none\n";
                continue;

            }
        }
    }

    
    
}


// find the certain three numbers that sum up to fifteen
bool Player::checkWinner()
{
    
    for(auto n1 : this->numbers){
        int total{};
        for(auto n2 : this->numbers){
            if(n2 != n1){
                for(auto n3 : this->numbers){
                    if(n3 != n2 && n3 != n1){
                        total = n1+n2+n3;
                    }
                }
            }
        }
        if(total == 15){
            return true;
        }
    }

    return false;
}

void Player::display() const
{
    cout << "Player " << this->id << " selected: ";
    if (numbers.empty() == true){
        cout << " ";
    }
    else{
        for(auto num : numbers){
            cout << num << " ";
        }   
    }

    cout << endl;
}

void Player::pushNum(int num)
{
    this->numbers.push_back(num);
}

void Player::popNum()
{
    this->numbers.pop_back();
}