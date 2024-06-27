//
// Created by Dante on 24.06.2024.
//
#include "decleration.h"
#include "printing/printingVisualEss.h"

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int* generateArray(int size){
    if(size<=0){
        return reinterpret_cast<int *>(-1);
    }
    int *arr = (int*) calloc(size, sizeof(int));

    if(arr==nullptr){
        cout<<"ERROR ALLOCATING MEMORY"<<endl;
        return reinterpret_cast<int *>(-2);
    }

    srand(time(nullptr));
    for(int i =0;i<size;i++){
        *(arr+i) = rand() % 100 + 1;
    }
    return arr;
}

void destroyArray(int* arr){
    if(arr == nullptr){
        return;
    } else{
        free(arr);
    }
}

bool isRunning(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            return false;
        default:
            return true;
    }
}

void shuffle_array(int* arr, int n, SDL_Renderer* renderer){
    if(isRunning()){
    }else{
        return;
    }
    // To obtain a time-based seed
    unsigned seed = 0;

    // Shuffling our array a little bit
    for (int i=0;i<100;i++){

        shuffle(arr, arr + n,default_random_engine(seed));
        updateRenderer(arr,n,renderer,-1,-1);
        SDL_Delay(10);

        if(isRunning()){
            continue;
        }else{
            return;
        }
    }

}

void selectionSort(int* arr, int n, SDL_Renderer* renderer){

    clock_t runTime;
    runTime = clock();

    for(int i=0;i<n-1;i++){
        int min_index = i;

        for(int j = i +1; j<n ;j++){
            if(*(arr+j) > *(arr+min_index)){
                min_index = j;
            }
            if(isRunning()){
                continue;
            }else{
                return;
            }
        }

        if(min_index != i){
            swap((arr+min_index),(arr+i));
            //update render
            updateRenderer(arr,n,renderer,min_index,i);
        }
    }
    SDL_Delay(1000);
    //terminal use only

    cout<<SDL_GetError();
    runTime = clock() - runTime;
    cout<<"Execution time: "<<(float)runTime/CLOCKS_PER_SEC <<"seconds"<<endl;
    SDL_Delay(1000);
    printArray(arr,n);
    destroyArray(arr);
}

void bubbleSort(int* arr, int n, SDL_Renderer* renderer){
    bool swaped;
    for(int i =0;i<n;i++){
        swaped = false;
        for(int j = 0;j<n-i-1;j++){
            if(*(arr+j) < *(arr+j+1)){
                swap(*(arr+j),*(arr+j+1));
                swaped = true;

                //update render
                updateRenderer(arr,n,renderer,j,i);

                if(isRunning()){
                    continue;
                }else{
                    return;
                }
            }
        }
        if(!swaped){
            break;
        }
    }
    SDL_Delay(1000);
}

void insertionSort(int* arr, int n, SDL_Renderer* renderer){
    int klucz,j;
    for(int i = 1;i<n;i++){
        klucz = *(arr+i);
        j = i-1;
        while (j >= 0 && *(arr+j) > klucz){
            *(arr+j+1) = *(arr+j);
            j--;

            //updateRenderer(arr,n,renderer,j,i);
//            if(isRunning()){
//                continue;
//            }else{
//                return;
//            }
        }

        *(arr+j+1) = klucz;
        printArray(arr, n);
    }
}