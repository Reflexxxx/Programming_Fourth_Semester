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
			auto key = *i;
			auto j = i - 1;
			while (j != begin && comp(*j, key))
			{
					if (comp(*i, *j))
					{
						*(j+1) = *j;
						j--;

					}
			}
			*(j + 1) = key;
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
			for (auto j = i + 1; j != end; j++)
			{
				if (comp(*j, *i))
				{
					min_pos = j;
					if (comp(*min_pos, *i)) {
						swap(*i, *j);
					}
				}
			}


		}
	};

						return func;
}

//std::function<void(std::vector<Element>::iterator, std::vector<Element>::iterator, std::function<bool(Element, Element)>)> Sortings::getQuickSort()
//{
//
//	auto func = [](std::vector<Element>::iterator begin, std::vector<Element>::iterator end, std::function<bool(Element, Element)> comp)
//	{
//		auto i, j, mid, piv;
//		i = L;
//		j = R;
//		mid = L + (R - L) / 2;
//		piv = ;
//
//		while (i<R || j>L) {
//			while (vec[i] < piv)
//				i++;
//			while (vec[j] > piv)
//				j--;
//
//			if (i <= j) {
//				swap(vec, i, j); //error=swap function doesnt take 3 arguments
//				i++;
//				j--;
//			}
//			else {
//				if (i < R)
//					quicksort(vec, i, R);
//				if (j > L)
//					quicksort(vec, L, j);
//				return;
//			}
//		}
//	}
//}