#include "MediaFile.h"

using namespace System;
using namespace System::Data;

MediaFile::MediaFile()
{
	informations->Add(pathKey, "unbekannt");
	informations->Add(dateCreationKey, "01/01/2015 00:00:01");
	informations->Add(dateModifiedKey, "01/01/2015 00:00:01");
}

MediaFile::~MediaFile()
{
}

Dictionary<String^, String^> ^ MediaFile::getInformations(){ return informations; }
String ^ MediaFile::getPath(){ return informations[MediaFile::pathKey]; }
String ^ MediaFile::getDateCreation(){ return informations[MediaFile::dateCreationKey]; }
String ^ MediaFile::getDateModified(){ return informations[MediaFile::dateModifiedKey]; }

void MediaFile::setPath(String ^path){ informations[MediaFile::pathKey] = path; }
void MediaFile::setDateCreation(String ^dateCreation){ informations[MediaFile::dateCreationKey] = dateCreation; }
void MediaFile::setDateModified(String ^dateModified){ informations[MediaFile::dateModifiedKey] = dateModified; }

void MediaFile::play()
{
}

void MediaFile::edit()
{
}