#include "FileDatabase.h"

#include <fstream>
#include <sstream>
#include <mutex>

namespace FileReader 
{
	const string fileName = "database.txt";

	mutex databaseMutex;
	FileDatabase* FileDatabase::_fileDatabase = nullptr;

	FileDatabase* FileDatabase::GetInstance()
	{
		lock_guard<mutex> databaseLock(databaseMutex);
		if (_fileDatabase == nullptr) {
			_fileDatabase = new FileDatabase();
		}
		return _fileDatabase;
	}

	FileDatabase::FileDatabase()
	{
		
	}

	vector<Person> FileDatabase::Get()
	{
		lock_guard<mutex> databaseLock(databaseMutex);
		ifstream databaseFile(fileName);

		json jsonData;
		databaseFile >> jsonData;

		vector<Person> result = jsonData.get<std::vector<Person>>();

		databaseFile.close();

		return result;
	}
	void FileDatabase::Save(vector<Person> people)
	{
		lock_guard<mutex> databaseLock(databaseMutex);
		ofstream databaseFile(fileName);

		json jsonData(people);
		string content = jsonData.dump();
		databaseFile << content;

		databaseFile.close();
	}
}