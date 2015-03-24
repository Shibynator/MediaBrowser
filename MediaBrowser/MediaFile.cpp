#include "MediaFile.h"

using namespace System;

MediaFile::MediaFile()
{
	path = "unbekannt";
	datecreation.Parse("01/01/2015 00:00:01");		
	datemodified.Parse("01/01/2015 00:00:01");		
}

MediaFile::MediaFile(String ^ pat, DateTime dcre, DateTime dmod)
	: path(pat), datecreation(dcre), datemodified(dmod)
{
}

MediaFile::~MediaFile()
{
}

void MediaFile::play()
{

}

void MediaFile::edit()
{

}