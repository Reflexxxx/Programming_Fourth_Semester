#include "Sortings.h"
#include "helpers.h"

using std::swap;

Sortings::Sortings()
{

}

Sortings::~Sortings()
{

}

std::function<void(std::vector<Element>::iterator, std::vector<Element>::iterator, std::function<bool(Element, Element)>)> Sortings::getBubbleSort()
{

	auto func = [](std::vector<Element>::iterator begin, std::vector<Element>::iterator end, std::function<bool(Element, Element)> comp)
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
			while (j != begin && comp(key, *j))
			{
				if (comp(*i, *j))
				{
					*(j + 1) = *j;
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
					if (comp(*min_pos,*i)) {
						swap(*i, *j);
					}
				}
			}


		}
	};

	return func;

}


//int partition(int arr[], int low, int high)
//{
//	int pivot = arr[high];   
//	int i = (low - 1);  
//
//	for (int j = low; j <= high - 1; j++)
//	{
//	
//		if (arr[j] <= pivot)
//		{
//			i++;    
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}

//std::function<void(std::vector<element>::iterator, std::vector<element>::iterator, std::function<bool(element, element)>)> sortings::getquicksort()
//{
//
//  if (low < high) 
//{
//
//	int pi = partition(arr, low, high);
//
//	 separately sort elements before 
//	 partition and after partition 
//	quicksort(arr, low, pi - 1);
//	quicksort(arr, pi + 1, high);
//}
//
//}
//
//void merge(int arr[], int l, int m, int r)
//{
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//
//	int L[n1], R[n2];
//
//	for (i = 0; i < n1; i++)
//		L[i] = arr[l + i];
//	for (j = 0; j < n2; j++)
//		R[j] = arr[m + 1 + j];
//
//	i = 0; 
//	j = 0; 
//	k = l; 
//	while (i < n1 && j < n2)
//	{
//		if (L[i] <= R[j])
//		{
//			arr[k] = L[i];
//			i++;
//		}
//		else
//		{
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//
//	while (i < n1)
//	{
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//
//	while (j < n2)
//	{
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}

//std::function<void(std::vector<Element>::iterator, std::vector<Element>::iterator, std::function<bool(Element, Element)>)> Sortings::getMergeSort()
//{
//
//	 
	/*{
	int m = l + (r - l) / 2;

	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);

	merge(arr, l, m, r);
	}*/
//
//}
//
//void heapify(int arr[], int n, int i)
//{
//	int largest = i; 
//	int l = 2 * i + 1; 
//	int r = 2 * i + 2; 
//
//	if (l < n && arr[l] > arr[largest])
//		largest = l;
//
//	if (r < n && arr[r] > arr[largest])
//		largest = r;
//
//	if (largest != i)
//	{
//		swap(arr[i], arr[largest]);
//		heapify(arr, n, largest);
//	}
//}

//std::function<void(std::vector<Element>::iterator, std::vector<Element>::iterator, std::function<bool(Element, Element)>)> Sortings::getHeapSort()
//{
//
//for (int i = n / 2 - 1; i >= 0; i--)
//heapify(arr, n, i);
//
//for (int i = n - 1; i >= 0; i--)
//{
//	swap(arr[0], arr[i]);
//	heapify(arr, i, 0);
//}
//
//}