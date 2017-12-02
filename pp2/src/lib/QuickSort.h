# ifndef QUICKSORT_H
# define QUICKSORT_H

# include"DoubleLinkedList.h"

template<typename T>
class QuickSort {
public:
  int partition(DoubleLinkedList<T>& A, int low, int high);
  void sort(DoubleLinkedList<T>& A, int low, int high);

};

template<typename T>
int QuickSort<T> ::partition(DoubleLinkedList<T>& A, int low, int high){
  T pivot = A.get(low);
  T temp = A.get(high + 1);
  A.update(high + 1, pivot);

  int i = low, j = high + 1;

  while(i <= j){
    do{
        i++;
    }while(A.get(i) < pivot);
    do{
        j--;
    }
    while(A.get(j) > pivot);
    if(i < j){
      T aux = A.get(i);
      A.update(i, A.get(j));
      A.update(j, aux);
    }
  }
  T aux = A.get(low);
  A.update(low, A.get(j));
  A.update(j, aux);

  A.update(high + 1, temp);

  return j;
}

template<typename T>
void QuickSort<T>::sort(DoubleLinkedList<T>& A, int low, int high){
  if(low < high){
    int q = partition(A, low, high);
    sort(A, low, q - 1);
    sort(A, q + 1, high);
  }
}

# endif
