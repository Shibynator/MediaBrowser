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

File       :	MediaFile.cpp

*****************************************************************************/

/* imports					   */
#include "MediaFile.h"
#include "PopUpForm.h"

/* namespaces				   */
using namespace System;
using namespace System::Data;
using namespace MediaBrowser;

/****************************************************************************
Method      :	MediaFile()
Function    :	Constructor for the MediaFile-class
Type        :	Constructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MediaFile::MediaFile()
{
	informations->Add(pathKey, "unbekannt");
	informations->Add(dateCreationKey, "01/01/2015 00:00:01");
	informations->Add(dateModifiedKey, "01/01/2015 00:00:01");

	readonlyinformation->Add(pathKey, true);
	readonlyinformation->Add(dateCreationKey, true);
	readonlyinformation->Add(dateModifiedKey, true);
}

/****************************************************************************
Method      :	~MediaFile()
Function    :	Destructor for the MediaFile-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MediaFile::~MediaFile()
{
}

/****************************************************************************
Method      :	getInformations()
Function    :	returns the informations dictionary
Type        :	global
Input Para  :	none
Output Para :	Dictionary<String^, String^>			the dictionary
Author      :	Matthias Stalder
Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
Dictionary<String^, String^> ^ MediaFile::getInformations()
{
	return informations; 
}

/****************************************************************************
Method      :	getReadonlyinformation()
Function    :	returns the readonly-information dictionary
Type        :	global
Input Para  :	none
Output Para :	Dictionary<String^, bool>			the dictionary
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
Dictionary<String^, bool> ^ MediaFile::getReadonlyinformation()
{ 
	return readonlyinformation; 
}

/****************************************************************************
Method      :	getPath()
Function    :	returns the path to the file in the filesystem
Type        :	global
Input Para  :	none
Output Para :	String				the path to the file
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MediaFile::getPath(){ return informations[MediaFile::pathKey]; }

/****************************************************************************
Method      :	getDateCreation()
Function    :	returns the date when the file was created
Type        :	global
Input Para  :	none
Output Para :	String				date of creation
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MediaFile::getDateCreation()
{ 
	return informations[MediaFile::dateCreationKey];
}

/****************************************************************************
Method      :	getDateModified()
Function    :	returns the date when the file was modified
Type        :	global
Input Para  :	none
Output Para :	String				date modified
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MediaFile::getDateModified()
{ 
	return informations[MediaFile::dateModifiedKey]; 
}

/****************************************************************************
Method      :	setPath()
Function    :	sets the path to the file on the filesystem
Type        :	global
Input Para  :	path			the path to the file
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MediaFile::setPath(String ^path)
{ 
	informations[MediaFile::pathKey] = path; 
}

/****************************************************************************
Method      :	setDateCreation()
Function    :	sets the date of creation attribut
Type        :	global
Input Para  :	dateCreation			date of creation
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MediaFile::setDateCreation(String ^dateCreation)
{ 
	informations[MediaFile::dateCreationKey] = dateCreation; 
}

/****************************************************************************
Method      :	setDateModified()
Function    :	sets the date modified attribut
Type        :	global
Input Para  :	dateModified			date modified
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MediaFile::setDateModified(String ^dateModified)
{ 
	informations[MediaFile::dateModifiedKey] = dateModified; 
}

/****************************************************************************
Method      :	play()
Function    :	plays the selected file (music, movie or picture) 
Type        :	global
Input Para  :	none
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MediaFile::play()
{
	try{ System::Diagnostics::Process::Start(getPath()); }
	catch (Exception ^ e)		// catch all
	{
		PopUpForm ^ popWindow = gcnew PopUpForm("Fehler", "Abspielen fehlgeschlagen. Eine Exception ist aufgetreten.", "Exception: " + e->Message);
	}
}
