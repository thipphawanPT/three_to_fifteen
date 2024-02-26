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
        cout << "\t\t2. Play versus AI" << endl;
        cout << "\t\t3. Rules" << endl;
        cout << "\t\t4. Exit" << endl;
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
                    cout << "\n--------------------END--------------------" << endl;
                    player1.display();
                    player2.display();
                    cout << endl;
                    system("PAUSE");
                    break;
                }
                else if (turn == 8 && player1.checkWinner() == false && player2.checkWinner() == false){
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



void playWithAI()
{
    
}