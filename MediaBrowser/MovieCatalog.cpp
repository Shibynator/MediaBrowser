#include "MovieCatalog.h"

MovieCatalog::MovieCatalog()
{
}

MovieCatalog::~MovieCatalog()
{
}

void MovieCatalog::import()
{
}

void MovieCatalog::search()
{
}

void MovieCatalog::sort()
{
}

void MovieCatalog::remove()
{
}

void MovieCatalog::save()
{
}

void MovieCatalog::load()
{
}

void MovieCatalog::add(MovieFile ^ movieFile)
{
	movieList->Add(movieFile);
}

LISTMOVIE ^ MovieCatalog::getList()
{
	return movieList;
}