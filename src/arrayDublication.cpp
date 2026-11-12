//  char **arrayDubliction(char *arr, int &capacity, int size ){
//  int newCapacaty = capacity *2;
//  char *newArr = new char[newCapacaty];
//  for (int i = 0; i < size; i++){
//    newArr[i] = arr[i];
//  }
//      delete[] arr;
//    capacity = newCapacity;
//    return newArr;
//
//  }
//

  char **arrayDuplication(char** arr, int& capacity, int size) {

    int newCapacity = capacity * 2;

    char **newArr = new char*[newCapacity]{};

    // Copy old pointers
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    // Delete old pointer array
    delete[] arr;

    capacity = newCapacity;

    return newArr;
}


 void addElementToDynamicArray(char **& arr, int& size, int& capacity, const char *ele){
    if(size == capacity){

        arr = arrayDuplication(arr, capacity, size);
    }
    int counter = 0;
    while(ele[counter] != '\0'){
        counter++;
    }


char* newElement = new char[counter + 1];
for(int i = 0; i < counter + 1 ; i++){
        newElement[i] = ele[i];
 }
arr[size] = newElement;
 size++;
 }
