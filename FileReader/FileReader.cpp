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
    vector<Person> everyonesFriends;
    everyonesFriends.push_back(Person("Mile", 55));
    everyonesFriends.push_back(Person("Rile", 45));

    vector<Person> people;
    people.push_back(Person("Branko", 31, everyonesFriends));
    people.push_back(Person("Marko", 32, everyonesFriends));
    people.push_back(Person("Zarko", 30, everyonesFriends));

    fileDatabase->Save(people);

    vector<Person> retrievedPeople = fileDatabase->Get();

    for (Person person : retrievedPeople)
        cout << person.name << ":" << person.age << ":" << person.friends[0].name << "\n";
}