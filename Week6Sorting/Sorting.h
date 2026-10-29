// CMP201 Assignment 4: Sorting
// William Kavanagh, Abertay University, 2025 : w.kavanagh@abertay.ac.uk 
// updated: Autumn 2026.
// Partial Framework

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm> // you may want to use std::swap

struct Duck
{
	std::string breed;
	float wingSpan;
	int identifier;
	int age_months;

	// A little helper function to print duck facts
	void quack() const {
		std::cout << "\tDUCK: I am a(n) " << breed << ", my id is: " << identifier
			<< ". I am " << age_months << " months old and have a wingspan of "
			<< wingSpan << "cm\n";
	}

	// the standard comparison operators compare ducks by wingspan.
	std::partial_ordering operator<=>(const Duck& otherDuck) const
	{
		




		// TODO: Assessed [0.5 if compareDucksByAge is also correct]
		return wingSpan <=> otherDuck.wingSpan;
	}

};

// Create a duck army
inline std::vector<Duck> createDucks(int howManyDucks)
{
	// provided
	static const std::vector<std::string> breeds = {
		"Mallard", "Pekin", "Rouen", "Cayuga", "Muscovy", "Indian Runner" // more ducks: https://en.wikipedia.org/wiki/List_of_duck_breeds
	};

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> breed_dist(0, breeds.size() - 1);
	std::uniform_real_distribution<float> wingspan_dist(55.0f, 90.0f);
	std::uniform_int_distribution<> age_dist(3, 60);

	std::vector<Duck> ducks;
	ducks.reserve(howManyDucks);		// Saves multiple pesky resize operations

	for (int i = 0; i < howManyDucks; ++i)
	{
		ducks.push_back({
			breeds[breed_dist(gen)],
			wingspan_dist(gen),
			i,
			age_dist(gen)
			});
	}

	return ducks;
}

// Returns true if leftDuck is younger than rightDuck, false otherwise
inline bool compareDucksByAge(const Duck& leftDuck, const Duck& rightDuck)
{
	if (leftDuck.age_months <rightDuck.age_months) {

		return true;

	}




	// TODO Assessed [0.5 if operator<=> is also correct]
	return false;
}

// uses a callable comparator to sort a vector using cocktailshaker sort (bidirectional bubblesort).
template <typename T, typename Compare>
void CocktailShakerSort(std::vector<T>& vector, Compare comp)
{

	

	for (int i = 0; i < vector.size() - 1; ++i) {
		for (int j = 0; j < vector.size() - i - 1;++j) {

			if (comp(vector[j + 1], vector[j])) {

				std::swap(vector[j],vector[j+1]);
			}
		}

		for (int j = vector.size() - 1; j > vector.size() - 1 + i; --j) {

			if (comp(vector[j], vector[j - 1])) {


				std::swap(vector[j-1], vector[j]);


			}

		}

	}



	// TODO: Assessed [1.0]


}

// zips together templated vector by dividing into two subvectors and merging back in order
// NOTE: marks will be lost if your implementation is not stable
template <class T>
void Merge(std::vector<T>& vector, int start, int mid, int end)
{
	

	
	std::vector<T> halfL(vector.begin() + start, vector.begin() + mid);
	std::vector<T> halfR (vector.begin()+mid+1, vector.begin()+end);

	std::cout << "merging with a collection of " << end - start << "elements\n";

	int leftI = 0;
	int rightI = 0;
	int mainI = start;
	while (leftI < halfL.size() && rightI < halfR.size()) {

		if (halfR.at(rightI) < halfL.at(leftI) ) {

			vector.at(mainI) = halfR.at(rightI);
			++rightI;
			++mainI;

		}
		else {
			vector.at(mainI) = halfL.at(leftI);
			++leftI;
			++mainI;

		}
		


	}


	while (leftI < halfL.size()) {

		vector.at(mainI) = halfL.at(leftI);
		++leftI;
		++mainI;


	}

	while (rightI < halfR.size()) {

		vector.at(mainI) = halfR.at(rightI);
		++rightI;
		++mainI;


	}
	// TODO: Assessed [1.5] (0.5 of which is for stability, which requires mergeSort to be good also)

}

// templated recursive sort using calls to MergeSort. Should be O(n log(n) )
template <class T>
void MergeSort(std::vector<T>& vector, int start, int end)
{
	int mid = (start + end) / 2;
	if (start < end) {
		MergeSort(vector, start, mid);
		MergeSort(vector, mid+1, end);

		Merge(vector, start, mid, end);
	}

	// TODO: assessed [0.5]
}

// A simple wrapper for MergeSorts recursive calls.
template <class T> void MergeSort(std::vector<T>& collection)
{
	// Provided
	MergeSort(collection, 0, static_cast<int>(collection.size() - 1));	// cast from size_t to handle warnings
}

// Partition function for QuickSort.
// Runs in O(n) and chooses the final element as the pivot
template <class T>
int partition(std::vector<T>& collection, int begin, int end)
{
	int start = begin - 1;






	// TODO: Assessed [1.0]
	// NOTE: other pivot selection will result in marks being deducted.
	return -1;
}

// Sorting using partition() and recusion. Runs in O(n log(n))
template <class T>
void QuickSort(std::vector<T>& collection, int begin, int end)
{
	// TODO: Assessed [0.5]
	
}

// A simple wrapper for QuickSorts recursive calls.
template <class T> void QuickSort(std::vector<T>& collection)
{
	// Provided
	QuickSort(collection, 0, static_cast<int>(collection.size() - 1));
}