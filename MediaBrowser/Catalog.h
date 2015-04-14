#pragma once
#include "MediaFile.h"

#include "MusicFile.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

ref class Catalog : public DataTable
{
protected:
	String ^ const pathSaveDir = "C:\\MediaBrowserTest";
	String ^ pathSaveFileCatalog;
	String ^ pathSaveFileSchema;

public:
	Catalog(String ^ pathSaveDir, String ^ pathSaveName);
	virtual ~Catalog();

	virtual void import();
	virtual void getFile();

	void save();
	void load();

	void add(MediaFile ^ newFile);
	void search(String ^ searchStr);
	void remove(DataGridViewRow ^ currentRow);
};

