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
        if (opt == 1 | opt == 2 | opt == 3)
        {
            switch (opt)
            {
            case 1:
                play();
                break;
            case 2:
                displayRules();
                break;
            case 3:
                cont = false;
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "[ERROR] Please type 1,2 or 3" << endl << flush;
    
            system("PAUSE");
        }
    }


 
    return 0;
    }
