#pragma once
#include "MediaFile.h"

#include "MusicFile.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

ref class Catalog : public DataTable
{

public:
	generic <typename T>  where T : MediaFile,ref class
		T getFileFromRow(DataGridViewRow ^ currentRow)
	{				
		T newFile = Activator::CreateInstance<T>();
		
		DataRow ^ drow = safe_cast<DataRowView ^>(currentRow->DataBoundItem)->Row;

		//map file with all avaible informations
		for each (DataColumn ^column in drow->Table->Columns)
		{
			newFile->getInformations()[column->ToString()] = drow[column->ToString()]->ToString();
		}

		return newFile;
	}

public:
	Catalog();
	virtual ~Catalog();

	virtual void import();
	virtual void getFile();

	virtual void remove();
	virtual void save();
	virtual void load();

	void add(MediaFile ^ newFile);
	void search(String ^ searchStr);
};

