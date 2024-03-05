#include <iostream>
#include <algorithm>
#include "playSystem.h"
#include "player.h"


const int MAX = 1000000;
const int MIN = -1000000;

/*
*   Main module
*
*
* Display Game logo and menu option
*/
void displayMenu()
{
       
        std::cout << "\t _____ _                  ___ " << std::endl;
        std::cout << "\t|_   _| |_  _ _ ___ ___  |_  )" << std::endl;
        std::cout << "\t  | | | ' \\| '_/ -_) -_)  / / " << std::endl;
        std::cout << "\t _|_|_|_||_|_| \\___\\___| /___|" << std::endl;
        std::cout << "\t| __(_)/ _| |_ ___ ___ _ _    " << std::endl;
        std::cout << "\t| _|| |  _|  _/ -_) -_) ' \\" << std::endl;
        std::cout << "\t|_| |_|_|  \\__\\___\\___|_||_| " << std::endl;

        std::cout << "\n\n" ;

        std::cout << "\t\t1. Play" << std::endl;
        std::cout << "\t\t2. Play versus AI" << std::endl;
        std::cout << "\t\t3. Rules" << std::endl;
        std::cout << "\t\t4. Exit" << std::endl;
}

/*
       Display Rules of game
*/


/*
*   Main module
*
*
*
*/
void displayRules()
{
    system("CLS");
    std::cout << "\n\n" <<"Rules" << std::endl;
    std::cout << "1. To win, you must have three numbers sum up to fifteen." << std::endl;   
    std::cout << "2. The numbers are 1, 2, 3, 4, 5, 6, 7, 8, 9" << std::endl;
    std::cout << "3. Each player takes it in turns to choose one of the whole numbers 1 to 9." << std::endl;
    std::cout << "4. Each number can be chosen only once." << std::endl;
    std::cout << "5. If all numbers were selected and neither player has a certain three number sum up to 15, then draw.\n" << std::endl;
    system("PAUSE");

}

/*
*   Main module
*
*
*
*/

/*
       Main module. 
       Player against Player
*/

>>>>>>> f3eda51f66d03bea5dc1642a555b115d136e44fb
void play(){
    std::vector<int> box {1,2,3,4,5,6,7,8,9}; // number that user can select.
    Player player1(1);
    Player player2(2);
    Player* pPlayer; // pointer to Player
    int preTurn {}; // value 1 means player one, 2 means player two, defualt is 0.
    int turn {0};

    system("CLS");
    while(!box.empty())
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
            std::cout << "Error Alert: pointer player is empty." << std::endl;
        }
        else{
                
                std::cout << std::endl << "=======================================" << std::endl; 
                std::cout << "Turn: " << turn+1 << " Player: " << pPlayer->getID() << std::endl;
                std::cout << "\nYou can only select number below:\n" ;
                for (size_t i {}; i < box.size(); i++){
                    if (box[i] != 0){
                        std::cout << box[i] << " ";
                    }    
                }
                std::cout << std::endl << "=======================================" << std::endl;
                player1.display();
                player2.display();
                pPlayer->selectNumber(box);
                if (pPlayer->checkWinner() == true){
                    std::cout << "\n" << "Congrats!! Player " << pPlayer->getID() << " [win]!!" << std::endl;
                    std::cout << "\n--------------------END--------------------" << std::endl;
                    player1.display();
                    player2.display();
                    std::cout << std::endl;
                    system("PAUSE");
                    break;
                }
                else{
                    turn++;
                }
        }


    }
    // if nobody win until box is empty then draw
    if( player1.checkWinner() == false && player2.checkWinner() == false){
        std::cout << std::endl;
        std::cout << "     /\\~-_" << std::endl;
        std::cout << "   =(o^o = 7" << std::endl;
        std::cout << "----O--O---------" << std::endl;
        std::cout << "|     Draw ! ~  |" << std::endl;
        std::cout << "-----------------" << std::endl; 
        system("PAUSE");
    }

  delete(pPlayer);
}



// Find left numbers that can select
std::vector<int> possibleMove(std::vector<int> box)
{
    std::vector<int> moves;
    for (auto num : box){
        if (num != 0){
            moves.push_back(num);
        }
    }
    return moves;
}


// Minimax algorithm
int minimax(std::vector<int> &copyBox, Player player1, Player player2, bool isMax)
{
    
    if (player1.checkWinner() == true && player2.checkWinner() == false) {
        return -10;
    }
    else if (player1.checkWinner() == false && player2.checkWinner() == true) {
        return 10;
    }
    else if (copyBox.empty() && player1.checkWinner() == false && player2.checkWinner() == false) {
        return 0;
    }

    std::vector<int> moves = possibleMove(copyBox);
   
    
    
    
    if (isMax) {
        int bestScore = MIN;
        for (auto move : moves) {
            player2.pushNum(move);
            std::vector<int>::iterator it = find(copyBox.begin(),copyBox.end(),move);
            copyBox.erase(it);
            int score = minimax(copyBox,player1,player2,false);
            copyBox.push_back(move);
            player2.popNum();
            bestScore = std::max(score,bestScore);
        }
        return bestScore;
    }
    else {
        int bestScore = MAX;
        for (auto move : moves) {
            player1.pushNum(move);
            std::vector<int>::iterator it = find(copyBox.begin(),copyBox.end(),move);
            copyBox.erase(it);
            int score = minimax(copyBox,player1,player2,true);
            copyBox.push_back(move);
            player1.popNum();
            bestScore = std::min(score,bestScore);
        }
        return bestScore;
    }

}



// Find best move for ai
int findBestMove(std::vector<int> copyBox, Player user, Player ai)
{
    int bestScore = MIN;
    int bestMove {};
    auto moves = possibleMove(copyBox);
    for (auto move : moves) {
        ai.pushNum(move);
        std::vector<int>::iterator it = find(copyBox.begin(),copyBox.end(),move);
        copyBox.erase(it);
        int score = minimax(copyBox,user,ai,false); 
        copyBox.push_back(move);
        ai.popNum();
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;       
        }
    }
    return bestMove;
}


/*
*   Main module
*
*
*
*/

void playWithAI()
{
    std::vector<int> box {1,2,3,4,5,6,7,8,9};
    Player user(1);
    Player ai(2);
    int preTurn {};

    while (!box.empty()){
        system("CLS");
        if(preTurn == 1){
            // ai part
            preTurn = 2;
            std::cout << std::endl << "=======================================" << std::endl; 
            std::cout << "Turn: AI (Player 2)" << std::endl;
            std::cout << "\nIt will select number below:\n" ;
            for (size_t i {}; i < box.size(); i++){
                if (box[i] != 0){
                    std::cout << box[i] << " ";
                }    
            }
            std::cout << std::endl << "=======================================" << std::endl;
            user.display();
            ai.display();
            int num = findBestMove(box,user,ai);
            ai.pushNum(num);
            std::vector<int>::iterator it = find(box.begin(),box.end(),num);
            box.erase(it);
            std::cout << "AI selected " << num << std::endl;
            system("PAUSE"); 
            if (ai.checkWinner() == true){
                std::cout << "\n" << "AI against you !! Human [Lose]!!" << std::endl;
                std::cout << "\n--------------------END--------------------" << std::endl;
                user.display();
                ai.display();
                std::cout << std::endl;
                system("PAUSE");
                break;
            }
           
        }
        else{
            // human part
            preTurn = 1;
            std::cout << std::endl << "=======================================" << std::endl; 
            std::cout << "Turn: Human (Player 1)" << std::endl;
            std::cout << "\nYou can only select number below:\n" ;
            for (size_t i {}; i < box.size(); i++){
                if (box[i] != 0){
                    std::cout << box[i] << " ";
                }    
            }
            std::cout << std::endl << "=======================================" << std::endl;
            user.display();
            ai.display();
            user.selectNumber(box);
            if (user.checkWinner() == true){
                std::cout << "\n" << "Congrats!! Human [win]!!" << std::endl;
                std::cout << "\n--------------------END--------------------" << std::endl;
                user.display();
                ai.display();
                std::cout << std::endl;
                system("PAUSE");
                break;
           
        }
    }
    }
        

    if (user.checkWinner() == false && ai.checkWinner() == false) {
        std::cout << std::endl;
        std::cout << "     /\\~-_" << std::endl;
        std::cout << "   =(o^o = 7" << std::endl;
        std::cout << "----O--O---------" << std::endl;
        std::cout << "|     Draw ! ~  |" << std::endl;
        std::cout << "-----------------" << std::endl; 
        system("PAUSE");

    }
}
