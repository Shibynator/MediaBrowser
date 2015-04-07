#pragma once

#include "Catalog.h"

#include "PictureFile.h"

using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class PictureCatalog : public Catalog
{
private:
	String ^ const endingPictureJPG = "\\*.jpg";

public:
	PictureCatalog();
	virtual ~PictureCatalog();

	virtual void import(String ^ folderPath);
	virtual PictureFile ^ getFile(DataGridViewRow ^ currentRow);

	virtual void save() override;
	virtual void load() override;
};

