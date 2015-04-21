/***************************************************************************
Header     :	MusicFile                                      Version 1.0
****************************************************************************

Function   :	This class implements a MusicFile

Methodes   :	MusicFile()
				~MusicFile()
				getTitle()
				getArtist()
				getAlbumArtist()
				getAlbum()
				getGenre()
				getDuration()
				setTitle()
				setArtist()
				setAlbumArtist()
				setAlbum()
				setGenre()
				setDuration()
				edit()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MusicFile.cpp

*****************************************************************************/

/* imports					   */
#include "MusicFile.h"
#include "MediaInfoDLL.h"
#include <id3/tag.h>
#include <id3/misc_support.h>

/* namespaces				   */
using namespace System;
using namespace System::Data;

/****************************************************************************
Method      :	MusicFile()
Function    :	Constructor for the MusicFile-class
Type        :	Constructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MusicFile::MusicFile()
{
	informations->Add(titleKey, "unbekannt");
	informations->Add(artistKey, "unbekannt");
	informations->Add(albumArtistKey, "unbekannt");
	informations->Add(albumKey, "unbekannt");
	informations->Add(genreKey, "unbekannt");
	informations->Add(durationKey, "00:00:00");

	// config which tags should be editable 
	readonlyinformation->Add(titleKey, false);
	readonlyinformation->Add(artistKey, false);
	readonlyinformation->Add(albumArtistKey, false);
	readonlyinformation->Add(albumKey, false);
	readonlyinformation->Add(genreKey, false);
	readonlyinformation->Add(durationKey, true);
}

/****************************************************************************
Method      :	~MusicFile()
Function    :	Destructor for the MusicFile-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MusicFile::~MusicFile()
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
String ^ MusicFile::getTitle()
{ 
	return informations[titleKey]; 
}

/****************************************************************************
Method      :	getArtist()
Function    :	returns the artist
Type        :	global
Input Para  :	none
Output Para :	String			the artist as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MusicFile::getArtist()
{ 
	return informations[artistKey]; 
}

/****************************************************************************
Method      :	getAlbumArtist()
Function    :	returns the albumartist
Type        :	global
Input Para  :	none
Output Para :	String			the albumartist as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MusicFile::getAlbumArtist()
{ 
	return informations[albumArtistKey]; 
}

/****************************************************************************
Method      :	getAlbum()
Function    :	returns the album
Type        :	global
Input Para  :	none
Output Para :	String			the album as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MusicFile::getAlbum()
{ 
	return informations[albumKey]; 
}

/****************************************************************************
Method      :	getGenre()
Function    :	returns the genre
Type        :	global
Input Para  :	none
Output Para :	String			the genre as a string
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
String ^ MusicFile::getGenre()
{ 
	return informations[genreKey]; 
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
String ^ MusicFile::getDuration()
{ 
	return informations[durationKey]; 
}

/****************************************************************************
Method      :	setTitle()
Function    :	sets a new title
Type        :	global
Input Para  :	title			the new title as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::setTitle(String ^title)
{ 
	informations[MusicFile::titleKey] = title; 
}

/****************************************************************************
Method      :	setArtist()
Function    :	sets a new artist
Type        :	global
Input Para  :	artist			the new artist as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::setArtist(String ^artist)
{ 
	informations[MusicFile::artistKey] = artist; 
}

/****************************************************************************
Method      :	setAlbumArtist()
Function    :	sets a new albumartist
Type        :	global
Input Para  :	albumArtist			the new albumartist as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::setAlbumArtist(String ^albumArtist)
{ 
	informations[MusicFile::albumArtistKey] = albumArtist; 
}

/****************************************************************************
Method      :	setAlbum()
Function    :	sets a new album
Type        :	global
Input Para  :	album			the new album as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::setAlbum(String ^album)
{ 
	informations[MusicFile::albumKey] = album; 
}

/****************************************************************************
Method      :	setGenre()
Function    :	sets a new genre
Type        :	global
Input Para  :	genre			the new genre as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::setGenre(String ^genre)
{ 
	informations[MusicFile::genreKey] = genre; 
}

/****************************************************************************
Method      :	setDuration()
Function    :	sets a new duration
Type        :	global
Input Para  :	duration			the new duration as a string
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::setDuration(String ^duration)
{ 
	informations[MusicFile::durationKey] = duration; 
}

/****************************************************************************
Method      :	edit()
Function    :	writes the new id3 tags to the file
Type        :	global
Input Para  :	none
Output Para :	none
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void MusicFile::edit() 
{
	// geht noch nicht
	const char * filename = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->getPath()).ToPointer());

	ID3_Tag myTag;
	ID3_Frame * myFrame;
	myTag.Link(filename);

	// Titel
	do
	{
		myFrame = myTag.Find(ID3FID_TITLE);		// alle bestehende tags löschen
		if (NULL != myFrame)
		{
			myTag.RemoveFrame(myFrame);
		}
	} while (NULL != myFrame);
	myFrame = new ID3_Frame();
	myFrame->SetID(ID3FID_TITLE);
	char * fieldTitle = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->getTitle()).ToPointer());
	myFrame->Field(ID3FN_TEXT).Set(fieldTitle);
	myTag.AddFrame(myFrame);
	delete myFrame;

	// Artist
	do
	{
		myFrame = myTag.Find(ID3FID_LEADARTIST);		// alle bestehende tags löschen
		if (NULL != myFrame)
		{
			myTag.RemoveFrame(myFrame);
		}
	} while (NULL != myFrame);
	myFrame = new ID3_Frame();
	myFrame->SetID(ID3FID_LEADARTIST);
	char * fieldArtist = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->getArtist()).ToPointer());
	myFrame->Field(ID3FN_TEXT).Set(fieldArtist);
	myTag.AddFrame(myFrame);
	delete myFrame;

	// Albumartist
	do
	{
		myFrame = myTag.Find(ID3FID_BAND);		// alle bestehende tags löschen
		if (NULL != myFrame)
		{
			myTag.RemoveFrame(myFrame);
		}
	} while (NULL != myFrame);
	myFrame = new ID3_Frame();
	myFrame->SetID(ID3FID_BAND);
	char * fieldAlbumartist = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->getAlbumArtist()).ToPointer());
	myFrame->Field(ID3FN_TEXT).Set(fieldAlbumartist);
	myTag.AddFrame(myFrame);
	delete myFrame;

	// Album
	do
	{
		myFrame = myTag.Find(ID3FID_ALBUM);		// alle bestehende tags löschen
		if (NULL != myFrame)
		{
			myTag.RemoveFrame(myFrame);
		}
	}while (NULL != myFrame);
	myFrame = new ID3_Frame();
	myFrame->SetID(ID3FID_ALBUM);
	char * fieldAlbum = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->getAlbum()).ToPointer());
	myFrame->Field(ID3FN_TEXT).Set(fieldAlbum);
	myTag.AddFrame(myFrame);
	delete myFrame;
	
	// Genre
	char * fieldGenre = (char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->getGenre()).ToPointer());
	ID3_AddGenre(&myTag, fieldGenre, true);

	myTag.SetPadding(false);
	myTag.SetUnsync(true);

	myTag.Update();
}