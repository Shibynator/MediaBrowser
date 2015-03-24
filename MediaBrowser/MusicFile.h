#pragma once

#include "MediaFile.h"

using namespace System;

ref class MusicFile : public MediaFile
{
private:
	String ^ title;
	String ^ artist;
	String ^ albumartist;
	String ^ album;
	String ^ genre;
	String ^ duration;

public:
	MusicFile();
	MusicFile(String ^ tit, String ^ art, String ^ aart, String ^ alb, String ^ gen, String ^ dur);
	MusicFile(String ^ pat, String ^ dcre, String ^ dmod, String ^ tit, String ^ art, String ^ aart, String ^ alb, String ^ gen, String ^ dur);
	virtual ~MusicFile();

	virtual void play() override;
	virtual void edit() override;
};

