#pragma once

#include "MediaFile.h"

using namespace System;

ref class PictureFile : public MediaFile
{
private:
	String ^ title;
	String ^ resolution;
	String ^ fstop;
	String ^ exposuretime;
	String ^ iso;

public:
	PictureFile();
	PictureFile(String ^ tit, String ^ res, String ^ fst, String ^ exp, String ^ is);
	PictureFile(String ^ pat, DateTime dcre, DateTime dmod, String ^ tit, String ^ res, String ^ fst, String ^ exp, String ^ is);
	virtual ~PictureFile();

	virtual void play() override;
	virtual void edit() override;
};

