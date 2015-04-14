#pragma once

#include "Catalog.h"

#include "MovieFile.h"

using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class MovieCatalog : public Catalog
{
private:
	String ^ const endingMovieMP4 = "\\*.mp4";
	String ^ const pathSaveFileCatalog = "movieCatalog.xml";
	String ^ const pathSaveFileSchema = "movieSchema.xml";

public:
	MovieCatalog(String ^ pathSaveName, String ^ pathSaveSchema);
	virtual ~MovieCatalog();

	virtual void import(String ^ folderPath);

	MovieFile ^ getFile(DataGridViewRow ^ currentRow);
};

