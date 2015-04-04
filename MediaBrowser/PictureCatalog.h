#pragma once

#include "Catalog.h"

#include "PictureFile.h"

using namespace System::Collections::Generic;

ref class PictureCatalog : public Catalog
{
private:
	String ^ const endingPictureJPG = "\\*.jpg";

public:
	PictureCatalog();
	virtual ~PictureCatalog();

	virtual void import(String ^ folderPath);
	virtual void search() override;
	virtual void sort() override;
	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;
};

