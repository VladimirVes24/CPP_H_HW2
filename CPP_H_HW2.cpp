#include <iostream>
#include <vector>
#include <algorithm>
#include "swap.h"
#include "PrintVector.h"
#include "RandomFillVector.h"
#include "SortPointers.h"
#include "CountVowels.h"

class Item
{
private:
	int value = 0;
public:
	Item(int input)
		: value(input)
	{

	}

	void printValue();

};

void Item::printValue()
{
	std::cout << value << std::endl;
}



int main()
{
	//Task 1
	std::unique_ptr<Item> ptr1(new Item(10));
	std::unique_ptr<Item> ptr2(new Item(20));
	ptr1->printValue();
	ptr2->printValue();
	swap(ptr1, ptr2);
	ptr1->printValue();
	ptr2->printValue();

	//Task 2
	std::cout << "Initial vector:" << std::endl;
	std::vector<int*> ptrVector;
	RandomFillVector(ptrVector, 10);
	PrintVector(ptrVector);
	std::cout << "Sorted vector:" << std::endl;
	SortPointers(ptrVector);
	PrintVector(ptrVector);
	
	//Task 3
	// 
	//count_if + find
	countVowels1();
	//count_if + for
	countVowels2();
	//for+find
	countVowels3();
	//for+for
	countVowels4();
}

