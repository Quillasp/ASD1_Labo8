#ifndef selectionsort_h
#define selectionsort_h

#include "forwardListUtils.h"

template <class T>
void selectionSort(std::forward_list<T>& L) {
  using namespace std;
  
	//  Complétez cette fonction
	auto write_pointer = L.before_begin();
	auto predecessor = L.before_begin();
	auto current = next(predecessor);

	if (!L.empty()) {
		while (next(current) != L.end()) {
			auto pre_min = predecessor;
			auto min = current;
			auto pred2 = predecessor;
			auto curr2 = current;

			while (curr2 != L.end()) {
				if (*curr2 < *min) {
					min = curr2;
					pre_min = pred2;
				}
				pred2 = curr2;
				curr2 = next(pred2);
			}

			L.splice_after(write_pointer, L, pre_min);

			if (min == current) {
				cout << L << endl;
				write_pointer = next(write_pointer);
				predecessor = current;
			}

			current = next(predecessor);
		}
	}
}
#endif