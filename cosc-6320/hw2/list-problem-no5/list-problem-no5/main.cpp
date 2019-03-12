#include <iostream>
#include "List.h"


int main()
{
	ArrayList<int> *arr_lt = new ArrayList<int>();
	LinkedList<int> *link_lt = new LinkedList<int>();
                                
	add(link_lt, 5);                  // add items to link list
	add(link_lt, 8);
	add(link_lt, 5);
	add(link_lt, 3, 2);
	add(link_lt, 10);
	std::cout << "linked_list: ";
	print_list(link_lt);              // print link list
                             
	add(arr_lt, 3);                   // add items to array list
	add(arr_lt, 3);
	add(arr_lt, 3, 0);
	add(arr_lt, 3);
	std::cout << "arr_list: ";
	print_list(arr_lt);               // print array list
	std::cout << std::endl;

	int value;
	bool success;
	get(link_lt, 1, value, success);  // get 2nd value from Link list  
	std::cout << "Item in Link list at 1: " << value << std::endl;

	add(arr_lt, value, 1);            // add the value into array list at 2nd position
	std::cout << "Array list after adding the value got from Link list: " << std::endl;
	print_list(arr_lt);
	std::cout << std::endl;

	purge_list(arr_lt);               // purge array list
	std::cout << "Array List after purge: " << std::endl;
	print_list(arr_lt);               // print array list after purge

	purge_list(link_lt);               // purge link list
	std::cout << "Link List after purge: " << std::endl;
	print_list(link_lt);               // print link list after purge
	std::cout << std::endl;

	int pos = find(link_lt, 10);       // find item into link list
	if (pos != INVALID_POS)
		std::cout << "Item 10 found into link list at: " << pos << std::endl;
	else
		std::cout << "Item 10 not found into link list." << std::endl;

	return 0;
}

