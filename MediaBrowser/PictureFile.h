#pragma once

#include "MediaFile.h"

using namespace System;

ref class PictureFile : public MediaFile
{
protected:
	static String ^ titleKey = "Title";
	static String ^ resolutionKey = "Resolution";
	static String ^ fstopKey = "Fstop";
	static String ^ exposuretimeKey = "Exposuretime";
	static String ^ isoKey = "ISO";

public:
	PictureFile();
	virtual ~PictureFile();

	String ^ getTitle();
	String ^ getResolution();
	String ^ getFstop();
	String ^ getExposuretime();
	String ^ getISO();

	void setTitle(String ^title);
	void setResolution(String ^resolution);
	void setFstop(String ^fstop);
	void setExposuretime(String ^exposuretime);
	void setISO(String ^iso);

	virtual void play() override;
	virtual void edit() override;
};

