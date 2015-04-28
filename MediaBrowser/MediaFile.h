#ifndef MEDIAFILE_HPP
#define MEDIAFILE_HPP

/***************************************************************************
Header     :	MediaFile                                      Version 1.0
****************************************************************************

Function   :	This class implements a generic MediaFile

Methodes   :	MediaFile()
				~MediaFile()
				getInformations()
				getReadonlyinformation()
				getPath()
				getDateCreation()
				getDateModified()
				setPath()
				setDateCreation()
				setDateModified()
				play()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MediaFile.h

*****************************************************************************/

#pragma once

/* imports					   */
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

/* namespaces				   */
using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;

/* Class definition            */
ref class MediaFile
{
	/* data      */
	protected:
		Dictionary<String^, String^> ^informations = gcnew Dictionary<String^, String^>();
		Dictionary<String^, bool> ^readonlyinformation = gcnew Dictionary<String^, bool>();

	public:
		static String ^ const pathKey = "Path";
		static String ^ const dateCreationKey = "DateCreated";
		static String ^ const dateModifiedKey = "DateModified";

	/* methodes      */
	public:
		MediaFile();
		virtual ~MediaFile();
		Dictionary<String^, String^> ^getInformations();
		Dictionary<String^, bool> ^getReadonlyinformation();
		String ^getPath();
		String ^getDateCreation();
		String ^getDateModified();
		void setPath(String ^path);
		void setDateCreation(String ^dateCreation);
		void setDateModified(String ^dateModified);
		void play();
};

#endif
