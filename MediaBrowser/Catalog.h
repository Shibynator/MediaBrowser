#pragma once
#include "MediaFile.h"

#include "MusicFile.h"

using namespace System;
using namespace System::Data;

ref class Catalog : public DataTable
{
protected:

public:
	Catalog();
	virtual ~Catalog();

	virtual void import();
	virtual void search();
	virtual void sort();
	virtual void remove();
	virtual void save();
	virtual void load();

	void Add(MediaFile ^newFile);
};

