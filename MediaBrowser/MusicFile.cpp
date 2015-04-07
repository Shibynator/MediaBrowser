#include "MusicFile.h"

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
}