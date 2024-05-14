#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>


std::vector<int> generateArray(const size_t len) {
	std::vector<int> arr(len);
	//std::srand(0);
	std::srand(std::time(nullptr));
	for (auto &num : arr) {
		num = std::rand() % 100;
	}
	return arr;
}


template <typename T>
void printArr(const T &arr) {
	for (const auto &num : arr) {
		std::cout << num << ' ';
	}
	std::cout << '\n';
}


template <typename T>
void bubbleSortIter(T begin, T end) {
	bool sorted{0};
	--end;
	while (!sorted) {
		sorted = 1;
		for (auto it{begin}; it!= end; ++it){
			const auto nextIt {it+1};
			if (*it > *nextIt) {
				const auto tmp {*it};
				*it = *nextIt;
				*nextIt = tmp;
				sorted = 0;
			}
		}
		--end;

	}


}

template <typename T>
void bubbleSortIndex(T &arr) { // Reference of array
	bool sorted{0};
	size_t len{arr.size()-1};
	while (!sorted){ // Exit when sorted
		sorted = 1;
		for (size_t i{0}; i < len; ++i){ // iterate 
			if (arr[i] > arr[i+1]){
				const auto tmp {arr[i]}; // Swap item i & i+1
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
				sorted = 0;
			}
		}
		--len; // iterate one less each time as largest values will be sorted
	}
}



template <typename T>
void insertionSort(T &arr) {
	size_t len{arr.size()};
	size_t sorted{len-1};
	for (size_t i{0}; i < len; ++i) {
		size_t j{0};
		const auto item{arr[j]};
		for (; j < len-1; ++j) {

			// swap items

			if (j < sorted || item > arr[j+1]) {
				arr[j] = arr[j+1];
			} else {
				break;
			}
		}

		arr[j] = item;

			
		--sorted;
		//printArr(arr);

	}
}


template <typename T>
void insertionSort2(T &arr) {
	size_t len{arr.size()};
	for (size_t i{1}; i < len; ++i) { // start at index 1 not 0 as index 0 is already sorted
		size_t j{i};
		const auto item{arr[i]};
		while (j > 0 && item < arr[j-1]) {

			// swap items

			arr[j] = arr[j-1];
			
			--j;
		}

		arr[j] = item;

			
		//printArr(arr);

	}
}



int main() {
	const size_t len{10};
	std::vector<int> arr{generateArray(len)};

	printArr(arr);



	// Bubble sort using iterator
	{
		std::cout << "Bubble sort using iterator: ";

		std::vector<int> arr2sort {arr};
		const auto start {std::chrono::high_resolution_clock::now()};

		bubbleSortIter(arr2sort.begin(),arr2sort.end());

		const auto stop = std::chrono::high_resolution_clock::now();
		const auto duration {std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start)};
		std::cout << duration.count() << '\n';
	}


	// Bubble sort using index
	{	
		std::cout << "Bubble sort using index: ";
		
		std::vector<int> arr2sort {arr};
		const auto start {std::chrono::high_resolution_clock::now()};

		bubbleSortIndex(arr2sort);

		const auto stop {std::chrono::high_resolution_clock::now()};
		const auto duration {std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start)};
		std::cout << duration.count() << '\n';
	}




	// insertion sort
	{	
		std::cout << "Insertion sort bad: ";

		std::vector<int> arr2sort {arr};
		const auto start {std::chrono::high_resolution_clock::now()};

		insertionSort(arr2sort);

		const auto stop {std::chrono::high_resolution_clock::now()};
		const auto duration {std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start)};
		std::cout << duration.count() << '\n';
	}


	// insertion sort 2
	{
		std::cout << "Insertion sort good: ";

		std::vector<int> arr2sort {arr};
		const auto start {std::chrono::high_resolution_clock::now()};

		insertionSort2(arr2sort);

		const auto stop {std::chrono::high_resolution_clock::now()};
		const auto duration {std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start)};
		std::cout << duration.count() << '\n';
		printArr(arr2sort);
	}


	// Built in sort using introsort - combination of quicksort and heapsort

	{	
		std::cout << "Built-in sort: ";

		std::vector<int> arr2sort {arr};
		const auto start {std::chrono::high_resolution_clock::now()};

		std::sort(arr2sort.begin(),arr2sort.end());

		const auto stop {std::chrono::high_resolution_clock::now()};
		const auto duration {std::chrono::duration_cast<std::chrono::nanoseconds>(stop-start)};
		std::cout << duration.count() << '\n';


	}








	return 0;
}





