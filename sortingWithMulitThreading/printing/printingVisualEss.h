//
// Created by Dante on 24.06.2024.
//

#ifndef SORTINGWITHMULITTHREADING_PRINTINGVISUALESS_H
#define SORTINGWITHMULITTHREADING_PRINTINGVISUALESS_H

#include <cstdio>
#include <cstdlib>

#include <bits/stdc++.h>

#include "SDL.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;


void printArray(const int arr[], int size);

void windowShow(int* arr, int size);
void drawState(const int* arr,int size, SDL_Renderer* renderer, int red, int blue);

#endif //SORTINGWITHMULITTHREADING_PRINTINGVISUALESS_H
