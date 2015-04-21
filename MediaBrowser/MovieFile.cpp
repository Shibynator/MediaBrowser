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

File       :	MovieFile.cpp

*****************************************************************************/

/* imports					   */
#include "MovieFile.h"

/* namespaces				   */
using namespace System;

/****************************************************************************
Method      :	MovieFile()
Function    :	Constructor for the MovieFile-class
Type        :	Constructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MovieFile::MovieFile()
{
	informations->Add(titleKey, "unbekannt");
	informations->Add(resolutionKey, "unbekannt");
	informations->Add(durationKey, "00:00:00");
	informations->Add(framerateKey, "unbekannt");

	// config which tags should be editable 
	readonlyinformation->Add(titleKey, true);
	readonlyinformation->Add(resolutionKey, true);
	readonlyinformation->Add(durationKey, true);
	readonlyinformation->Add(framerateKey, true);
}

/****************************************************************************
Method      :	~MovieFile()
Function    :	Destructor for the MovieFile-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MovieFile::~MovieFile()
{
}

/****************************************************************************
Method      :	getTitle()
Function    :	returns the title
Type        :	global
Input Para  :	none
Output Para :	String			the title as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MovieFile::getTitle()
{ 
	return informations[titleKey]; 
}

/****************************************************************************
Method      :	getResolution()
Function    :	returns the resolution
Type        :	global
Input Para  :	none
Output Para :	String			the resolution as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MovieFile::getResolution()
{ 
	return informations[resolutionKey]; 
}

/****************************************************************************
Method      :	getDuration()
Function    :	returns the duration
Type        :	global
Input Para  :	none
Output Para :	String			the duration as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MovieFile::getDuration()
{ 
	return informations[durationKey]; 
}

/****************************************************************************
Method      :	getFramerate()
Function    :	returns the framerate
Type        :	global
Input Para  :	none
Output Para :	String			the framerate as a string
Author      :	Matthias Stalder
Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MovieFile::getFramerate()
{ 
	return informations[framerateKey]; 
}

/****************************************************************************
Method      :	setTitle()
Function    :	sets a new title
Type        :	global
Input Para  :	title		the new title as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MovieFile::setTitle(String ^title)
{ 
	informations[MovieFile::titleKey] = title; 
}

/****************************************************************************
Method      :	setResolution()
Function    :	sets a new resolution
Type        :	global
Input Para  :	resolution		the new resolution as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MovieFile::setResolution(String ^resolution)
{ 
	informations[MovieFile::resolutionKey] = resolution; 
}

/****************************************************************************
Method      :	setDuration()
Function    :	sets a new duration
Type        :	global
Input Para  :	duration		the new duration as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MovieFile::setDuration(String ^duration)
{ 
	informations[MovieFile::durationKey] = duration; 
}

/****************************************************************************
Method      :	setFramerate()
Function    :	sets a new framerate
Type        :	global
Input Para  :	framerate		the new framerate as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MovieFile::setFramerate(String ^framerate)
{ 
	informations[MovieFile::framerateKey] = framerate; 
}