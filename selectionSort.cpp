#ifndef selectionsort_h
#define selectionsort_h

#include "listUtils.h"
#include <algorithm>

template <class T>
void selectionSort(std::list<T>& L) {
  
  //  Complétez le code du tri par sélection sur une liste doublement chainée
  //  où le minimum trouvé est mis en place avec un appel à la fonction splice
  //  au lieu d'un swap.
  //
  //  Affichez l'état de la liste avec
  //
  //    std::cout << L << std::endl;
  //
  //  après chaque appel à splice
  
  auto write_pointer = L.begin();
  auto current = L.begin();
  
  while (next(current) != L.end()) {
    auto min = std::min_element(current, L.end());
    L.splice(write_pointer, L, min);
    std::cout << L << std::endl;
    if (min == current) {
      write_pointer = next(write_pointer);
      current = next(current);
    }
  }
}

#endif