#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define LIST_SIZE 500
#define INVALID_POS -1

template <class AT>
class ArrayList
{
public:
	ArrayList();
	~ArrayList();

	void add(AT x, int pos = -1);
	AT remove(int pos, bool &success);

	int find(AT x);
	AT get(int pos, bool &success);

	int first();
	int next(int pos);

	bool empty();
	void purge_list();

	void print_list();
	void delete_list();
	bool is_pos_valid(int pos);

private:
	AT list[LIST_SIZE];
	int num_of_items;
};

#include "ArrayList.cpp"

#endif
//#include "ArrayList.cpp"