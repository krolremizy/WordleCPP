#include <iostream>
#include <string>
#include <algorithm>
#include<fstream>
#include <vector>
#include "MenuLoop.h"

int main()
{
	srand(time(NULL));
	MenuLoop ml_object;
	ml_object.Loop();
}