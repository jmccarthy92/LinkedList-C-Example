#include <iostream>
#include "bag.h"
using namespace std;

int main() {
	bag a;
	a.insert(10);
	a.insert(20);
	a.insert(25);
	cout << "our bag should have 10,20,25 in it: " << a << endl;
	//a.erase(25);
	a.erase_one(25);
	a.insert(12);
	cout << "our bag should have 10,20,12 in it: " << a << endl;
	bag b;
	b.insert(23);
	b.insert(25);
	b.insert(27);
	b.insert(29);
	cout << "our bag shoule have 23,25,27, and 29 in it: " << b << endl;
//	b.insert(23);
	for (int j = 0; j < 30; j++)
		b.insert(100);
	int num = b.count(100);
	cout << " There are " << num << " 100's in the Bag" << endl;
	 num = b.erase(100);
	cout << " We erase 100 [" << num << "]  times" << endl;
	cout << " Our bag should now have 25,27,29   " << b << endl;
	bag c(b);
	cout << "Ths new bag should be equivalent to the first" << c << endl;

	bag d = b;
	cout << "The newer bag should be equal to the old bag " << d << endl;

	d += a;
	cout << " The newest bag should have 25,27,29,10,20, 12 in it: " << d << endl;

	int x;
	cin >> x;

}

