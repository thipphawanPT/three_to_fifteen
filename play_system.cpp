#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>
#include "play_system.h"

using namespace std;


/* Check number function
*  vector - 
*  return 
*/
int check_number(std::vector<int> &vec);

/* Check turn function 
*  int round - get the round to figure out whose turn
*  odd round is for player 1 and even round is for player 2.
*  return number 1 and 2 for identify player.
*/
int check_turn(int round);


/* Check winner function 
*  int round - get the round to figure out whose turn
*  vec - player
*  return number 1 and 2 for identify winner player.
*/
int check_winner(std::vector<int> &vec1,std::vector<int> &vec2, int round);




int check_winner(std::vector<int> &vec1,std::vector<int> &vec2, int round){
    int res1 {};
    int res2 {};
    int winner{};
    for(size_t i {}; i < vec1.size(); i++)
    {
        res1 = vec1[i]+res1;
    }
    for (size_t i = 0; i < vec2.size(); i++)
    {
        res2 = vec2[i]+res2;
    }
    
    if (res1 == 15 && round >= 5)
        {
            cout << "Winner: Player 1 !!!" << endl;
            return 1;
        }
    else if (res2 == 15 && round == 6)
        {   
            cout << "Winner: Player 2 !!!" << endl;
            return 1;
        }
    else if (res1 != 15 && res2 != 15 && round == 6)
        {
            cout << endl;
            cout << "     /\\~-_" << endl;
            cout << "   =(o^o = 7" << endl;
            cout << "----O--O---------" << endl;
            cout << "|     Draw ! ~  |" << endl;
            cout << "-----------------" << endl;
                             
            return 1;
        }
    else
    {
        return 0;
    }
}


int check_turn(int round){
    if (round%2 == 0)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

int check_number(std::vector<int> &vec){
    string str;
    vector<int> *box = &vec;
    int res{};
    while(true){
        int letter {};
        
        cout << endl << "You select: ";
        cin >> str;
        for(size_t i {} ; i < str.length(); i++)
        {
            if (isdigit(str[i]) == false)
            {
                letter = letter + 1;
            }   
        }

        if(letter > 0)
        {
            cout << "Error: only digit is required\n";
            continue;
        }
        else
        {
            int num = stoi(str);
    
            if (num >= 1 && num <= 9)
            {
                vector<int>::iterator it = find(box->begin(),box->end(),num);
                if(it != box->end())
                {
                    res = *it;
                    box->erase(it);
                    break;

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

    
    return res;
    
}





void play_system(){
    // Declare variables
    vector<int> box {1,2,3,4,5,6,7,8,9}; // number that user can select.
    vector<int> player_one {0,0,0};
    vector<int> player_two {0,0,0};
    vector<int> *player {nullptr};
    int turn {1}; 
    int pre_turn {}; // value 1 means player one, 2 means player two, defualt is 0.
    int num{};
    string str; // number that player select
    bool cont = true; // use for while loop
    int m{};


    system("CLS");
    while(cont)
    {   
        system("CLS");
        // see whose turn and assign to player
        if (pre_turn == 1){
            player = &player_two;
            pre_turn = 2;
        }
        else{
            player = &player_one;
            pre_turn = 1;
        }

        if(player == nullptr)
        {
            cout << "Error Alert:001" << endl;
        }
        else
        {
            cout << endl << "=======================================" <<endl;
            cout << "Turn: " << turn << " Player: ";
            cout << "\nYou can only select number below:\n" ;
            for (size_t i {}; i < box.size(); i++)
            {
                if (box[i] != 0)
                {
                    cout << box[i] << " ";
                } 
            }
            cout << endl << "=======================================" << endl;
            cout << "Player 1 selected: " << player_one[0] << " " << player_one[1] << " " << player_one[2] << " (" << player_one[0]+player_one[1]+player_one[2] << ")" << endl;
            cout << "Player 2 selected: " << player_two[0] << " " << player_two[1] << " " << player_two[2] << " (" << player_two[0]+player_two[1]+player_two[2] << ")" << endl;
            cout << "---------------------------------------";
            num = check_number(box);
            player->at(m) = num;
            if(turn%2 == 0)
            {
                m++;
            }
            
            if(check_winner(player_one,player_two,turn) == 1)
                {
                    
                    while (1)
                    {
                        
                        cout << "Play again? [y/n] ";
                        string sel{};
                        cin >> ws;
                        getline(cin,sel,'\n');
                        if(sel == "y" || sel == "Y")
                        {
                            turn = 1;
                            box = {1,2,3,4,5,6,7,8,9};
                            player_one = {0,0,0};
                            player_two = {0,0,0};
                            m = 0;
                            
                            break;
                        }
                        else if (sel == "n" || sel == "N")
                        {
                            cont = false;
                            break;
                        }
                        else
                        {
                            cout << endl<<"Error: you can insert only y or n" << endl;
                            continue;
                        }
                      
                    }
                    
                }
            else
            {
                turn++;
            }


        }
    }


}
