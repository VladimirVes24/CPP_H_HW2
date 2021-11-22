#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

void countVowels1()
{
	auto start = std::chrono::high_resolution_clock::now();

	std::ifstream file("voina-i-mirTEST.txt");
	if (!file.is_open()) 
	{
		std::cout << "Could not read the file!" << std::endl;
		return;
	}

	std::string vowels = "AEIOUYaeiouy";

	size_t count = std::count_if(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>(),[=](char x){return vowels.find(x) != std::string::npos;});
	file.close();

	auto finish = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << "(Count_if + find) took " << result.count() << " milliseconds.\n";
	std::cout << "Number of vowels: " << count << std::endl;
}


void countVowels2()
{
	auto start = std::chrono::high_resolution_clock::now();

	std::ifstream file("voina-i-mirTEST.txt");
	if (!file.is_open())
	{
		std::cout << "Could not read the file!" << std::endl;
		return;
	}

	std::string vowels = "AEIOUYaeiouy";

	size_t count = std::count_if(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), [=](char x) -> bool {for (auto chr : vowels) { if (chr == x) return true; } return false;});
	file.close();

	auto finish = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << "(Count_if + for) took " << result.count() << " milliseconds.\n";
	std::cout << "Number of vowels: " << count << std::endl;
}

void countVowels3()
{
	auto start = std::chrono::high_resolution_clock::now();

	std::ifstream file("voina-i-mirTEST.txt");
	if (!file.is_open())
	{
		std::cout << "Could not read the file!" << std::endl;
		return;
	}

	std::string vowels = "AEIOUYaeiouy";
	size_t count = 0;

	for (auto it = std::istreambuf_iterator<char>(file); it != std::istreambuf_iterator<char>(); ++it)
	{
		if (vowels.find(*it) != std::string::npos) ++count;
	}

	file.close();

	auto finish = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << "(For + find) took " << result.count() << " milliseconds.\n";
	std::cout << "Number of vowels: " << count << std::endl;
}

void countVowels4()
{
	auto start = std::chrono::high_resolution_clock::now();

	std::ifstream file("voina-i-mirTEST.txt");
	if (!file.is_open())
	{
		std::cout << "Could not read the file!" << std::endl;
		return;
	}

	std::string vowels = "AEIOUYaeiouy";
	size_t count = 0;

	for (auto it = std::istreambuf_iterator<char>(file); it != std::istreambuf_iterator<char>(); ++it)
	{
		for (char chr : vowels)
		{
			if (*it == chr && *it != std::string::npos) ++count;
		}
	}

	file.close();

	auto finish = std::chrono::high_resolution_clock::now();
	auto result = std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
	std::cout << "(For + for) took " << result.count() << " milliseconds.\n";
	std::cout << "Number of vowels: " << count << std::endl;
}

