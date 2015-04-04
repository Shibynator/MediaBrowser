#pragma once

#include "Catalog.h"

#include "MovieFile.h"

using namespace System::Collections::Generic;

ref class MovieCatalog : public Catalog
{
private:
	String ^ const endingMovieMP4 = "\\*.mp4";

public:
	MovieCatalog();
	virtual ~MovieCatalog();

	virtual void import(String ^ folderPath);

	virtual void search() override;
	virtual void sort() override;
	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;
};

