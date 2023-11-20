/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <array>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unistd.h>

using namespace std;

class studentData{
    public:
    studentData(string birthDate, string admissionYear, string groupe, int cource, int (&grades)[8]){
        this->birthDate = birthDate;
        this->admissionYear = admissionYear;
        this->groupe = groupe;
        this->cource = cource;
        string subjects[8]{"Mathmatics", "English", "Russian", "Chemistry", "History", "Literature", "Physics", "Physical education"};
        for (int i = 0;i<8;i++){
            this->grades[i]     = grades[i];
            this->averageGrade += grades[i];
            this->subjects[i]   = subjects[i];
        }
        this->averageGrade = (this->averageGrade)/8;
    }
    
    string getBirthDate()    {return birthDate;};
    string getAdmissionYear(){return admissionYear;};
    string getGroupe()       {return groupe;};
    string getSubjects(int n){return subjects[n];};
    int    getCource()       {return cource;};
    int    getGrades(int i)  {return grades[i];};
    double getAverageGrade() {return averageGrade;};

    void setBirthDate(string birthDate)        {this->birthDate=birthDate;};
    void setAdmissionYear(string admissionYear){this->admissionYear=admissionYear;};
    void setGroupe(string groupe)              {this->groupe=groupe;};
    void setSubject(int n, string subject)     {this->subjects[n]=subject;};
    void setCource(int cource)                 {this->cource=cource;};
    void setGrade(int i, int grade)            {this->grades[i]=grade;};
    void setAverageGrade(){
        for (int i = 0;i<8;i++){
            double averageGrade;
            averageGrade += this->grades[i];
        }
        this->averageGrade = (averageGrade)/8;
    };
    
    void printStudentList(){
        cout<<" Birth Date: "<<getBirthDate();
        cout<<" Admission Year: "<<getAdmissionYear();
        cout<<" Groupe: "<<getGroupe();
        cout<<" Cource: "<<getCource()<<"\t[";
        for (int i = 0; i<8; i++){
                cout<<"  "<<getSubjects(i)<<": "<<getGrades(i);
        }
		cout<<" ]";
        cout<<"\tAverage Grade: "<<getAverageGrade()<<"\n\n";
    };
    
    private:
    
    string birthDate;
    string admissionYear;
    string groupe;
    string subjects[8];
    int cource;
    double averageGrade;
    int grades[8];
};

int generateRandomNumber(int max, int min, int usages){
    int number;
  srand(time(NULL)+usages);
  number = min + rand() % (max - min + 1);
  return number;
};

array<studentData*,25> createGroupe(){
    array <studentData*,25> students;
	string birthDate;
	int usagesrng = 0;
	int grades[8];
    for (int i = 0;i<25;i++){
        cout<<"CreatingStudent Num "<<i+1<<"/25\t[";
		for(int j = 0;j<8;j++){
            grades[j] = generateRandomNumber(5,3,usagesrng);
			usagesrng++;
  			cout<<"#";
        }
		birthDate = to_string(generateRandomNumber(29,1,usagesrng))+"."+to_string(generateRandomNumber(12,1,usagesrng))+".2006";
		usagesrng++;
		students[i] = new studentData(birthDate, "2023", "ISP", 2, grades);
        cout<<"] Done!\n"<<endl;
}
return students;
}

void printGroupeList(array<studentData*,25> students){
	for (int i = 0;i<25;i++){
		cout<<"Student№"<<i+1<<":";
        students[i]->printStudentList();
    }
}

array<studentData*,25> studentSortByAverageGrade(array<studentData*,25> students){
	cout<<"\nSORTING...\n\n";	
	studentData* studentMem;
	int i = 0;    
	do{
        if ((students[i]->getAverageGrade())<(students[i+1]->getAverageGrade())){
            studentMem = students[i];
            students[i] = students[i+1];
            students[i+1] = studentMem;
            i = -1;
        };
		i++;
    }while (i<24);
return students;
}

int main()
{

    array <studentData*, 25> students = createGroupe();
    printGroupeList(students);
    students = studentSortByAverageGrade(students);
    printGroupeList(students);
    return 0;
}
