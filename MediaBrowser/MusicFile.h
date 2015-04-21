#ifndef MUSICFILE_HPP
#define MUSICFILE_HPP

/***************************************************************************
Header     :	MusicFile                                      Version 1.0
****************************************************************************

Function   :	This class implements a MusicFile

Methodes   :	MusicFile()
				~MusicFile()
				getTitle()
				getArtist()
				getAlbumArtist()
				getAlbum()
				getGenre()
				getDuration()
				setTitle()
				setArtist()
				setAlbumArtist()
				setAlbum()
				setGenre()
				setDuration()
				edit()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MusicFile.h

*****************************************************************************/

#pragma once

/* imports					   */
#include "MediaFile.h"

/* namespaces				   */
using namespace System;
using namespace System::Data;

/* Class definition            */
ref class MusicFile : public MediaFile
{
	/* data      */
	public:
		static String ^ const titleKey = "Title";
		static String ^ const artistKey = "Artist";
		static String ^ const albumArtistKey = "Albumartist";
		static String ^ const albumKey = "Album";
		static String ^ const genreKey = "Genre";
		static String ^ const durationKey = "Duration";

	/* methodes      */
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
		void edit();
};

#endif