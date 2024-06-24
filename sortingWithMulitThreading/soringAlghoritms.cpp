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

void selectionSort(int* arr, int n, SDL_Renderer* renderer){

    clock_t runTime;
    runTime = clock();

    for(int i=0;i<n-1;i++){
        int min_index = i;

        for(int j = i +1; j<n ;j++){
            if(*(arr+j) < *(arr+min_index)){
                min_index = j;
            }
        }

        if(min_index != i){
            swap((arr+min_index),(arr+i));

            //clear screen
            if(SDL_SetRenderDrawColor(renderer,0,0,0,255)!=0){
                cout<<"SetRenderDrawColor ERROR";
                return;
            }
            if(SDL_RenderClear(renderer)!=0){
                cout<<"RENDER CLEAR ERROR";
                return;
            }
            //draw update
            drawState(arr,n,renderer,min_index,i);

            //show to window
            SDL_RenderPresent(renderer);


            SDL_Delay(10);
        }

    }
    //cout<<SDL_GetError();
    runTime = clock() - runTime;
    cout<<"Execution time: "<<(float)runTime/CLOCKS_PER_SEC <<"seconds"<<endl;
    SDL_Delay(1000);
    printArray(arr,n);
    destroyArray(arr);
}