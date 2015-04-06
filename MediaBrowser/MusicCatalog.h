#pragma once

#include "Catalog.h"
#include "MusicCatalog.h"
#include "MusicFile.h"

using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

ref class MusicCatalog : public Catalog
{
private:
	String ^ const endingMusicMP3 = "\\*.mp3";

public:
	MusicCatalog();
	virtual ~MusicCatalog();

	virtual void import(String ^ folderPath);
	virtual MusicFile ^ getFile(DataGridViewRow ^ currentRow);

	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;
};

