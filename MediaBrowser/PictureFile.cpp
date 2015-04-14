#include "PictureFile.h"

using namespace System;

PictureFile::PictureFile()
{
	// todo fil dictonary

	// config which tags should be editable 
	readonlyinformation->Add(titleKey, true);
	readonlyinformation->Add(resolutionKey, true);
	readonlyinformation->Add(fstopKey, true);
	readonlyinformation->Add(exposuretimeKey, true);
	readonlyinformation->Add(isoKey, true);
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
