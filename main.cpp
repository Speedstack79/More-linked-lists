#include <iostream>
#include "LinkedList.h"
using namespace std;

//odd modulo will be in order of name      0
//even modulo will be in order of weight   1

int main(void)
{
	LinkedList<string> list;
	list.add("Jim", "150");
    list.add("Tom", "212");
    list.add("Michael", "174");
    list.add("Abe", "199");
    list.add("Richard", "200");
    list.add("April", "117");
    list.add("Claire", "124");
    list.add("Bobby", "109");
    list.add("Bob", "156");
    list.add("Kevin", "145");
    list.add("Jason", "182");
    list.add("Brian", "150");
    list.add("Chris", "175");
    list.add("Steven", "164");
    list.add("Annabelle", "99");
	list.printAllNames();
	list.printAllWeights();
    cout << "\nPress enter to exit.\n";
    cin.get();

	return 0;
}

