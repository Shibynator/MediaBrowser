#include "MusicFile.h"

using namespace System;
using namespace System::Data;

MusicFile::MusicFile()
{
	title = "unbekannt";
	artist = "unbekannt";
	albumartist = "unbekannt";
	album = "unbekannt";
	genre = "unbekannt";
	duration = "00:00:00";
}

MusicFile::MusicFile(String ^ tit, String ^ art, String ^ aart, String ^ alb, String ^ gen, String ^ dur)
	: title(tit), artist(art), albumartist(aart), album(alb), genre(gen), duration(dur)
{

}

MusicFile::MusicFile(String ^ pat, String ^ dcre, String ^ dmod, String ^ tit, String ^ art, String ^ aart, String ^ alb, String ^ gen, String ^ dur)
	: MediaFile(pat, dcre, dmod), title(tit), artist(art), albumartist(aart), album(alb), genre(gen), duration(dur)
{
	
}


MusicFile::~MusicFile()
{
}

String ^ MusicFile::getTitle(){ return title; }
String ^ MusicFile::getArtist(){ return artist; }
String ^ MusicFile::getAlbumartist(){ return albumartist; }
String ^ MusicFile::getAlbum(){ return album; }
String ^ MusicFile::getGenre(){ return genre; }
String ^ MusicFile::getDuration(){ return duration; }

void MusicFile::play()
{
}

void MusicFile::edit() 
{
}