#pragma once

#include "Catalog.h"

#include "MusicFile.h"

using namespace System::Collections::Generic;

ref class MusicCatalog : public Catalog
{
	
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

