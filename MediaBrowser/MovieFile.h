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
	virtual ~MovieFile();

	virtual void play() override;
	virtual void edit() override;
};

