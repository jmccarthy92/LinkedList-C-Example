
#ifndef MAIN_SAVITCH_NODE1_H  
#define MAIN_SAVITCH_NODE1_H
#include <cstdlib> // Provides size_t and NULL


class node
{
public:
	// TYPEDEF
	typedef double value_type;

	// CONSTRUCTOR (already implemented for you)
	node(const value_type& init_data = value_type(), node* init_link = NULL)
	{
		data_field = init_data; link_field = init_link;
	}

	//IMPLEMENT THE FOLLOWING MEMBER FUNCTIONS

	// Member functions to set the data and link fields. 
	void set_data(const value_type& new_data)
	{
		this->data_field = new_data;
	}
	void set_link(node* new_link)
	{
		this->link_field = new_link;
	}

	// Constant member function to retrieve the current data:
	value_type data() const
	{
		return this->data_field;
	}

	// Two slightly different member functions to retreive
	// the current link. (they have the same implementation)
	//they take care of whether it's called from a const function
	//or a non-const function
	const node* link() const
	{
		return this->link_field;
	}
	node* link()
	{
		return this->link_field;
	}

private:
	value_type data_field;
	node* link_field;
};



#endif