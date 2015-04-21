/***************************************************************************
Header     :	PictureFile                                      Version 1.0
****************************************************************************

Function   :	This class implements a PictureFile

Methodes   :	PictureFile()
				~PictureFile()
				mapInformations()

Author     :	Matthias Stalder
Daniel Ziörjen

History    :	21.04.2015

File       :	PictureFile.cpp

*****************************************************************************/

/* imports					   */
#include "PictureFile.h"
#include <vcclr.h>

/* namespaces				   */
using namespace Runtime::InteropServices;
using namespace System;

/****************************************************************************
Method      :	PictureFile()
Function    :	Constructor for the PictureFile-class
Type        :	Constructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
PictureFile::PictureFile()
{
}

/****************************************************************************
Method      :	~PictureFile()
Function    :	Destructor for the PictureFile-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
PictureFile::~PictureFile()
{
}

/****************************************************************************
Method      :	getTitle()
Function    :	returns the title
Type        :	global
Input Para  :	path				path to the picturefile on the filesystem
				informationModel	type of data to be read
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void PictureFile::mapInformations(String ^path, FREE_IMAGE_MDMODEL informationModel)
{
	FITAG *tag = NULL;
	FIMETADATA *mdhandle = NULL;

	//convert managed String to const char for calling FreeImage_Load()
	const char* pathConverted = (const char*)(Marshal::StringToHGlobalAnsi(path)).ToPointer();	
	FIBITMAP *picture = FreeImage_Load(FIF_JPEG, pathConverted, JPEG_DEFAULT);

	mdhandle = FreeImage_FindFirstMetadata(informationModel, picture, &tag);
	
	if (mdhandle) {
		do {
			// process the tag
			const char *tagKey = FreeImage_GetTagKey(tag);
			const char *tagValue = FreeImage_TagToString(informationModel, tag);

			informations->Add(gcnew String(tagKey), gcnew String(tagValue));

		} while (FreeImage_FindNextMetadata(mdhandle, &tag));

		FreeImage_FindCloseMetadata(mdhandle);
	}
}
