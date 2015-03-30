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
	virtual ~PictureFile();

	virtual void play() override;
	virtual void edit() override;
};

