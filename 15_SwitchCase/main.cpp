#include <iostream>

using namespace std;

int main()
{
    char letterGrade{};
    cin >> letterGrade;
    switch (letterGrade)
    {
    case 'a':
    case 'A':
        cout << "You need a 90 or above, study hard!" << endl;
        break;
    case 'b':
    case 'B':
        cout << "You need 80-89 for B, go study!" << endl;
        break;
    case 'c':
    case 'C':
        cout << "You need 70-79 for an average grade" << endl;
        break;
    case 'd':
    case 'D':
        cout << "Hmm, you should strive for better grade. All you need is 60-69" << endl;
        break;
    case 'f':
    case 'F':
    {
        char confirm{};
        cout << "Are you sure (Y/N)? ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y')
            cout << "Ok, i guess you didn't study..." << endl;
        else if (confirm == 'n' || confirm == 'N')
            cout << "Good, go to study" << endl;
        else
            cout << "Illegal choise" << endl;
        break;
    }
    default:
        cout << "Sorry, not a valid grade" << endl;
    }

    /*
    ------------------------------------------------------
    */

   enum direction{
    left,right,up,down
   };

   direction heding{left};

   switch (heding)
   {
   case left:
    cout << "Go left"<< endl;
    break;
   case right:
    cout << "Go right"<< endl;
    break;    
   
   default:
    break;
   }
}