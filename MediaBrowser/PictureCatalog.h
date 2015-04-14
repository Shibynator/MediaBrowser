#pragma once

#include "Catalog.h"

#include "PictureFile.h"

using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class PictureCatalog : public Catalog
{
private:
	String ^ const endingPictureJPG = "\\*.jpg";
	String ^ const pathSaveFileCatalog = "pictureCatalog.xml";
	String ^ const pathSaveFileSchema = "pictureSchema.xml";

public:
	PictureCatalog(String ^ pathSaveName, String ^ pathSaveSchema);
	virtual ~PictureCatalog();

	virtual void import(String ^ folderPath);

	PictureFile ^ getFile(DataGridViewRow ^ currentRow);
};

