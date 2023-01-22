#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

//Classifying data into student's
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

//Showing Student Report Card
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

//Displaying all registered students results.
void classResults(){
    student stud;
    ifstream stdinFile;
    stdinFile.open("StudentData.dat", ios::binary);
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

//Student record; Creating, Deleting, Modifying, Displaying
void writestd(){
    student stud;
    ofstream stdoutFile;

    stdoutFile.open("StudentData.dat", ios::binary|ios::app);
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

    stdinFile.open("StudentData.dat", ios::binary);

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
    stdinFile.open ("StudentData.dat", ios::binary);
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
	stdFile.open("StudentData.dat",ios::binary|ios::in|ios::out);
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
    stdinFile.open("StudentData.dat", ios::binary);
    
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
    remove("StudentData.dat");
    rename("Temp.dat", "StudentData.dat");

    cout << "\n\n\t\t\t\t\tRecord has been successfully deleted." << endl;
    cin.ignore();
    cin.get(); 
}