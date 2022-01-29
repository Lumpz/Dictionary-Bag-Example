/*  Blake Bonheim -- CSIS 215 Programming Assignment 1 -- Bag Dictionary  */
/*    This assignment was worked on with my partner Jarred Patterson      */

#ifndef ABAG_H
#define ABAG_H

#include <iostream>
#include <stdlib.h>
#include "bagADT.h"
#include "kvpair.h"
#include "book.h"


template <typename E>
class ABag : public Bag<E>{            //Bag is base and ABag is derived class
public: 
	ABag()                             //Constructor
	{ 
		myArray = new E[defaultSize];  //Initialize myArray with the defaultSize
		arraySize = 0;
	}
	~ABag() {}                         //Destructor

	bool addItem(const E& item)        //add a KVPair to myArray and increase size
	{
        if (arraySize < 10)
        {
            myArray[arraySize] = item;
            arraySize++;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(E& item)           //search for a KVPair in myArray and remove if found. Shift the values of the array and decrease the size.
    {
        
        for (int i =(arraySize - 1 ); i > -1; i--)         //loop through array top-to-bottom
        {
            if (myArray[i] == item)                       //compare item in array to item passed in using the overloaded '==' operator
            {
                item = myArray[i];
                for (int b = i; b < (arraySize - 1); b++)  //shift the items above the removed item down
                {
                    myArray[b] = myArray[b + 1];
                }
                arraySize--;
                return true;
            }
        }
        return false;
    }
     
    bool removeTop(E& returnValue)                   //remove the top item in the array and decrease the size
    {
        if (arraySize > 0)
        {
            returnValue = myArray[arraySize - 1];
            arraySize--;
            return true;
        }
        else
        {
            return false;
        }
    }
     
    bool find(E& returnValue) const        //loop through myArray and compare keys to the item passed in. if it is found, update the items value
    {
        for (int i = (arraySize - 1); i > -1; i--)
        {
            if (myArray[i] == returnValue)
            {
                returnValue = myArray[i];
                return true;
            }
        }
        return false;
    }
      
    bool inspectTop(E& item) const        //inspect the item on top of myArray and update the passed in item value
    {
        if (arraySize == 0)
        {
            return false;
        }
        else
        {
            item = myArray[arraySize - 1];
            return true;
        }
    }
     
    void emptyBag()                      //'empty' the bag by setting the array size to zero
    {
        arraySize = 0;
    }
     
    bool operator+=(const E& addend)    //overload the += operator to allow it to add an item to the array
    {
        addItem(addend);
        return true;
    }
     
    int size() const                   //return the size of the array
    {
        return arraySize;
    }
     
    int bagCapacity() const            //return the capacity of the array
    {
        return defaultSize;
    }

private:
	int arraySize;                    //create a private member variable to store array size
	 E* myArray;                      //create a private member variable to point to myArray  
};

#endif