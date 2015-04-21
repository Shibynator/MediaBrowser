#ifndef MOVIEFILE_HPP
#define MOVIEFILE_HPP

/***************************************************************************
Header     :	MovieFile                                      Version 1.0
****************************************************************************

Function   :	This class implements a MovieFile

Methodes   :	MovieFile()
				~MovieFile()
				getTitle()
				getResolution()
				getDuration()
				getFramerate()
				setTitle()
				setResolution()
				setDuration()
				setFramerate()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MovieFile.h

*****************************************************************************/

#pragma once

/* imports					   */
#include "MediaFile.h"

/* namespaces				   */
using namespace System;
using namespace System::Data;

/* Class definition            */
ref class MovieFile : public MediaFile
{
	/* data      */
	public:
		static String ^ const titleKey = "Title";
		static String ^ const resolutionKey = "Resolution";
		static String ^ const durationKey = "Duration";
		static String ^ const framerateKey = "Framerate";

	/* methodes      */
	public:
		MovieFile();
		virtual ~MovieFile();
		String ^ getTitle();
		String ^ getResolution();
		String ^ getDuration();
		String ^ getFramerate();
		void setTitle(String ^title);
		void setResolution(String ^resolution);
		void setDuration(String ^duration);
		void setFramerate(String ^framerate);
};

#endif