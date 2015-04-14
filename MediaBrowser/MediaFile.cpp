#include "MediaFile.h"

using namespace System;
using namespace System::Data;

MediaFile::MediaFile()
{
	informations->Add(pathKey, "unbekannt");
	informations->Add(dateCreationKey, "01/01/2015 00:00:01");
	informations->Add(dateModifiedKey, "01/01/2015 00:00:01");

	readonlyinformation->Add(pathKey, true);
	readonlyinformation->Add(dateCreationKey, true);
	readonlyinformation->Add(dateModifiedKey, true);
}

MediaFile::~MediaFile()
{
}

Dictionary<String^, String^> ^ MediaFile::getInformations(){ return informations; }
Dictionary<String^, bool> ^ MediaFile::getReadonlyinformation(){ return readonlyinformation; }
String ^ MediaFile::getPath(){ return informations[MediaFile::pathKey]; }
String ^ MediaFile::getDateCreation(){ return informations[MediaFile::dateCreationKey]; }
String ^ MediaFile::getDateModified(){ return informations[MediaFile::dateModifiedKey]; }

void MediaFile::setPath(String ^path){ informations[MediaFile::pathKey] = path; }
void MediaFile::setDateCreation(String ^dateCreation){ informations[MediaFile::dateCreationKey] = dateCreation; }
void MediaFile::setDateModified(String ^dateModified){ informations[MediaFile::dateModifiedKey] = dateModified; }

void MediaFile::play()
{
	try{ System::Diagnostics::Process::Start(getPath()); }
	catch(...)		// catch all
	{
		// exception
	}
}
