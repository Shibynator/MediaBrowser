#include "MusicCatalog.h"


MusicCatalog::MusicCatalog()
{
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
	musicList->Add(musicFile);
}

LISTMUSIC ^ MusicCatalog::getList()
{
	return musicList;
}