#pragma once

#include "Catalog.h"

#include "PictureFile.h"

using namespace System::Collections::Generic;

typedef List<PictureFile ^> LISTPICTURE;

ref class PictureCatalog : public Catalog
{
private:
	LISTPICTURE ^ pictureList = gcnew LISTPICTURE();

public:
	PictureCatalog();
	virtual ~PictureCatalog();

	virtual void import() override;
	virtual void search() override;
	virtual void sort() override;
	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;

	void add(PictureFile ^ pictureFile);
	LISTPICTURE ^ getList();
};

