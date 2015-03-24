#pragma once

#include "MusicFile.h"

using namespace System;
using namespace System::Data;

ref class Catalog : DataSet
{
private:
	DataTable mediaTable;

public:
	Catalog();
	virtual ~Catalog();

	virtual void import();
	virtual void search();
	virtual void sort();
	virtual void remove();
	virtual void save();
	virtual void load();
};

