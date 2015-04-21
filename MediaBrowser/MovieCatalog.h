#ifndef MOVIECATALOG_HPP
#define MOVIECATALOG_HPP

/***************************************************************************
Header     :	MovieCatalog                                    Version 1.0
****************************************************************************

Function   :	This class implements a moviecatalog. it derived from the
				abstract baseclass catalog.

Methodes   :	MovieCatalog()
				~MovieCatalog()
				import()
				getFile()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MovieCatalog.h

*****************************************************************************/

#pragma once

/* imports					   */
#include "Catalog.h"
#include "MovieFile.h"

/* namespaces				   */
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

/* Class definition            */
ref class MovieCatalog : public Catalog
{
	/* data      */
	private:
		String ^ const endingMovieMP4 = "\\*.mp4";
		String ^ const pathSaveFileCatalog = "movieCatalog.xml";
		String ^ const pathSaveFileSchema = "movieSchema.xml";

	/* methodes      */
	public:
		MovieCatalog(String ^ pathSaveName, String ^ pathSaveSchema);
		virtual ~MovieCatalog();
		virtual void import(String ^ folderPath) override;
		MovieFile ^ getFile(DataGridViewRow ^ currentRow);
};

#endif