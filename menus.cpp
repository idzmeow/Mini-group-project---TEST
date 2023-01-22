#include <iostream>
#include <iomanip>
using namespace std;

//functions
void writestd();	
void displayAll();	
void displaySP(int);	
void modifystd(int);	
void deletestd(int);	
void classResults();	
void results();		
void introduction();		
void entry_menu();

//Results Menu
void results(){

    char choice;
    int matricno;

    system("cls");

    cout << "\n\n\t\t\t\t\t RESULTS MENU" << endl;
    cout << "\n\n\t\t\t\t\t 1. Class Results" << endl;
    cout << "\n\n\t\t\t\t\t 2. Student Report Card" << endl;
    cout << "\n\n\t\t\t\t\t 3. Return to Main Menu" << endl;
    cout << "\n\n\t\t\t\t\t Please enter your choice " << endl;

    cin >> choice;

    system ("cls");
    switch(choice){

        case '1' : classResults(); break;
        case '2' : cout << "Please enter your matric number " << endl;
                    cin >> matricno;
                    displaySP(matricno); break;
        case '3' : break;
        default : cout << "\a";
    }
}

//Student Entry Menu
void entry_menu(){

    char choice;
    int num3;
    system("cls");
    cout << "\n\n\t\t\t\t\tENTRY MENU" << endl;
    cout << "\n\n\t\t\t\t\t 1. Create new student records " << endl;
    cout << "\n\n\t\t\t\t\t 2. Display all registered students records " << endl;
    cout << "\n\n\t\t\t\t\t 3. Search student records " << endl;
    cout << "\n\n\t\t\t\t\t 4. Modify student records " << endl;
    cout << "\n\n\t\t\t\t\t 5. Delete student records " << endl;
    cout << "\n\n\t\t\t\t\t 6. Return to main menu " << endl;

    cout << "Please enter your choice" << endl;
    cin >> choice;

    system ("cls");
    switch(choice){
        case '1' : writestd();
                break;
        case '2' : displayAll();
                break;
        case '3' : cout << "\n\n\t\t\t\t\t Please enter your Matric Number " << endl;
                cin >> num3;
                displaySP(num3);
                break;
        case '4' : cout << "\n\n\t\t\t\t\t Please enter your Matric Number " << endl;
                cin >> num3;
                modifystd(num3);
                break;
        case '5' : cout << "\n\n\t\t\t\t\t Please enter your Matric Number " << endl;
                cin >> num3;
                deletestd(num3);
                break;
        case '6' : break;

        default : cout << "\a"; entry_menu();
    }
}

