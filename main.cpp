#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


class student{
    public:
    int matric_number;
    char stdname[100];
    float MarksCT, MarksMech, MarksMat, MarksCalc, MarksProg;
    float AvgMarks;
    char grade;
    void calculate();

    void getdata();
    void showdata() const;
    void show_tabular() const;
    int rematricno() const; 
};

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

void student::getdata()
{
    cout << "\n\n\t\t\t\t\tPlease enter your Matric Number" << endl;
    cin >> matric_number;
    cout << "\n\n\t\t\t\t\tPlease enter you Full Name" << endl;
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

void student::showdata() const{

    cout << "\n\n\t\t\t\t\tStudent Matric number : " << matric_number;
    cout << "\n\n\t\t\t\t\tStudent Name : " << stdname;
    cout << "\n\n\t\t\t\t\tCircuit Theory marks : "<< MarksCT;
    cout << "\n\n\t\t\t\t\tEngineering Mechanics marks : " << MarksMech;
    cout << "\n\n\t\t\t\t\tEngineering Materials marks : " << MarksMat;
    cout << "\n\n\t\t\t\t\tCalculus marks : " << MarksCalc;
    cout << "\n\n\t\t\t\t\tProgramming for Engineers marks : " << MarksProg;
    cout << "\n\n\t\t\t\t\tAverage marks : " << AvgMarks;
    cout << "\n\n\t\t\t\t\tGrade achieved : " << grade;
}

void student::show_tabular() const {
        cout << endl;
        cout << matric_number << setw(18) << stdname << setw(45) << MarksCT << setw(8) << MarksMech << setw(8) << MarksMat << setw(8) << MarksCalc << setw(8) << MarksProg << setw(8) << AvgMarks << setw(8) << grade << endl;
}

int student::rematricno() const{
    return matric_number;
}


void writestd();	
void displayAll();	
void displaySP(int);	
void modifystd(int);	
void deletestd(int);	
void classResults();	
void results();		
void introduction();		
void entry_menu();

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

void writestd(){
    student stud;
    ofstream stdoutFile;

    stdoutFile.open("student.dat", ios::binary|ios::app);
    stud.getdata();
    stdoutFile.write(reinterpret_cast<char*> (&stud), sizeof(student));
    stdoutFile.close();
        cout << "\n\n\t\t\t\t\tStudent record has been created " << endl;
    cin.ignore();
    cin.get();
}

void displayAll(){
    student stud;
    ifstream stdinFile;

    stdinFile.open("student.dat", ios::binary);

    if(!stdinFile){
        cout << "The file cannot be opened. Press any key to return" << endl;
        cin.ignore();
        cin.get();
        return;
    }

    cout << "\n\n\t\t\t\t\tDISPLAYING ALL RECORD " << endl;
    while(stdinFile.read(reinterpret_cast<char*> (&stud), sizeof(student))){
        stud.showdata();
        cout << "\n\n\t\t\t\t\t============================= " << endl;
    }
    stdinFile.close();
    cin.ignore();
    cin.get();
}

void displaySP(int num){
    student stud;
    ifstream stdinFile;
    stdinFile.open ("student.dat", ios::binary);
    if(!stdinFile)
	{
		cout<<"File could not be opened. Press any Key";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;

	while(stdinFile.read(reinterpret_cast<char*> (&stud), sizeof(student))){
	
    	if(stud.rematricno()==num)
		{
	  		 stud.showdata();
			 flag=true;
		}
	}
	stdinFile.close();

	if(flag==false)
		cout<<"\n\n\t\t\t\t\tRecord does not exist.";
	cin.ignore();
	cin.get();
}

void modifystd(int num1)
{
	bool found=false;
	student stud;
	fstream stdFile;
	stdFile.open("student.dat",ios::binary|ios::in|ios::out);
	if(!stdFile)
	{
		cout << " File could not be opened. Please press any key" << endl;
		cin.ignore();
		cin.get();
		return;
	}
    	while(!stdFile.eof() && found==false)
	{

		stdFile.read(reinterpret_cast<char*> (&stud), sizeof(student));
		if(stud.rematricno()==num1)
		{
			stud.showdata();
			cout <<"\n\n\t\t\t\t\tPlease enter details of student" << endl;
			stud.getdata();
		    	int position=(-1)*static_cast<int>(sizeof(stud));
		    	stdFile.seekp(position,ios::cur);
		    	stdFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
		    	cout<<"\n\n\t\t\t\t\tRecord has been updated " << endl;
		    	found=true;
		}
	}
	stdFile.close();
	if(found==false)
		cout<<"\n\n\t\t\t\t\tRecord Not Found " << endl;
	cin.ignore();
	cin.get();
}

void deletestd(int num2){

    student stud;
    ifstream stdinFile;
    stdinFile.open("student.dat", ios::binary);
    
    if(!stdinFile){
        cout << "File could not be opened. Press any key to exit." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    ofstream stdoutFile;
    stdoutFile.open("Temp.dat", ios::out);
    stdinFile.seekg(0, ios::beg);
    while(stdinFile.read(reinterpret_cast<char*> (&stud), sizeof(student))){

        if(stud.rematricno()!=num2){
            stdoutFile.write(reinterpret_cast<char*> (&stud), sizeof(student));
        }
    }
    stdoutFile.close();
    stdinFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");

    cout << "\n\n\t\t\t\t\tRecord has been successfully deleted." << endl;
    cin.ignore();
    cin.get(); 
}

void classResults(){
    student stud;
    ifstream stdinFile;
    stdinFile.open("student.dat", ios::binary);
    if(!stdinFile){
        cout << "File could not be opened. Press any key to exit." << endl;
        cin.ignore();
        cin.get();
        return;
    }

    cout << "\n\n\t\t\t\t\t--RESULTS FOR ALL STUDENTS--" << endl;
    cout << "________________________________________________________________________________________________________________________" << endl;
    cout << "\nMatric No  Name                                                 EEE105  EBB113  EMM101  EUM113  EEE123   CGPA     Grade" << endl;
    cout << "________________________________________________________________________________________________________________________" << endl;

    while(stdinFile.read(reinterpret_cast<char*> (&stud), sizeof(student))){
        
        stud.show_tabular();
    }
    cin.ignore();
    cin.get();
    stdinFile.close();
}

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

void introduction(){

        cout << "\n\n\t\t\t\t\tSTUDENT REPORT CARD SYSTEM" << endl;
        cout << "\n\n\t\t\t\t\t By Group 36 :D" << endl;
        cout << "\n\n\t\t\t\t\tKampus Kejuruteraan Universiti Sains Malaysia" << endl;
        cout << "\n\n\t\t\t\t\tPlease open this window in fullscreen" << endl;
        cin.get();       
}

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