#include "PictureCatalog.h"


PictureCatalog::PictureCatalog()
{
}

PictureCatalog::~PictureCatalog()
{
}

void PictureCatalog::import()
{
}

void PictureCatalog::search()
{
}

void PictureCatalog::sort()
{
}

void PictureCatalog::remove()
{
}

void PictureCatalog::save()
{
}

void PictureCatalog::load()
{
}

void PictureCatalog::add(PictureFile ^ pictureFile)
{
	pictureList->Add(pictureFile);
}

LISTPICTURE ^ PictureCatalog::getList()
{
	return pictureList;
}