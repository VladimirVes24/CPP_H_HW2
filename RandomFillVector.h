#pragma once

template <typename T>
void RandomFillVector(std::vector<T*> &v, int size)
{
	v.resize(size);
	auto iter = v.begin();
	while (iter != v.end())
	{
		*iter = new T;
		++iter;
	}
};

template <>
void RandomFillVector(std::vector<int*> &v, int size)
{
	std::srand(static_cast<uint16_t>(std::time(0)));
	v.resize(size);
	auto iter = v.begin();
	while (iter != v.end())
	{
		*iter = new int(rand() % 100);
		++iter;
	}
};