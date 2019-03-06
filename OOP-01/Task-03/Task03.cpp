#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <list>

using namespace std;

struct Student
{
	char Id[20];
	char Name[30];
	char Sex[8];
	int FirstQuizScore;
	int SecondQuizScore;
	int MidTermScore;
	int FinalScore;
	int TotalScore;
};

void PrintMainMenu()
{
	cout << endl << " __________________________________\n";
	cout << "|                                  |\n";
	cout << "|1) Add a new student              |\n";
	cout << "|2) Delete a student               |\n";
	cout << "|3) Update student info            |\n";
	cout << "|4) Display all students           |\n";
	cout << "|__________________________________|\n";
	cout << "|                                  |\n";
	cout << "|5) Student score average          |\n";
	cout << "|6) Display best student           |\n";
	cout << "|7) Display worst student          |\n";
	cout << "|8) Find student by ID             |\n";
	cout << "|9) Sort students by total score   |\n";
	cout << "|__________________________________|\n";
	cout << "|                                  |\n";
	cout << "|0) Exit!                          |\n";
	cout << "|__________________________________|\n" << endl;
}

list<Student> StudentSeed()
{
	list<Student> newStudentList;

	Student tmpStudent;

	strcpy(tmpStudent.Id, "1");
	strcpy(tmpStudent.Name, "Alex");
	strcpy(tmpStudent.Sex, "male");
	tmpStudent.FirstQuizScore = 15;
	tmpStudent.SecondQuizScore = 2;
	tmpStudent.MidTermScore = 18;
	tmpStudent.FinalScore = 40;
	tmpStudent.TotalScore = tmpStudent.FirstQuizScore + tmpStudent.SecondQuizScore + tmpStudent.MidTermScore + tmpStudent.FinalScore;
	newStudentList.push_back(tmpStudent);

	strcpy(tmpStudent.Id, "2");
	strcpy(tmpStudent.Name, "Ante");
	strcpy(tmpStudent.Sex, "male");
	tmpStudent.FirstQuizScore = 16;
	tmpStudent.SecondQuizScore = 20;
	tmpStudent.MidTermScore = 14;
	tmpStudent.FinalScore = 36;
	tmpStudent.TotalScore = tmpStudent.FirstQuizScore + tmpStudent.SecondQuizScore + tmpStudent.MidTermScore + tmpStudent.FinalScore;
	newStudentList.push_back(tmpStudent);

	strcpy(tmpStudent.Id, "3");
	strcpy(tmpStudent.Name, "Matija");
	strcpy(tmpStudent.Sex, "male");
	tmpStudent.FirstQuizScore = 20;
	tmpStudent.SecondQuizScore = 18;
	tmpStudent.MidTermScore = 16;
	tmpStudent.FinalScore = 30;
	tmpStudent.TotalScore = tmpStudent.FirstQuizScore + tmpStudent.SecondQuizScore + tmpStudent.MidTermScore + tmpStudent.FinalScore;
	newStudentList.push_back(tmpStudent);

	return newStudentList;
}

Student InputStudent()
{
	Student newStudent;
	cin >> newStudent.Id;
	cin >> newStudent.Name;
	cin >> newStudent.Sex;/*
	cin >> newStudent.FirstQuizScore;
	cin >> newStudent.SecondQuizScore;
	cin >> newStudent.MidTermScore;
	cin >> newStudent.FinalScore;
	cin >> newStudent.TotalScore;*/

	return newStudent;
}

int main()
{
	list<Student> allStudents = StudentSeed();

	int currentTail = 3;

	int choice = 0;
	do
	{
		PrintMainMenu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			{
				allStudents.push_back(InputStudent());
				break;
			}

		case 2:
			{
				char idToDelete[20];
				cin >> idToDelete;
				bool isIdFound = false;

				for (Student student : allStudents)
				{
					if(strcmp(student.Id, idToDelete) == 0)
					{
						isIdFound = true;
						break;
					}
				}

				if(!isIdFound)
					break;

				allStudents.remove_if([idToDelete](Student const & student)
				{
					return strcmp(student.Id, idToDelete) == 0;
				});

				break;
			}

		case 3:
			{
				char idToUpdate[20];
				cin >> idToUpdate;

				for (list<Student>::iterator i = allStudents.begin(); i != allStudents.end(); ++i)
				{
					Student & student(*i);

					if(strcmp(student.Id, idToUpdate) == 0)
					{
						Student tmpStudent = InputStudent();

						strcpy(student.Id, tmpStudent.Id);
						strcpy(student.Name, tmpStudent.Name);
						strcpy(student.Sex, tmpStudent.Sex);

						break;
					}
				}

				break;
			}

		case 4:
			{
				for (Student student : allStudents)
				{
					cout << student.Id << endl;
					cout << student.Name << endl;
					cout << student.Sex << endl;
					cout << student.FirstQuizScore << endl;
					cout << student.SecondQuizScore << endl;
					cout << student.MidTermScore << endl;
					cout << student.FinalScore << endl;
					cout << student.TotalScore << endl << endl;
				}
				
				break;
			}
		case 5:
			{
				char idToFind[20];
				cin >> idToFind;

				for (Student student : allStudents)
				{
					if(strcmp(student.Id, idToFind) == 0)
					{
						double studentScoreAverage = student.TotalScore / 4;

						cout << student.Name << "'s score average is: " << studentScoreAverage << endl;
						break;
					}
				}
				break;
			}
		case 6:
			{
				list<Student> sortedStudents = allStudents;
				sortedStudents.sort([] (Student const &first, Student const &second) 
					{return first.TotalScore > second.TotalScore;});

				cout << sortedStudents.front().Name << " is the best student :)" << endl;

				break;
			}

		case 7:
			{
				list<Student> sortedStudents = allStudents;
				sortedStudents.sort([] (Student const &first, Student const &second) 
					{return first.TotalScore < second.TotalScore;});

				cout << sortedStudents.front().Name << " is the worst student :(" << endl;

				break;
			}

		case 8:
			{
				char idToDelete[20];
				cin >> idToDelete;
				bool isIdFound = false;

				for (Student student : allStudents)
				{
					if(strcmp(student.Id, idToDelete) == 0)
					{
						cout << student.Name << endl;
						cout << student.Sex << endl;
						cout << student.FirstQuizScore << endl;
						cout << student.SecondQuizScore << endl;
						cout << student.MidTermScore << endl;
						cout << student.FinalScore << endl;
						cout << student.TotalScore << endl << endl;
						isIdFound = true;
						break;
					}
				}

				if(!isIdFound)
				{
					cout << "No student with that ID exists!" << endl;
				}
				break;
			}

		case 9:
			{
				list<Student> sortedStudents = allStudents;
				sortedStudents.sort([] (Student const &first, Student const &second) 
					{return first.TotalScore > second.TotalScore;});

				for (Student student : sortedStudents)
				{
					cout << student.Name << endl;
					cout << student.Sex << endl;
					cout << student.FirstQuizScore << endl;
					cout << student.SecondQuizScore << endl;
					cout << student.MidTermScore << endl;
					cout << student.FinalScore << endl;
					cout << student.TotalScore << endl << endl;
				}
			}
		
		}
	}while (choice != 0);
}