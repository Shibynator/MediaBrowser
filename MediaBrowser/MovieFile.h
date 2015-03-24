#pragma once

#include "MediaFile.h"

using namespace System;

ref class MovieFile : public MediaFile
{
private:
	String ^ title;
	String ^ resolution;
	String ^ duration;
	String ^ framerate;

public:
	MovieFile();
	MovieFile(String ^ tit, String ^ res, String ^ dur, String ^ frm);
	MovieFile(String ^ pat, String ^ dcre, String ^ dmod, String ^ tit, String ^ res, String ^ dur, String ^ frm);
	virtual ~MovieFile();

	virtual void play() override;
	virtual void edit() override;
};

