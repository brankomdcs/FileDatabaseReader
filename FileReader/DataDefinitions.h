#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

#pragma once
namespace DataDefinition 
{
	struct Person
	{
		Person() {};
		Person(string person_name, int person_age) :
			name(person_name),
			age(person_age) {}

		string name;
		int age;
	};

	inline void to_json(json& j, const Person& r) {
		j = json{
			{"name", r.name},
			{"age", r.age}
		};
	}

	inline void from_json(const json& j, Person& r) {
		r.name = j.at("name").get<std::string>();
		r.age = j.at("age").get<int>();
	}
}