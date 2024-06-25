#include "decleration.h"
#include "printing/printingVisualEss.h"

int main(int argc, char** argv){

    int arr_size = 1000;
    int* arr = generateArray(arr_size);
    windowShow(arr,arr_size);

    return 0;
}