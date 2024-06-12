#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"


using namespace std;

template<class T>

class List {

	public:
		//constructor
		List();
				
		//destructor
		~List();
		
		//other
		List& add(const T&);
		List& remove(const T&);
		const T& get(int index) const;
		int getSize() const;
		bool isFull() const;
		void clear();

		T& operator[](int index);
		const T& operator[](int index) const;

		List<T>& operator+=(const T& t);
		List<T>& operator-=(const T& t);
	
	
	private:
		int numElements;
		T* elements;
	
};

/// @brief Construct a new List<T>:: List object
/// @tparam T 
template<typename T>
List<T>::List(){
	elements = new T[MAX_ARR];
	numElements = 0;
}
/// @brief Destroy the List<T>:: List object
/// @tparam T 
template<typename T>
List<T>::~List(){
	delete [] elements;
}

/// @brief add a new element to the list
/// @tparam T 
/// @param s 
/// @return 
template<typename T>
List<T>& List<T>::add(const T& s){
	if (numElements >= MAX_ARR)   return *this;
  	elements[numElements++] = s;
	return *this;
}

/// @brief remove an element from the list
/// @tparam T 
/// @param s 
/// @return 
template<typename T>
List<T>& List<T>::remove(const T& s){
	int index = 0;
	while (index < numElements){
		if (s == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

/// @brief get the size of the list
/// @tparam T 
/// @return 
template<typename T>
int List<T>::getSize() const{
	return numElements;
}

/// @brief check if the list is full
/// @tparam T 
/// @return 
template<typename T>
bool List<T>::isFull() const {
	return numElements >= MAX_ARR;
}

/// @brief clear the list
/// @tparam T 
template<typename T>
void List<T>::clear() {
	numElements = 0;
}

/// @brief get an element from the list
/// @tparam T 
/// @param index 
/// @return 
template<typename T>
const T& List<T>::get(int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"List<T> index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

/// @brief get an element from the list
/// @tparam T 
/// @param index 
/// @return 
template<class T>
T& List<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr << "Index out of bounds" << endl;
		exit(1);
	} return elements[index];
}

/// @brief get an element from the list
/// @tparam T 
/// @param index 
/// @return 
template<class T>
const T& List<T>::operator[](int index) const {
	if (index < 0 || index >= numElements) {
		cerr << "Index out of bounds" << endl;
		exit(1);
	} return elements[index];
}

/// @brief add an element to the list
/// @tparam T 
/// @param t 
/// @return 
template<class T>
List<T>& List<T>::operator+=(const T& t) {
	if(numElements < MAX_ARR) {
		elements[numElements++] = t;
		return *this;
	}
	cerr << "List is full" << endl;
	exit(1);
	
}
/// @brief remove an element from the list
/// @tparam T 
/// @param t 
/// @return 
template<class T>
List<T>& List<T>::operator-=(const T& t) {
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

#endif