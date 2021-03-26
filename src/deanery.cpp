// Copyright 2021 Krayushkina
#include <vector>
#include<string>
#include<cstring>
#include "Deanery.h"
ifstream FileStudents("students.txt");
ifstream FileGroups("groups.txt");
ofstream FileNew("data.txt");
void Deanery::CreateStudentsFromFile()
{
	if (!FileStudents.is_open())
	{
		FileStudents.open("students.txt");
		return;
	}
	else
	{
		string fio_f = "";
		string id_f="";
		char buffer[80];
		FileStudents.getline(buffer, 80);
		int len = strlen(buffer);
		if (buffer[0] == ' ')
		{
			FileStudents.close();
			return;
		}
		for (int i = 0; i < len; i++)
		{
				if (buffer[i] >= '0' && buffer[i] <= '9')
				{
					id_f += buffer[i];
				}
				else
				{
					fio_f += buffer[i];
				}
		}
		int idf = std::stoi(id_f);
		students.push_back(new Student(idf, fio_f));
		num_students++;
	}

}
void Deanery::CreateGroupsFromFile()
{
	if (!FileGroups.is_open())
	{
		FileGroups.open("groups.txt");
		return;
	}
	else
	{
		string group_f = "";

		char buffer[8];
		FileGroups.getline(buffer, 8);
		int len = strlen(buffer);
		if (buffer[0] == ' ')
		{
			FileGroups.close();
			return;
		}
		for (int i = 0; i < len; i++)
		{
					group_f += buffer[i];
		}
		groups.push_back(new Group(group_f));
		for (int i = num_groups*10; i < num_groups*10+10; i++)
		{
			groups[num_groups]->AddStudent(students[i], groups[num_groups]);
		}
		num_groups++;
	}
}
void Deanery::GetStatistic(string thing)
{
	if (thing[0] >= '0' && thing[0] <= '9')
	{
		int th=std::stoi(thing);
		for (int i = 0; i < num_students; i++)
		{
			if (students[i]->id == th)
			{
				
				cout << "ID: "<<students[i]->id << " -- " << students[i]->fio << endl;
				cout << "Number of marks: " << students[i]->num << endl;
				cout << "Marks: ";
				for (int j = 0; j < students[i]->num; j++)
				{
					cout << students[i]->marks[j]<<" ";
				}
				cout << endl;
				cout << "Average Mark: " << students[i]->AverageMark() << endl;

				cout << "Group :" << students[i]->group->title << endl;
				cout << endl;
			}
		}
	}
	else
	{
		for (int i = 0; i < num_groups; i++)
		{
			if (groups[i]->title == thing)
			{
				cout << "Group: " << groups[i]->title << endl;
				cout << "Average in group: " << groups[i]->AverageInGroup() << endl;
				cout << endl;
				cout << "Head: "<<groups[i]->head->fio<<endl;
				cout << "Students: " << endl;
				for (int j = 0; j < groups[i]->num; j++)
				{
					cout << "ID: " << groups[i]->students[j]->id << " -- " << groups[i]->students[j]->fio << endl;
					cout << "Number of marks: " << groups[i]->students[j]->num << endl;
					cout << "Average Mark: " << groups[i]->students[j]->AverageMark() << endl;
					cout << endl;
				}
			}
		}
	}
}
void Deanery::StudentTransferToGroup(int id, string group)
{

	for (int i = 0; i < num_groups; i++)
	{
		for (int j = 0; j < groups[i]->num; j++)
		{
			if (groups[i]->students[j]->id == id)
			{
				if (groups[i]->head != students[j])
				{
					for (int n = 0; n < num_groups; n++)
					{
						if (groups[n]->title == group)
						{
							students[j]->group->title = group;
							groups[n]->AddStudent(groups[i]->students[j], groups[n]);
							break;
						}
					}
					groups[i]->StudentException(groups[i]->students[j]->id);
					return;
				}
				else
				{
					for (int n = 0; n < num_groups; n++)
					{
						if (groups[n]->title == group)
						{
							students[j]->group->title = group;
							groups[n]->AddStudent(groups[i]->students[j], groups[n]);
							break;
						}
					}
					groups[i]->StudentException(groups[i]->students[j]->id);
					ChooseHeads();
					return;
				}

			}
		}
	}
}
void Deanery::StudentDeduction()
{
	for (int i = 0; i < num_groups; i++)
	{
		for (int j = 0; j < groups[i]->num; j++)
		{
			if (groups[i]->students[j]->AverageMark() < 3.5)
			{
				if (groups[i]->head != students[j])
				{
					groups[i]->StudentException(groups[i]->students[j]->id);
					num_students--;
					j--;
				}
				else
				{
					groups[i]->StudentException(groups[i]->students[j]->id);
					num_students--;
					j--;
					ChooseHeads();
				}
			}
		}
	}
}
void Deanery::SaveDataInFiles()
{
	FileNew.clear();
	for (int i = 0; i < num_groups; i++)
	{
		for (int j = 0; j < groups[i]->num; j++)
		{
			FileNew << "ID: " << groups[i]->students[j]->id << " -- " << groups[i]->students[j]->fio << "\n";
			FileNew << "Number of marks: " << groups[i]->students[j]->num << "\n";
			FileNew << "Marks: ";
			for (int k = 0; k < groups[i]->students[j]->num; k++)
			{
				FileNew << groups[i]->students[j]->marks[k] << " ";
			}
			FileNew << "\n";
			FileNew << "Average Mark: " << groups[i]->students[j]->AverageMark() << "\n";

			FileNew << "Group :" << groups[i]->students[j]->group->title << "\n";
		}
	}
	FileNew.close();
}
void Deanery::ChooseHeads()
{
	for (int i = 0; i < num_groups; i++)
	{
		groups[i]->HeadElection();
	}
}
void Deanery::DataOutput()
{
	for (int i = 0; i < num_groups; i++)
	{
		for (int j = 0; j < groups[i]->num; j++)
		{
			cout << "ID: " << groups[i]->students[j]->id << " -- " << groups[i]->students[j]->fio << endl;
			cout << "Number of marks: " << groups[i]->students[j]->num << endl;
			cout << "Marks: ";
			for (int k = 0; k < groups[i]->students[j]->num; k++)
			{
				cout << groups[i]->students[j]->marks[k] << " ";
			}
			cout << "\n";
			cout << "Average Mark: " << groups[i]->students[j]->AverageMark() << endl;

			cout << "Group :" << groups[i]->students[j]->group->title << endl;
		}
	}
}
void Deanery::AddMarks()
{
	random_device ran;
	for (int i = 0; i < num_groups; i++)
	{
		for (int j = 0; j < groups[i]->num; j++)
		{
			groups[i]->students[j]->AddMark(ran() % 10 + 1);
		}
	}
}
