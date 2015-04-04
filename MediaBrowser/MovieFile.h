#pragma once

#include "MediaFile.h"

using namespace System;
using namespace System::Data;

ref class MovieFile : public MediaFile
{
protected:
	static String ^ titleKey = "Title";
	static String ^ resolutionKey = "Resolution";
	static String ^ durationKey = "Duration";
	static String ^ framerateKey = "Framerate";

public:
	MovieFile();
	virtual ~MovieFile();

	String ^ getTitle();
	String ^ getResolution();
	String ^ getDuration();
	String ^ getFramerate();

	void setTitle(String ^title);
	void setResolution(String ^resolution);
	void setDuration(String ^duration);
	void setFramerate(String ^framerate);

	virtual void play() override;
	virtual void edit() override;
};

