#include <iostream>
#include <algorithm>
#include "playSystem.h"
#include "player.h"

using namespace std;



void displayMenu()
{
       
        cout << "\t _____ _                  ___ " << endl;
        cout << "\t|_   _| |_  _ _ ___ ___  |_  )" << endl;
        cout << "\t  | | | ' \\| '_/ -_) -_)  / / " << endl;
        cout << "\t _|_|_|_||_|_| \\___\\___| /___|" << endl;
        cout << "\t| __(_)/ _| |_ ___ ___ _ _    " << endl;
        cout << "\t| _|| |  _|  _/ -_) -_) ' \\" << endl;
        cout << "\t|_| |_|_|  \\__\\___\\___|_||_| " << endl;

        cout << "\n\n" ;

        cout << "\t\t1. Play" << endl;
        cout << "\t\t2. Rules" << endl;
        cout << "\t\t3. Exit" << endl;
}


void displayRules()
{
    system("CLS");
    cout << "\n\n" <<"Rules" << endl;
    cout << "1. To win, you must have three numbers sum up to fifteen." << endl;   
    cout << "2. The numbers are 1, 2, 3, 4, 5, 6, 7, 8, 9" << endl;
    cout << "3. Each player takes it in turns to choose one of the whole numbers 1 to 9." << endl;
    cout << "4. Each number can be chosen only once." << endl;
    cout << "5. If all numbers were selected and neither player has a certian three number sum up to 15, then draw.\n" << endl;
    system("PAUSE");

}


void play(){
    vector<int> box {1,2,3,4,5,6,7,8,9}; // number that user can select.
    Player player1(1);
    Player player2(2);
    Player* pPlayer;
    int preTurn {}; // value 1 means player one, 2 means player two, defualt is 0.
    int turn {0};
    bool cont = true;

    system("CLS");
    while(cont)
    {
        system("CLS");
        // See whose turn and assgn to pointer player
        if(preTurn == 1){
            pPlayer = &player2;
            preTurn = 2;
        }
        else{
            pPlayer = &player1;
            preTurn = 1;
        }

        // Validate pointer player
        if(pPlayer == nullptr){
            cout << "Error Alert: pointer player is empty." << endl;
        }
        else{
                
                cout << endl << "=======================================" <<endl; 
                cout << "Turn: " << turn+1 << " Player: " << pPlayer->getID() << endl;
                cout << "\nYou can only select number below:\n" ;
                for (size_t i {}; i < box.size(); i++){
                    if (box[i] != 0){
                        cout << box[i] << " ";
                    }    
                }
                cout << endl << "=======================================" << endl;
                player1.display();
                player2.display();
                pPlayer->selectNumber(box);
                if (pPlayer->checkWinner() == true){
                    cout << "\n" << "Congrats!! Player " << pPlayer->getID() << " [win]!!" << endl;
                    system("PAUSE");
                    break;
                }
                else if (turn >= 9 && player1.checkWinner() == false && player2.checkWinner() == false){
                    cout << endl;
                    cout << "     /\\~-_" << endl;
                    cout << "   =(o^o = 7" << endl;
                    cout << "----O--O---------" << endl;
                    cout << "|     Draw ! ~  |" << endl;
                    cout << "-----------------" << endl; 
                    system("PAUSE");
                    break;
                }
                else{
                    turn++;
                }
        }


    }
  


}




  //  while(cont)
    // {   
    //     system("CLS");
    //     // see whose turn and assign to player
    //     if (pre_turn == 1){
    //         player = &player_two;
    //         pre_turn = 2;
    //     }
    //     else{
    //         player = &player_one;
    //         pre_turn = 1;
    //     }

    //     if(player == nullptr)
    //     {
    //         cout << "Error Alert:001" << endl;
    //     }
    //     else
    //     {
    //         cout << endl << "=======================================" <<endl;
    //         cout << "Turn: " << turn << " Player: ";
    //         cout << "\nYou can only select number below:\n" ;
    //         for (size_t i {}; i < box.size(); i++)
    //         {
    //             if (box[i] != 0)
    //             {
    //                 cout << box[i] << " ";
    //             } 
    //         }
    //         cout << endl << "=======================================" << endl;
    //         cout << "Player 1 selected: " << player_one[0] << " " << player_one[1] << " " << player_one[2] << " (" << player_one[0]+player_one[1]+player_one[2] << ")" << endl;
    //         cout << "Player 2 selected: " << player_two[0] << " " << player_two[1] << " " << player_two[2] << " (" << player_two[0]+player_two[1]+player_two[2] << ")" << endl;
    //         cout << "---------------------------------------";
    //         num = check_number(box);
    //         player->at(m) = num;
    //         if(turn%2 == 0)
    //         {
    //             m++;
    //         }
            
    //         if(check_winner(player_one,player_two,turn) == 1)
    //             {
                    
    //                 while (1)
    //                 {
                        
    //                     cout << "Play again? [y/n] ";
    //                     string sel{};
    //                     cin >> ws;
    //                     getline(cin,sel,'\n');
    //                     if(sel == "y" || sel == "Y")
    //                     {
    //                         turn = 1;
    //                         box = {1,2,3,4,5,6,7,8,9};
    //                         player_one = {0,0,0};
    //                         player_two = {0,0,0};
    //                         m = 0;
                            
    //                         break;
    //                     }
    //                     else if (sel == "n" || sel == "N")
    //                     {
    //                         cont = false;
    //                         break;
    //                     }
    //                     else
    //                     {
    //                         cout << endl<<"Error: you can insert only y or n" << endl;
    //                         continue;
    //                     }
                      
    //                 }
                    
    //             }
    //         else
    //         {
    //             turn++;
    //         }


    //     }
    // }


 





