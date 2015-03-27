#include "MediaFile.h"

using namespace System;
using namespace System::Data;

MediaFile::MediaFile()
{
	path = "unbekannt";
	datecreation = "01/01/2015 00:00:01";
	datemodified = "01/01/2015 00:00:01";
}

MediaFile::MediaFile(String ^ pat, String ^ dcre, String ^ dmod)
	: path(pat), datecreation(dcre), datemodified(dmod)
{
}

MediaFile::~MediaFile()
{
}

String ^ MediaFile::getPath(){	return path; }
String ^ MediaFile::getDateCreation(){ return datecreation; }
String ^ MediaFile::getDateModified(){ return datemodified; }

void MediaFile::play()
{

}

void MediaFile::edit()
{

}