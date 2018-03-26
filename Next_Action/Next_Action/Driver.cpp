#include "node.cpp"
#include <iostream>
using namespace Action;


void main() {
	Node task = Node("Do a thing", "Do it well");
	std::cout << task.tostring();
	std::cin.get();
}
