#include "PictureFile.h"
#include <vcclr.h>

using namespace Runtime::InteropServices;
using namespace System;

PictureFile::PictureFile()
{
	// TODO: fil dictonary

	// config which tags should be editable 
	/*
	readonlyinformation->Add(titleKey, true);
	readonlyinformation->Add(resolutionKey, true);
	readonlyinformation->Add(fstopKey, true);
	readonlyinformation->Add(exposuretimeKey, true);
	readonlyinformation->Add(isoKey, true); */
}

PictureFile::~PictureFile()
{
}
/*
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
*/
void PictureFile::mapInformations(String ^path, FREE_IMAGE_MDMODEL informationModel)
{
	FITAG *tag = NULL;
	FIMETADATA *mdhandle = NULL;

	//convert managed String to const char for calling FreeImage_Load()
	const char* pathConverted = (const char*)(Marshal::StringToHGlobalAnsi(path)).ToPointer();	
	FIBITMAP *picture = FreeImage_Load(FIF_JPEG, pathConverted, JPEG_DEFAULT);

	mdhandle = FreeImage_FindFirstMetadata(informationModel, picture, &tag);
	
	if (mdhandle) {
		do {
			// process the tag
			const char *tagKey = FreeImage_GetTagKey(tag);
			const char *tagValue = FreeImage_TagToString(informationModel, tag);

			informations->Add(gcnew String(tagKey), gcnew String(tagValue));

		} while (FreeImage_FindNextMetadata(mdhandle, &tag));

		FreeImage_FindCloseMetadata(mdhandle);
	}
}
