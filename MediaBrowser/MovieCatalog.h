#pragma once

#include "Catalog.h"

#include "MovieFile.h"

using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class MovieCatalog : public Catalog
{
private:
	String ^ const endingMovieMP4 = "\\*.mp4";

public:
	MovieCatalog();
	virtual ~MovieCatalog();

	virtual void import(String ^ folderPath);
	virtual MovieFile ^ getFile(DataGridViewRow ^ currentRow);

	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;
};

