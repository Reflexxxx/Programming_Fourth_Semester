#include "Sortings.h"
#include "helpers.h"

using std::swap;

Sortings::Sortings()
{

}

Sortings::~Sortings()
{

}

std::function<void(std::vector<Element>::iterator , std::vector<Element>::iterator , std::function<bool(Element, Element)>)> Sortings::getBubbleSort()
{

	auto func = [](std::vector<Element>::iterator begin, std::vector<Element>::iterator end, std::function<bool(Element,Element)> comp)
	{
		for (auto i = begin; i != end; i++)
		{
			for (auto j = i; j != end; j++)
			{
				if (comp(*i, *j))
				{
					swap(*i, *j);
				}
			}
		}
	};

	return func;
}

std::function<void(std::vector<Element>::iterator, std::vector<Element>::iterator, std::function<bool(Element, Element)>)> Sortings::getInsertionSort()
{

	auto func = [](std::vector<Element>::iterator begin, std::vector<Element>::iterator end, std::function<bool(Element, Element)> comp)
	{
		for (auto i = begin; i != end; i++)
		{ 

			for (auto j = i - 1; j != begin; j--)
			{
				
				if (comp(*i, *j))
				{
					swap(*i, *j);
				}
			}
		}
	};

	return func;
}

std::function<void(std::vector<Element>::iterator, std::vector<Element>::iterator, std::function<bool(Element, Element)>)> Sortings::getSelectionSort()
{

	auto func = [](std::vector<Element>::iterator begin, std::vector<Element>::iterator end, std::function<bool(Element, Element)> comp)
	{
		for (auto i = begin; i != end; i++)
		{
			auto min_pos = i;
			for (auto j = i+1; j != end; j++)
			{
				if (comp(*j, *i))
				{
					min_pos = j;
					if (min_pos < i) {
						swap(*i, *j);
					}
				}
			}
			

		}
	};

	return func;

/*
void Sorting::start_sort(QString name_algorithms, const int *arr, int size)
{
	int *array = new int[static_cast<unsigned long long>(size)];
	for (int i = 0; i < size; i++)
		array[i] = arr[i];
	if (name_algorithms == "Bubble sort")
	{
		BubbleSort(array, size);
	}
	else if (name_algorithms == "Bogosort")
	{
		BogoSort(array, size);
	}
	else if (name_algorithms == "Selection sort")
	{
		SelectionSort(array, size);
	}
	else if (name_algorithms == "Insertion sort")
	{
		InsertionSort(array, size);
	}
}


void Sorting::BogoSort(int *arr, int size)
{
	while (!isSorted(arr, size))
	{
		arr = shuffle(arr, size);
		emit nextIteration(arr);
	}
}

bool Sorting::isSorted(int *arr, int size)
{
	for (int i = 1; i < size; i++)
		if (arr[i] < arr[i - 1]) return false;
	return true;
}
*/
