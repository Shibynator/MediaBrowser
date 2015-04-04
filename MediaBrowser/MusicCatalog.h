#pragma once

#include "Catalog.h"
#include "MusicCatalog.h"
#include "MusicFile.h"

using namespace System::Collections::Generic;

ref class MusicCatalog : public Catalog
{
private:
	String ^ const endingMusicMP3 = "\\*.mp3";

public:
	MusicCatalog();
	virtual ~MusicCatalog();

	virtual void import(String ^ folderPath);

	virtual void search() override;
	virtual void sort() override;
	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;

};

