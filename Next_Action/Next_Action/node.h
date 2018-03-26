#pragma once
#include <cstdlib>
#include <string>

typedef std::string string;

namespace Action {
	class Node {

		string name;
		string description;

	public:
		string tostring() { return name; }
		void rename(string name) { this->name = name; }
		string get() { return description; }
		void changeDescription(string description) { this->description = description; }

		Node();
		Node(string name) {rename(name);}
		Node(string name, string description) { rename(name); changeDescription(description); }		
		//~Node();
	};
}

