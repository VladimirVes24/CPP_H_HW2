#pragma once

template <typename T>
void SortPointers(std::vector<T*> &v)
{
	std::sort(v.begin(), v.end(), [](const T* a, const T* b) {return *a < *b;});
}
