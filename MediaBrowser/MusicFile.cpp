#include "MusicFile.h"

using namespace System;

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

MusicFile::MusicFile(String ^ pat, DateTime dcre, DateTime dmod, String ^ tit, String ^ art, String ^ aart, String ^ alb, String ^ gen, String ^ dur)
	: MediaFile(pat, dcre, dmod)
{
	
}


MusicFile::~MusicFile()
{
}

void MusicFile::play()
{
}

void MusicFile::edit() 
{
}