
#ifndef BAG_H_   //macroguard that stops the header from being included twice.
#define BAG_H_ //Including the header twice stops the compilation, Note no Semilcolon
#include <cstdlib>
#include <iostream>
#include "node.h"

class bag
{
public:
	typedef node value_type; //we define value type to be an int
	typedef std::size_t size_type; //we define size type to be a size_t (which is an unsigned int which is an int that can't be negative)
	static const size_type DEFAULT_CAPACITY = 30; //static variable for default capacity
												  //constructors and destructors
//	bag(size_type initial_capacity = DEFAULT_CAPACITY); //constructor with default arguments (remember you dont use the default argument in the .cpp)
	bag();
	bag(const bag& source); //copy constructor
	~bag(); //destructor
	void insert(const value_type& entry); //inserts into your bag
	bool erase_one(const value_type& target);//erase 1 of the target value
	size_type erase(const value_type& target);//erase all of the target value in the bag
	void operator +=(const bag& addend); //overloades += remember if x=5 x+=10 makes x=15. Similarly for bag...
	void operator =(const bag& source);//checks if two bags are equal
	size_type size() const { return used; } //note it's inlined
	value_type* head() const { return this->headPtr; }
	size_type count(const value_type& target) const; //returns how much of a given value you have inside the bag
	friend std::ostream& operator <<(std::ostream& outs, const bag& source);//couts the bag contents
private:
	//value_type *currentPtr;
	value_type *headPtr;
	size_type used;
	size_type capacity;

	void reserve(size_type new_capacity); //make your bag bigger
};

#endif