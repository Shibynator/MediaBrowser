#ifndef PICTURECATALOG_HPP
#define PICTURECATALOG_HPP

/***************************************************************************
Header     :	PictureCatalog                                    Version 1.0
****************************************************************************

Function   :	This class implements a picturecatalog. it derived from the
				abstract baseclass catalog.

Methodes   :	PictureCatalog()
				~PictureCatalog()
				import()
				getFile()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	PictureCatalog.h

*****************************************************************************/

#pragma once

/* imports					   */
#include "Catalog.h"
#include "PictureFile.h"

/* namespaces				   */
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

/* Class definition            */
ref class PictureCatalog : public Catalog
{
	/* data      */
	private:
		String ^ const endingPictureJPG = "\\*.jpg";
		String ^ const pathSaveFileCatalog = "pictureCatalog.xml";
		String ^ const pathSaveFileSchema = "pictureSchema.xml";

	/* methodes      */
	public:
		PictureCatalog(String ^ pathSaveName, String ^ pathSaveSchema);
		virtual ~PictureCatalog();
		virtual void import(String ^ folderPath) override;
		PictureFile ^ getFile(DataGridViewRow ^ currentRow);
};

#endif