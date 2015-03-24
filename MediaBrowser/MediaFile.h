#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

using namespace System;

ref class MediaFile
{
private:
	String ^ path;
	DateTime datecreation;
	DateTime datemodified;

public:
	MediaFile();
	MediaFile(String ^ pat, DateTime dcre, DateTime dmod);
	virtual ~MediaFile();

	virtual void play();
	virtual void edit();
};

