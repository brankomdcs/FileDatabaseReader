// FileReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include "FileDatabase.h"
#include "DataDefinitions.h"

using namespace std;
using namespace DataDefinition;
using namespace FileReader;

int main()
{
    FileDatabase* fileDatabase = FileDatabase::GetInstance();

    vector<Person> people;
    people.push_back(Person("Branko", 31));
    people.push_back(Person("Marko", 32));
    people.push_back(Person("Zarko", 30));

    fileDatabase->Save(people);

    vector<Person> retrievedPeople = fileDatabase->Get();

    for (Person person : retrievedPeople)
        cout << person.name << ":" << person.age << "\n";
}