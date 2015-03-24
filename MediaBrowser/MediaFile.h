#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

using namespace System;

ref class MediaFile
{
private:
	String ^ path;
	String ^ datecreation;
	String ^ datemodified;

public:
	MediaFile();
	MediaFile(String ^ pat, String ^ dcre, String ^ dmod);
	virtual ~MediaFile();

	virtual void play();
	virtual void edit();
};

