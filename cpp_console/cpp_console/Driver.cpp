#ifndef TODO_H
#include "todo.h"
#define TODO_H
#include <iostream>
#endif


void main()
{
	todo* list;
	list = new todo();
	action* node;
	list->insert(new action("Do a thing", "Do it really well!", 1,2,3,4));
	list->insert(new action("Do a different thing", "Do it better than the other thing", 2, 3, 4, 5));
	node = list->getRoot();
	std::cout << node->getTitle();
	std::cin.get();

}
