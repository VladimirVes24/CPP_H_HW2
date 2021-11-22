#pragma once


template <typename T>
void PrintVector(const std::vector<T*> &v)
{
	auto iter = v.begin();
	while (iter != v.end())
	{
		std::cout << **iter << " ";
		++iter;
	}
	std::cout << std::endl;
}