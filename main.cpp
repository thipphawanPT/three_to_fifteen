#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>


using namespace std;

void play_system(){
    //dummy
    vector<int> box {1,2,3,4,5,6,7,8,9};
    vector<int> player_one {};
    vector<int> player_two {};
}

void display_rules()
{
    system("CLS");
    cout << "\n\n" <<"Rules" << endl;
    cout << "1. To win, you must have three numbers sum up to fifteen." << endl;   
    cout << "2. The numbers are 1, 2, 3, 4, 5, 6, 7, 8, 9" << endl;
    cout << "3. Each player takes it in turns to choose one of the whole numbers 1 to 9." << endl;
    cout << "4. Each number can be chosen only once." << endl;
    cout << "5. If each person has three numbers and neither player has a total of 15, then draw.\n" << endl;
    system("PAUSE");

}

void display_menu()
{
       
        cout << "\t _____ _                  ___ " << endl;
        cout << "\t|_   _| |_  _ _ ___ ___  |_  )" << endl;
        cout << "\t  | | | ' \\| '_/ -_) -_)  / / " << endl;
        cout << "\t _|_|_|_||_|_| \\___\\___| /___|" << endl;
        cout << "\t| __(_)/ _| |_ ___ ___ _ _    " << endl;
        cout << "\t| _|| |  _|  _/ -_) -_) ' \\" << endl;
        cout << "\t|_| |_|_|  \\__\\___\\___|_||_| " << endl;

        cout << "\n\n" ;

        cout << "\t\t1. Start" << endl;
        cout << "\t\t2. Rules" << endl;
        cout << "\t\t3. Exit" << endl;
}




int main()
    {
   

    bool cont{true};
    while (cont)
    {
        system("CLS");
        display_menu();
        
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
                play_system();
                break;
            case 2:
                display_rules();
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
