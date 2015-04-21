#ifndef MUSICCATALOG_HPP
#define MUSICCATALOG_HPP

/***************************************************************************
Header     :	MusicCatalog                                    Version 1.0
****************************************************************************

Function   :	This class implements a musiccatalog. it derived from the
				abstract baseclass catalog.

Methodes   :	MusicCatalog()
				~MusicCatalog()
				import()
				getFile()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MusicCatalog.h

*****************************************************************************/

#pragma once

/* imports					   */
#include "Catalog.h"
#include "MusicCatalog.h"
#include "MusicFile.h"

/* namespaces				   */
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

/* Class definition            */
ref class MusicCatalog : public Catalog
{
	/* data      */
	private:
		String ^ const endingMusicMP3 = "\\*.mp3";

	/* methodes      */
	public:
		MusicCatalog(String ^ pathSaveName, String ^ pathSaveSchema);
		virtual ~MusicCatalog();
		virtual void import(String ^ folderPath) override;
		MusicFile ^ getFile(DataGridViewRow ^ currentRow);
};

#endif