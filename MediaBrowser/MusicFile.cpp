#include "MusicFile.h"
#include "MediaInfoDLL.h"
#include <id3/tag.h>
#include <id3/misc_support.h>

using namespace System;
using namespace System::Data;

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

MusicFile::~MusicFile()
{
}

String ^ MusicFile::getTitle(){ return informations[titleKey]; }
String ^ MusicFile::getArtist(){ return informations[artistKey]; }
String ^ MusicFile::getAlbumArtist(){ return informations[albumArtistKey]; }
String ^ MusicFile::getAlbum(){ return informations[albumKey]; }
String ^ MusicFile::getGenre(){ return informations[genreKey]; }
String ^ MusicFile::getDuration(){ return informations[durationKey]; }

void MusicFile::setTitle(String ^title){ informations[MusicFile::titleKey] = title; }
void MusicFile::setArtist(String ^artist){ informations[MusicFile::artistKey] = artist; }
void MusicFile::setAlbumArtist(String ^albumArtist){ informations[MusicFile::albumArtistKey] = albumArtist; }
void MusicFile::setAlbum(String ^album){ informations[MusicFile::albumKey] = album; }
void MusicFile::setGenre(String ^genre){ informations[MusicFile::genreKey] = genre; }
void MusicFile::setDuration(String ^duration){ informations[MusicFile::durationKey] = duration; }

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