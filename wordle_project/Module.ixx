#include <iostream>
export module Module;

export class Random
{
public:

	 int RandomWordGenerator(int vecSize)
	{
		return rand() % vecSize;
	}
};