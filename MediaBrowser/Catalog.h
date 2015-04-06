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
	virtual void getFile();

	virtual void remove();
	virtual void save();
	virtual void load();

	void add(MediaFile ^ newFile);
	void search(String ^ searchStr);
};

