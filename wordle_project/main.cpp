#include <iostream>
#include <string>
#include <algorithm>
#include<fstream>
#include <vector>
#include "GameLoop.h"

int main()
{
	srand(time(NULL));
	GameLoop gl_object;
	gl_object.MenuLoop();
}