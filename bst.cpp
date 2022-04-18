#include <iostream>
#include <cstring>
#include <math.h>
#include "bst.h"

#if 0
Justin Iness
3/28/2022
C++ Programming
Heap
#endif

using namespace std;

node::node(int number) { // parametized constructor
	data = number;
	left = NULL;
	right = NULL;
}
node::~node() { // destructor

}
