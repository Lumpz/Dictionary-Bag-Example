/*  Blake Bonheim -- CSIS 215 Programming Assignment 1 -- Bag Dictionary  */
/*    This assignment was worked on with my partner Jarred Patterson      */
#ifndef BDICTIONARY_H
#define BDICTIONARY_H

#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"
#include "book.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key,E> {   //Dictionary is the Base class and BDictionary is the derived class
public:
	BDictionary(int startSize)                   //pass the starting size of the array by passing in an INT in the constructor
    {
        myBag = ABag<KVpair<Key, E>>();          //initialize an ABag object as myBag
        
        bagSize = startSize;                     //store the bagSize 
    }
	~BDictionary()                               //Destructor
    {

    }

    void clear()                                 //clear the contents of the bag by calling the emptyBag function of myBag
    {
       myBag.emptyBag();
    }
   
    bool insert(const Key& k, const E& e)       //insert a key and value as a KVPair object into the bag
    {
        KVpair<Key, E> temp(k, e);
       
        return myBag += temp;
    }
   
    bool remove(const Key& k, E& rtnVal)        //remove a KVPair from the bag by using the Key passed in. Update the value from the bag
    {
        KVpair<Key, E> temp(k, rtnVal);         //create a temperary KVPair object to pass the key and value into the remove() function
        bool tempBool;
        if (myBag.remove(temp))
        {
            tempBool = true;                    //if the item was able to be found in the bag, return true
        }
        else
        {
            tempBool = false;                   //if the item was able to be found in the bag, return true
        }

        rtnVal = temp.value();                  //update the trnValue with the value from the removed bag item
        return tempBool;
    }
   
    bool removeAny(E& returnValue)              //remove an arbitrary item (we chose the top item) from the bag and return the value
    {
        
        KVpair<Key, E> temp;                    //create a temporary KVPair to store the returnValue

        if (myBag.removeTop(temp))
        {
            returnValue = temp.value();         //update the returnValue with the top bag item value
            return true;
        }
        else
        {
            return false;
        }
    }
   
    bool find(const Key& k, E& returnValue) const  //search the bag for the key passed in. If the key is found in the bag, return the bag value
    {
        KVpair<Key, E> temp(k, returnValue);       //create a temporary KVPair to store the passed in Key and Value
        return myBag.find(temp);
    }
   
    int size()                                     //returns the size of the bag
    {
        return myBag.size();
    }

private:
       ABag<KVpair<Key, E>> myBag;                 //create a private member variable to store the bag object
       int bagSize;                                //create a private member variable to store the bag size
};

#endif