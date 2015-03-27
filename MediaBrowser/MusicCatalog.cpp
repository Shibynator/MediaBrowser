#include "MusicCatalog.h"


MusicCatalog::MusicCatalog()
{
	this->Columns->Add("Title");
	this->Columns->Add("Artit");
	this->Columns->Add("Albumartist");
	this->Columns->Add("Album");
	this->Columns->Add("Genre");
	this->Columns->Add("Dauer");
	this->Columns->Add("Zuletzt geändert");
	this->Columns->Add("Erstellt am");
	this->Columns->Add("Pfad");
}


MusicCatalog::~MusicCatalog()
{
}

void MusicCatalog::import()
{
}

void MusicCatalog::search()
{
}

void MusicCatalog::sort()
{
}

void MusicCatalog::remove()
{
}

void MusicCatalog::save()
{
}

void MusicCatalog::load()
{
}

void MusicCatalog::add(MusicFile ^ musicFile)
{
	this->Rows->Add(musicFile->getTitle(), musicFile->getArtist(), musicFile->getAlbumartist(), musicFile->getAlbum(), musicFile->getGenre(), musicFile->getDuration(), 
		musicFile->getDateModified(), musicFile->getDateCreation(), musicFile->getPath());
}
