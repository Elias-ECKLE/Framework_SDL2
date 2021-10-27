#pragma once
/*
#include "Structs.h"
#include<stdio.h>



template <typename T>
class CList {

	CElement<T>*  pStart;
	CElement<T>* pCourant;

public:

	//methodes 
	CList();
	~CList();
	void firstElmt();
	T nextElmt();
	void add(T val);;




};



template <typename T>
CList<T>::CList() {
	this->pStart = nullptr;
	this->pCourant = pStart;

}

template <typename T>
CList<T>::~CList() {

	CElement<T>* pSuiv;

	while (pCourant != nullptr) {
		pSuiv=pCourant->pNext;
		delete pCourant;
		pCourant = pSuiv;
	}
}


template <typename T>
void CList<T>::firstElmt() {

	this->pCourant = this->pStart;
}

template <typename T>
T CList<T>::nextElmt() {

	T padNext *= nullptr;
	if (this->pCourant!=nullptr) {
		padNext = this->pCourant->value;
		this->pCourant = this->pCourant->pNext;
	}
	return padNext;
	
}

template<typename T>
void CList<T>::add(T val) {


}

*/