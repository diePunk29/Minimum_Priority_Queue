/**
 * Author: Cristian Mosqueda
 * Class: CSE 310 SUMMER SESSION
 * Date: 6/4/20
 * Purpose: Running the Min Priority Queue in this driver for the Plane Landing
 * Priority System.
 */

#include "minpq.cpp"
#include <iostream>
using namespace std;

int main() {
    cout << "*****\tPLANE LANDING SYSTEM INITIALIZATION\t*****" << endl;
    //prompting user for array size for heap
    cout << "Enter the number of incoming landing requests (array size) for the heap:\n> ";
    int length = 0;
    cin >> length;

    //creating a min priority que with length chosen by user
    PlaneLandSys minpq(length);
    char choice;
    int key, priority;
    key = priority = 0;

    do
    {   //calling the menu
        choice = minpq.menu();
        //switchcase for the menu
        switch (choice)
        {
        case '1': cout << "Enter the key value you wish to insert:\n> ";
                  cin >> key;
                  minpq.MinHeapInsert(key);
                  break;

        case '2': priority = minpq.HeapExtractMinimum();
                  if(priority != 0)
                        cout << "Plane that requested landing " << priority << " minute(s) ago, has landed." << endl;
                  break;
        
        case '3': minpq.ListRequests();
                  break;

        default:  cout << "****Interface Exit****" << endl;
                  break;
        }
    } while (choice == '1' || choice == '2' || choice == '3');

    return 0;
    
}