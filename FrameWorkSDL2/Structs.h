#pragma once


template<typename T>
class CCoords {
public :
	T x;
	T y;
};

template<typename T>
class CDimensions {
public :
	T w;
	T h;
};

template<typename T>
class CSpeed {
public:
	T x;
	T y;
};



template<typename T>
class CElement {
public:
	T value;
	CElement* pNext;
};


