#ifndef SORTINGWITHMULITTHREADING_DECLERATION_H
#define SORTINGWITHMULITTHREADING_DECLERATION_H

#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <bits/stdc++.h>
#include "SDL.h"

using namespace std;


void swap(int *xp, int *yp);
int* generateArray(int size);
void destroyArray(int* arr);

bool isRunning();

void shuffle_array(int arr[], int n, SDL_Renderer* renderer);

void selectionSort(int* arr, int n, SDL_Renderer* renderer);
void bubbleSort(int* arr, int n, SDL_Renderer* renderer);
void insertionSort(int* arr, int n, SDL_Renderer* renderer);
#endif //SORTINGWITHMULITTHREADING_DECLERATION_H
