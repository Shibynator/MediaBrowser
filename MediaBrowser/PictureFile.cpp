#include "PictureFile.h"

using namespace System;

PictureFile::PictureFile()
{
}

PictureFile::~PictureFile()
{
}

String ^ PictureFile::getTitle(){ return informations[titleKey]; }
String ^ PictureFile::getResolution(){ return informations[resolutionKey]; }
String ^ PictureFile::getFstop(){ return informations[fstopKey]; }
String ^ PictureFile::getExposuretime(){ return informations[exposuretimeKey]; }
String ^ PictureFile::getISO(){ return informations[isoKey]; }

void PictureFile::setTitle(String ^title){ informations[PictureFile::titleKey] = title; }
void PictureFile::setResolution(String ^resolution){ informations[PictureFile::resolutionKey] = resolution; }
void PictureFile::setFstop(String ^fstop){ informations[PictureFile::fstopKey] = fstop; }
void PictureFile::setExposuretime(String ^exposuretime){ informations[PictureFile::exposuretimeKey] = exposuretime; }
void PictureFile::setISO(String ^iso){ informations[PictureFile::isoKey] = iso; }

void PictureFile::play()
{
}

void PictureFile::edit()
{
}