#ifndef PICTUREFILE_HPP
#define PICTUREFILE_HPP

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

File       :	PictureFile.h

*****************************************************************************/

#pragma once

/* imports					   */
#include "MediaFile.h"
#include <FreeImage.h>

/* namespaces				   */
using namespace System;

/* Class definition            */
ref class PictureFile : public MediaFile
{
	/* data      */
	public:

	/* methodes      */
	public:
		PictureFile();
		virtual ~PictureFile();
		void mapInformations(String ^path,FREE_IMAGE_MDMODEL informationModel); 
};

#endif