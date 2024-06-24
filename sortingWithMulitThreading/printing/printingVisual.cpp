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

void windowShow(int* arr, int size){

    //window setup
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    if(SDL_CreateWindowAndRenderer(size*5,size*5,0,&window,&renderer)!=0){
        cout<<"WINDOW CREATION ERROR";
        return;
    }

    if(SDL_RenderSetScale(renderer,1,2)!=0){
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
