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
	cout << "Please enter the following student's info" << endl << endl;
	cout << "ID: ";
	cin >> newStudent.Id;
	cout << "Name: ";
	cin >> newStudent.Name;
	cout << "Sex: ";
	cin >> newStudent.Sex;
	cout << "Score on the first quiz: ";
	cin >> newStudent.FirstQuizScore;
	cout << "Score on the second quiz: ";
	cin >> newStudent.SecondQuizScore;
	cout << "Mid term test score: ";
	cin >> newStudent.MidTermScore;
	cout << "Final score: ";
	cin >> newStudent.FinalScore;
	newStudent.TotalScore = newStudent.FirstQuizScore + newStudent.SecondQuizScore + newStudent.MidTermScore + newStudent.FinalScore;

	return newStudent;
}

void PrintStudent(Student toPrint)
{
	cout << "ID: " << toPrint.Id << endl;
	cout << "Name: " << toPrint.Name << endl;
	cout << "Sex: " << toPrint.Sex << endl;
	cout << "Score on the first quiz: " << toPrint.FirstQuizScore << endl;
	cout << "Score on the second quiz: " << toPrint.SecondQuizScore << endl;
	cout << "Mid term test score: " << toPrint.MidTermScore << endl;
	cout << "Final score: " << toPrint.FinalScore << endl;
	cout << "Total score: " << toPrint.TotalScore << endl << endl;
}

int CheckIdIntegrity(list<Student> allStudents, Student toCheck)
{
	int numberOfOccurrences = 0;
	for (Student student : allStudents)
	{
		if(strcmp(student.Id, toCheck.Id) == 0)
		{
			numberOfOccurrences++;
		}
	}
	return numberOfOccurrences;
}

int main()
{
	list<Student> allStudents = StudentSeed();

	char choice;
	do
	{
		PrintMainMenu();
		cin >> choice;

		switch (choice)
		{
		case '1':
			{
				Student studentToAdd = InputStudent();

				if(CheckIdIntegrity(allStudents, studentToAdd) == 0)
					allStudents.push_back(studentToAdd);
				else
					cout << "A student with that ID already exists!" << endl;
				break;
			}

		case '2':
			{
				char idToDelete[20];
				cout << "Enter the ID of the student you want to delete: " << endl;
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
				{
					cout << "No student with that ID exists!" << endl;
					break;
				}

				allStudents.remove_if([idToDelete](Student const & student)
				{
					return strcmp(student.Id, idToDelete) == 0;
				});

				break;
			}

		case '3':
			{
				char idToUpdate[20];
				cout << "Enter the ID of the student you want to update" << endl;
				cin >> idToUpdate;
				bool isIdFound = false;

				for (list<Student>::iterator i = allStudents.begin(); i != allStudents.end(); ++i)
				{
					Student & student(*i);

					if(strcmp(student.Id, idToUpdate) == 0)
					{
						char tmpId[20];
						strcpy(tmpId, student.Id);
						Student tmpStudent = InputStudent();

						strcpy(student.Id, tmpStudent.Id);
						strcpy(student.Name, tmpStudent.Name);
						strcpy(student.Sex, tmpStudent.Sex);
						student.FirstQuizScore = tmpStudent.FirstQuizScore;
						student.SecondQuizScore = tmpStudent.SecondQuizScore;
						student.MidTermScore = tmpStudent.MidTermScore;
						student.FinalScore = tmpStudent.FinalScore;
						student.TotalScore = student.FirstQuizScore + student.SecondQuizScore + 
							student.MidTermScore + student.FinalScore;

						int newIdIntegrity = CheckIdIntegrity(allStudents, student);

						if(newIdIntegrity > 1)
						{
							cout << "A different student already has that ID!" << endl << "ID will not be updated" << endl;
							strcpy(student.Id, tmpId);
						}

						isIdFound = true;
						break;
					}
				}

				if(!isIdFound)
				{
					cout << "No student with that ID exists!" << endl;
					break;
				}

				break;
			}

		case '4':
			{
				for (Student student : allStudents)
				{
					PrintStudent(student);
				}
				
				break;
			}
		case '5':
			{
				char idToFind[20];
				cout << "Enter the ID of the student you want to know the score average:" << endl;
				cin >> idToFind;
				bool isIdFound = false;

				for (Student student : allStudents)
				{
					if(strcmp(student.Id, idToFind) == 0)
					{
						double studentScoreAverage = student.TotalScore / 4;

						cout << student.Name << "'s score average is: " << studentScoreAverage << endl;
						isIdFound = true;
						break;
					}
				}
				if(!isIdFound)
				{
					cout << "No student with that ID exists!" << endl;
					break;
				}

				break;
			}
		case '6':
			{
				list<Student> sortedStudents = allStudents;
				sortedStudents.sort([] (Student const &first, Student const &second) 
					{return first.TotalScore > second.TotalScore;});

				cout << sortedStudents.front().Name << " is the best student :)" << endl;

				break;
			}

		case '7':
			{
				list<Student> sortedStudents = allStudents;
				sortedStudents.sort([] (Student const &first, Student const &second) 
					{return first.TotalScore < second.TotalScore;});

				cout << sortedStudents.front().Name << " is the worst student :(" << endl;

				break;
			}

		case '8':
			{
				char idToFind[20];
				cout << "Enter the ID of the student you want to find:" << endl;
				cin >> idToFind;
				bool isIdFound = false;

				for (Student student : allStudents)
				{
					if(strcmp(student.Id, idToFind) == 0)
					{
						PrintStudent(student);
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

		case '9':
			{
				list<Student> sortedStudents = allStudents;
				sortedStudents.sort([] (Student const &first, Student const &second) 
					{return first.TotalScore > second.TotalScore;});

				for (Student student : sortedStudents)
				{
					PrintStudent(student);
				}

				break;
			}
		}
	}while (choice != '0');
}