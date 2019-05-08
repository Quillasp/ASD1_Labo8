
#include "fizzy.h"
#include <cassert>

using std::forward_list;


//Vous pouvez ajouter des fonctions annexes si nécessaire

void fizzy(std::forward_list<int>& dest,
		     std::forward_list<int>& fwrd,
		     int comp);

void fizzBuzz(std::forward_list<int>& L,
              std::forward_list<int>& F,
              std::forward_list<int>& B,
              std::forward_list<int>& FB)
{
  assert(F.empty() and B.empty() and FB.empty());

// à compléter

   fizzy(FB, L, 15);
   fizzy(B, L, 5);
   fizzy(F, L, 3);
}

void fizzy(std::forward_list<int>& dest,
		     std::forward_list<int>& fwrd,
		     int comp) {
	auto write_pointer = dest.before_begin();
	auto predecessor = fwrd.before_begin();
	auto current = next(predecessor);
   
	while (current != fwrd.end()) {
		if ((*(current) % comp) == 0) {
			dest.splice_after(write_pointer, fwrd, predecessor);
			write_pointer = next(write_pointer);
		} else {
			predecessor = current;
		}
		current = next(predecessor);
	}
}
