/**
 * Author: Cristian Mosqueda
 * Class: CSE 310 SUMMER SESSION
 * Date: 6/4/20
 * Purpose: Declaring the Min Priority Queue class for Plane 
 * Landing System with the highest priority.
 */

#ifndef MINPQ_H_INCLUDED
#define MINPQ_H_INCLUDED

class PlaneLandSys
{
private:
    //members
    int heap_size; //valid elements included in heaps size
    int array_length; //array length
    int *heap; //actual heap

public:
    //constructor
    PlaneLandSys(int total_elements);
    //methods for the min priority queue
    int Parent(int i);
    int LeftChild(int i);
    int RightChild(int i);
    void Exchange(int* x, int* y);
    void MinHeapify(int index);
    int HeapMinimum();
    int HeapExtractMinimum();
    void HeapDecreaseKey(int i, int key);
    void MinHeapInsert(int key);
    void ListRequests();
    char menu();
};

#endif