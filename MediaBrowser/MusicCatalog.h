#pragma once

#include "Catalog.h"

#include "MusicFile.h"

using namespace System::Collections::Generic;

typedef List<MusicFile ^> LISTMUSIC;

ref class MusicCatalog : public Catalog
{
private:
	LISTMUSIC musicList;

public:
	MusicCatalog();
	virtual ~MusicCatalog();

	virtual void import() override;
	virtual void search() override;
	virtual void sort() override;
	virtual void remove() override;
	virtual void save() override;
	virtual void load() override;

	void add(MusicFile ^ musicFile);
};

