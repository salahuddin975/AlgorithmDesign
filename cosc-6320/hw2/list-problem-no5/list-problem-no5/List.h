#ifndef LIST_H
#define LIST_H

#include "ArrayList.h"
#include "LinkedList.h"

/*
<------------ Usage -------------->

ArrayList<type> *arr_lt = new ArrayList<type>();
LinkedList<type> *link_lt = new LinkedList<type>();
<-- List can be either ArrayList or LinkedList with any *type -->

void add(LT *list, VT x, int pos=-1)
<-- add *x to the provided *list. Add to the position if *pos provided, otherwise to the end of the list -->

void remove(LT *list, int pos, VT &value, bool &success)
<-- remove item from the provided *pos of the *list. if *success, deleted item can be got into *value -->

int find(LT *list, VT x)
<-- if *x found, a valid *position will be returned, otherwise *INVALID_POS -->

void get(LT *list, int pos, VT &value, bool &success)
<-- if *success, get *value from the provided *list -->

int first(LT *list)
<-- if list is not empty, returns the first position, otherwise *INVALID_POS -->

int next(LT *list, int pos)
<-- returns the next position of the provided *position, otherwise *INVALID_POS -->

bool empty(LT *list)
<-- returns *true if *list is empty -->

void purge_list(LT *list)
<-- purge the provided list -->

void print_list(LT *list)
<-- print the provided list -->

void delete_list(LT *list)
<-- delete the provided list -->
*/



template<class LT, class VT>
void add(LT *list, VT x, int pos=-1)
{
	list->add(x, pos);
}

template<class LT, class VT>
void remove(LT *list, int pos, VT &value, bool &success)
{
	value = list->remove(pos, success);
}

template<class LT, class VT>
int find(LT *list, VT x)
{
	return list->find(x);
}

template<class LT, class VT>
void get(LT *list, int pos, VT &value, bool &success)
{
	value = list->get(pos, success);
}

template<class LT>
int first(LT *list)
{
	return list->first();
}

template<class LT>
int next(LT *list, int pos)
{
	return list->next(pos);
}

template<class LT>
bool empty(LT *list)
{
	return list->empty();
}

template<class LT>
void purge_list(LT *list)
{
	list->purge_list();
}

template<class LT>
void print_list(LT *list)
{
	list->print_list();
}

template<class LT>
void delete_list(LT *list)
{
	list->delete_list();
}


#endif