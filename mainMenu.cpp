#include <iostream>
#include <algorithm>
#include "playSystem.h"

using namespace std;




int main()
    {
   

    bool cont{true};
    while (cont)
    {
        system("CLS");
        displayMenu();
        
        int opt {};
        cout << "\nPlease type number (1-3) to select:  ";

        // Validate the user input
        
        char buffer[128];
        fgets(buffer,128,stdin);
        sscanf(buffer,"%d",&opt);
        if (opt == 1 | opt == 2 | opt == 3 | opt == 4)
        {
            switch (opt)
            {
            case 1:
                play();
                break;
            case 2:
                playWithAI();
                break;
            case 3:
                displayRules();
                break;
            case 4:
                return 0;
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "[ERROR] Please type 1,2,3 or 4" << endl << flush;
    
            system("PAUSE");
        }
    }


 
   
    }
