#include <iostream>
#include <iomanip>
#include <fstream>

#include "menus.cpp"
#include "results.cpp"

using namespace std;

//Please run the code from main.cpp otherwise the program will not work.

//Intro
void introduction(){

        cout << "\n\n\t\t\t\t\tSTUDENT REPORT CARD SYSTEM" << endl;
        cout << "\n\n\t\t\t\t\t By Group 36 :D" << endl;
        cout << "\n\n\t\t\t\t\tKampus Kejuruteraan Universiti Sains Malaysia" << endl;
        cout << "\n\n\t\t\t\t\tPlease open this window in fullscreen" << endl;
        cin.get();       
}

//Main Menu
int main()
{
	char choice;
	cout.setf(ios::fixed|ios::showpoint);
	cout<<setprecision(2); 
	introduction();

	do{

		system("cls");
		cout << "\n\n\n\t\t\t\tMAIN MENU ";
		cout << "\n\n\t\t\t\t\t1. RESULT ";
		cout << "\n\n\t\t\t\t\t2. ENTRY/EDIT ";
		cout << "\n\n\t\t\t\t\t3. EXIT ";
		cout << "\n\n\t\t\t\t\tPlease Select Your Option (1-3) " << endl;
		cin >> choice;

		switch(choice)
		{
			case '1': results();
				break;
			case '2': entry_menu();
				break;
			case '3':
				break;
			default :cout<<"\a";
		}
    }while(choice!='3');
	return 0;
}

//Getting User's Data
void student::getdata()
{
    cout << "\n\n\t\t\t\t\tPlease enter your Matric Number" << endl;
    cin >> matric_number;
    cout << "\n\n\t\t\t\t\tPlease enter your Full Name" << endl;
    cin.ignore();
    cin.getline (stdname, 100);
    cout << "\n\n\t\t\t\t\tPlease enter your final year examination Circuit Theory marks (e.g: 4.0)" << endl;
    cin >> MarksCT;
    cout << "\n\n\t\t\t\t\tPlease enter your final year examination Engineering Mechanics marks (e.g: 3.5)" << endl;
    cin >> MarksMech;
    cout << "\n\n\t\t\t\t\tPlease enter your final year examination Engineering Materials marks (e.g: 3.75)" << endl;
    cin >> MarksMat;
    cout << "\n\n\t\t\t\t\tPlease enter your final year examination Calculus marks (e.g: 3.0)" << endl;
    cin >> MarksCalc;
    cout << "\n\n\t\t\t\t\tPlease enter your final year examination Programming for Engineers marks (e.g: 4.0)" << endl;
    cin >> MarksProg;
    calculate();
}

//Calculating Grades
void student::calculate()
{   
    AvgMarks=(MarksCT + MarksMat + MarksCalc + MarksProg + MarksMech)/5.0;

        if (AvgMarks >= 3.67)
                grade = 'A';
        else if (AvgMarks >= 2.67)
                grade = 'B';
        else if (AvgMarks >= 1.67)
                grade = 'C';
        else if (AvgMarks >= 0.67)
                grade = 'D';
        else
                grade = 'F';
}


//For displaying all results use
void student::show_tabular() const {
        cout << endl;
        cout << matric_number << setw(18) << stdname << setw(45) << MarksCT << setw(8) << MarksMech << setw(8) << MarksMat << setw(8) << MarksCalc << setw(8) << MarksProg << setw(8) << AvgMarks << setw(8) << grade << endl;
}

int student::rematricno() const{
    return matric_number;
}






