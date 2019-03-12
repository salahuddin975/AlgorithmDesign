#include <iostream>
#include "ArrayList.h"

template <class AT>
ArrayList<AT>::ArrayList() : num_of_items(0) { }

template <class AT>
ArrayList<AT>::~ArrayList(){ }

template <class AT>
void ArrayList<AT>::add(AT x, int pos)
{
	if (pos == -1){        
		pos = num_of_items;
	}

	if (pos != 0 && is_pos_valid(pos - 1) == false){
		return;
	}
	
	for (int i = num_of_items-1; i >= pos; i--){
		list[i + 1] = list[i];
	}

	list[pos] = x;
	num_of_items = num_of_items + 1;
}

template <class AT>
AT ArrayList<AT>::remove(int pos, bool &success)
{
	if (is_pos_valid(pos) == false){
		success = false;
		return INVALID_POS;
	}

	AT x = list[pos];
	for (int i = pos; i < num_of_items-1; i++){
		list[i] = list[i + 1];
	}

	success = true;
	num_of_items = num_of_items - 1;

	return x;
}

template <class AT>
int ArrayList<AT>::find(AT x)
{
	if (num_of_items == 0){
		return INVALID_POS;
	}

	for (int i = 0; i < num_of_items; i++){
		if (list[i] == x){
			return i;
		}
	}

	return INVALID_POS;

}

template <class AT>
AT ArrayList<AT>::get(int pos, bool &success)
{
	if (is_pos_valid(pos) == false){
		success = false;
		return INVALID_POS;
	}

	success = true;
	return list[pos];
}

template <class AT>
int ArrayList<AT>::first()
{
	if (num_of_items == 0){
		return INVALID_POS;
	}

	return 0;
}

template <class AT>
int ArrayList<AT>::next(int pos)
{
	if (is_pos_valid(pos) == false){
		return INVALID_POS;
	}

	return pos + 1;
}

template <class AT>
bool ArrayList<AT>::empty()
{
	if (num_of_items == 0)
		return true;
	else
		return false;
}

template <class AT>
void ArrayList<AT>::purge_list()
{
	if (num_of_items == 0)
		return;

	bool success;

	for (int i = 0; i < num_of_items-1; i++)
	{
		for (int j = i + 1; j < num_of_items; j++)
		{
			if (list[i] == list[j]){
				remove(j, success);
				j--;
			}
		}
	}
}

template <class AT>
void ArrayList<AT>::print_list()
{
	if (num_of_items == 0){
		return;
	}

	for (int i = 0; i < num_of_items-1; i++){
		std::cout << list[i] << ", ";
	}
	std::cout << list[num_of_items - 1] << std::endl;
}

template <class AT>
void ArrayList<AT>::delete_list()
{
	num_of_items = 0;
}

template <class AT>
bool ArrayList<AT>::is_pos_valid(int pos)
{
	if (pos < 0 || pos >= num_of_items){
		return false;
	}
	return true;
}



