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
		Person(string person_name, int person_age, vector<Person> persons_friends = vector<Person>()) :
			name(person_name),
			age(person_age),
			friends(persons_friends)
		{}

		string name;
		int age;
		vector<Person> friends;
	};

	inline void to_json(json& j, const Person& r) {
		if (r.friends.empty()) {
			j = json{
			{"name", r.name},
			{"age", r.age}
			};
			return;
		}

		json friendsJson;
		for (Person person : r.friends)
		{
			json personJson;
			to_json(personJson, person);
			friendsJson.push_back(personJson);
		}
		j = json{
			{"name", r.name},
			{"age", r.age},
			{"friends", friendsJson}
		};
	}

	inline void from_json(const json& j, Person& r) {
		r.name = j.at("name").get<string>();
		r.age = j.at("age").get<int>();

		if (j.find("friends") == j.end())
			r.friends = vector<Person>();
		else
			r.friends = j.at("friends").get_to<vector<Person>>(r.friends);
	}
}