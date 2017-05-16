#include <iostream> //we are adding ostream and istream
#include <cstdlib>
#include "bag.h"
#include "node.h"
using namespace std;

typedef node value_type;
typedef std::size_t size_type;
bag::bag() //set capacity, used, and do a dynamic array of value_type
{
	headPtr = NULL;
	used = 0;
}

bag::bag(const bag& source)
{
	node *currentPtr = source.head() -> link();

	headPtr = new node(source.head()->data());
	node *prev = headPtr;
	while (currentPtr)
	{
		prev->set_link(new node(currentPtr->data() ) );
		currentPtr = currentPtr->link();
		prev = prev->link();
	}	
	
}
bag::~bag() //our destructor should release any dynamic memory we've allocated
{
	node *currentPtr = this->headPtr;
	node *temp = currentPtr->link();
	delete currentPtr;
	currentPtr = temp;
	while (currentPtr != NULL)
	{
		temp = currentPtr->link();
		delete currentPtr;
		currentPtr = temp;
	}
}



bool bag::erase_one(const value_type& target) //erases one item of a given value, returns true if something got erased, 0 if not
{
	bool deleteSwitch = false;
	node *currentPtr = this->headPtr;
	node *prevPtr = this->headPtr;
	if (currentPtr->data() == target.data())
	{
		
		headPtr = headPtr->link();
		delete currentPtr;
		return true;
	}
	while (currentPtr != NULL)
	{
		if (currentPtr->data() == target.data() )
		{
			prevPtr->set_link(currentPtr->link());	
			delete currentPtr;
			currentPtr = prevPtr;
			return true;
		}
		prevPtr = currentPtr;
		currentPtr = currentPtr->link();
	}
	return false;
	
}

size_type bag::erase(const value_type& target) //erases all of the data target from the bag
{
	size_type counter = 0;
	node *currentPtr = this->headPtr;
	node *prevPtr = this->headPtr;
	if (currentPtr->data() == target.data())
	{
		this->headPtr = headPtr->link();
		delete currentPtr;
		currentPtr = this->headPtr;
		prevPtr = currentPtr;
	}
	while (currentPtr != NULL)
	{

		if (currentPtr->data() == target.data())
		{
			prevPtr->set_link(currentPtr->link());
			delete currentPtr;
			currentPtr = prevPtr; 
			counter++;
		}
		prevPtr = currentPtr;
		currentPtr = currentPtr->link();
	
	}

	return counter;

}

void bag::insert(const value_type& entry) //inserts an entry into the bag
{
	if (headPtr == NULL)
	{
		headPtr = new node(entry);
		return;
	}
	node *currentPtr = this->headPtr;
	while (currentPtr != NULL)
	{
		if (currentPtr->link() == NULL)
		{
			currentPtr->set_link(new node(entry));
			return;
		}
		currentPtr = currentPtr->link();
	}

}

void bag::operator +=(const bag& addend) //adds the contents of one bag to another
{
	node *currentPtr = addend.head();
	while (currentPtr != NULL)
	{
		insert(currentPtr->data());
		currentPtr = currentPtr->link();
	}

}

void bag::operator =(const bag& source) //makes two bags equal
{
	node *currentPtr = this->headPtr;
	node *sourceCurrentPtr = source.head();
	while (sourceCurrentPtr != NULL)
	{
		if (currentPtr != NULL && currentPtr->link() != NULL)
		{
			currentPtr->set_data(sourceCurrentPtr->data());
		}
		else if (currentPtr != NULL && currentPtr->link() == NULL)
		{
			node *o = new node(sourceCurrentPtr->data());
			currentPtr->set_link(o);
		}
		currentPtr = currentPtr->link();
		sourceCurrentPtr = sourceCurrentPtr->link();
	}

}

size_type bag::count(const value_type& target) const //returns how many things are currently in the bag
{
	size_type counter = 0;
	node *currentPtr = this->headPtr;
	while (currentPtr != NULL)
	{
		if (currentPtr->data() == target.data())
			counter++;
		currentPtr = currentPtr->link();
	}

	return counter;
}

ostream& operator <<(ostream& outs, const bag& source)
{
	node *currentPtr = source.head();
	while (currentPtr != NULL)
	{
		cout << currentPtr->data() << "->";
		currentPtr = currentPtr->link();
	}
	cout << "NULL" << endl;

	return outs;
}