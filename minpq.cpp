/**
 * Author: Cristian Mosqueda
 * Class: CSE 310 SUMMER SESSION
 * Date: 6/4/20
 * Purpose: Defining & implementing the Min Priority Queue class for Plane 
 * Landing System with the highest priority.
 */

#include "minpq.h"
#include <iostream>
using namespace std;

//implementation of min priority queue
PlaneLandSys::PlaneLandSys(int size) {
    heap_size = 0;
    array_length = size;
    heap = new int[size]; //dynamic memory allocation
}
//accessing parent & children
int PlaneLandSys::Parent(int i) {return (i - 1)/2;}
int PlaneLandSys::LeftChild(int i) {return (2 * i) + 1;}
int PlaneLandSys::RightChild(int i) {return (2 * i) + 2;}

void PlaneLandSys::Exchange(int* x, int* y) {
    //swap method
    int temp = *x;
    *x = *y;
    *y = temp;
}
void PlaneLandSys::MinHeapify(int i) {
    //getting the children indexes
    int smallest = 0;
    int left = LeftChild(i);
    int right = RightChild(i);
    if((left <= heap_size) && heap[left] < heap[i])
        smallest = left; //current smallest is left child i
    else
        smallest = i;
    if((right <= heap_size) && heap[right] < heap[smallest])
        smallest = right; //smallest of children is right index then
    if(smallest != i) {
        Exchange(&heap[i], &heap[smallest]);
        MinHeapify(smallest); //check if new child does not violate min heap property
    }    
}
//returning the minimum of the min-heap
int PlaneLandSys::HeapMinimum() {return heap[0];}
int PlaneLandSys::HeapExtractMinimum() {
    int min = 0;
    //no elements in the heap
    if(heap_size < 1) {
        cout << "Error: There are no planes currently awaiting landing." << endl;
    }
    else {
        min = HeapMinimum();
        heap[0] = heap[heap_size - 1]; //making root == to last element added
        heap_size--; //decrementing heap_size because of removal of the min
        MinHeapify(0);
    }
    return min;
}
void PlaneLandSys::HeapDecreaseKey(int i, int key) {
    if(key > heap[i]) {
        cout << "Error new key is larger than current key." << endl;
        return;
    }
    heap[i] = key;
    //checks if the min-heap property is violated going in a bubble up manner
    while(i > 0 && heap[Parent(i)] > heap[i]) {
        Exchange(&heap[i], &heap[Parent(i)]);
        i = Parent(i);
    }
}
void PlaneLandSys::MinHeapInsert(int key) {
    if(heap_size != array_length) {
        heap_size++;
        heap[heap_size - 1] = INT_MAX; //INFINITY
        HeapDecreaseKey((heap_size - 1), key);
    }
    else {
        cout << "Error: HEAP MEMORY HAS BEEN EXHAUSTED.\n\tPROCEED TO SYSTEM EXIT." << endl;
    }
    
}

//print out the heap or valid elements in the heap minq
void PlaneLandSys::ListRequests() {
    if(heap_size != 0) {
        cout << "Plane Landing Priority Queue: " << endl;
        for(int i = 0; i < heap_size; i++) {
            printf("Priority Level %d: Plane %d requesting landing in %d minute(s).\n",(i + 1), (i + 1), heap[i]);
        }
        cout << endl;
    }
    else
        cout << "Error: No Landings have been requested." << endl;
}
//interface
char PlaneLandSys::menu() {
    char selection;
    cout << "***** Welcome to the Plane Landing Priority System Menu *****" << endl;
    cout << "Options:\n";
    cout << "1. Make a landing request." << endl;
    cout << "2. Land a plane." << endl;
    cout << "3. List all priority landing requests." << endl;
    cout << "4. Exit." << endl;

    cin >> selection;
    return selection;
}
