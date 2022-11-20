#include <iostream>
using namespace std;

void countSort(int array[], int size) {

  int last[10];
  int count[10];
  int max = array[0];

  for(int i=1;i<=size ;i++){
    if(array[i]> max)
    max=array[i];
  }
   for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }


  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }


  for (int i = size - 1; i >= 0; i--) {
    last[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  for (int i = 0; i < size; i++) {
    array[i] = last[i];
  }
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
int main() {
  int array[] = {6, 4, 2, 8, 5, 3, 1};
  int n = sizeof(array) / sizeof(array[0]);
  countSort(array, n);
  printArray(array, n);
}
