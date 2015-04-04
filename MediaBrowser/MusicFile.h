#pragma once

#include "MediaFile.h"

using namespace System;
using namespace System::Data;

ref class MusicFile : public MediaFile
{
protected:
	static String ^ titleKey = "Title";
	static String ^ artistKey = "Artist";
	static String ^ albumArtistKey = "Albumartist";
	static String ^ albumKey = "Album";
	static String ^ genreKey = "Genre";
	static String ^ durationKey = "Duration";

public:
	MusicFile();
	virtual ~MusicFile();

	String ^ getTitle();
	String ^ getArtist();
	String ^ getAlbumArtist();
	String ^ getAlbum();
	String ^ getGenre();
	String ^ getDuration();

	void setTitle(String ^title);
	void setArtist(String ^artist);
	void setAlbumArtist(String ^albumArtist);
	void setAlbum(String ^album);
	void setGenre(String ^genre);
	void setDuration(String ^duration);

	virtual void play() override;
	virtual void edit() override;
};

