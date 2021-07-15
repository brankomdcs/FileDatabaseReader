#ifndef _FILE_DATABASE_
#define _FILE_DATABASE_

#include <string>
#include "DataDefinitions.h"
using namespace std;
using namespace DataDefinition;

#pragma once

namespace FileReader 
{
	class FileDatabase 
	{
	private:
		FileDatabase();
		static FileDatabase* _fileDatabase;

	public:
		FileDatabase(FileDatabase &other) = delete;		// Prevents FileDatabase from being clonable.
		void operator=(const FileDatabase &) = delete;	// Prevents FileDatabase from being assignable.

		static FileDatabase* GetInstance();

		vector<Person> Get();
		void Save(vector<Person> people);
	};
}

#endif