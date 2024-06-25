//
// Created by Dante on 24.06.2024.
//
#include "printingVisualEss.h"
#include "../decleration.h"

void printArray(const int* arr, int size){
    for(int  i =0;i<size;i++){
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;
}

int findMax(const int *arr,int size){

    int max = *arr;

    for(int i=0;i<size;i++){
        if(*(arr+i) >= max){
            max = *(arr+i);
        }
    }
    return max;
}

void windowShow(int* arr, int size){

    int maxY = findMax(arr,size);

    float scaleW = (float)SCREEN_WIDTH/(float)size;
    float scaleH = (float)SCREEN_HEIGHT/(float)maxY;

    //window setup
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if(SDL_CreateWindowAndRenderer(SCREEN_WIDTH,SCREEN_HEIGHT,0,&window,&renderer)!=0){
        cout<<"WINDOW CREATION ERROR";
        return;
    }

    if(SDL_RenderSetScale(renderer,scaleW,scaleH)!=0){
        cout<<"RENDER SET ERROR";
        return;
    }

    //sorting + rendering
    selectionSort(arr,size,renderer);

}

void drawState(const int* arr, int size, SDL_Renderer* renderer, int red, int blue){
    for(int i = 0;i<size;i++){
        if(i ==red){
            SDL_SetRenderDrawColor(renderer,255,0,0,255);
        }else if(i==blue){
            SDL_SetRenderDrawColor(renderer,0,0,255,255);
        }else{
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }

        if(SDL_RenderDrawLine(renderer,i,size-1,i,*(arr+i))!=0){
            cout<<SDL_GetError();
            return;
        }
    }
}

void updateRenderer(const int* arr,int size, SDL_Renderer* renderer, int red, int blue){
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
    drawState(arr,size,renderer,red,blue);

    //show to window
    SDL_RenderPresent(renderer);


    SDL_Delay(10);
}
