#pragma once

#include "Catalog.h"

#include "MovieFile.h"

using namespace System::Collections::Generic;

ref class MovieCatalog : public Catalog
{

public:
	MovieCatalog();
	virtual ~MovieCatalog();

	virtual void import() override;
	virtual void search() override;
	virtual void sort() override;
	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;

	void add(MovieFile ^ movieFile);
};

