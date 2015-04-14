#include "Catalog.h"


Catalog::Catalog(String ^ pathSaveName, String ^ pathSaveSchema)
	: pathSaveFileCatalog(pathSaveName), pathSaveFileSchema(pathSaveSchema)
{

}

Catalog::~Catalog()
{
}

void Catalog::import()
{
}

void Catalog::getFile()
{
}

void Catalog::save()
{
	// chech if directory exists, otherwise create it
	if (!CreateDirectory((wchar_t*)Runtime::InteropServices::Marshal::StringToHGlobalUni(pathSaveDir).ToPointer(), NULL))
	{
		// Directory is already exist!
	}
	try
{
		WriteXmlSchema(pathSaveDir + "\\" + pathSaveFileSchema);	// save schema
		WriteXml(pathSaveDir + "\\" + pathSaveFileCatalog);			// Save catalog
}
	catch (...)		// catch all
{
		// error
	}
}

void Catalog::load()
{
	try
	{
		Clear();		// clear datatable (data and schema as well)
		ReadXmlSchema(pathSaveDir + "\\" + pathSaveFileSchema);	// save schema
		ReadXml(pathSaveDir + "\\" + pathSaveFileCatalog);	// save data
}
	catch (...)	// catch all
	{
		// error
	}
}

void Catalog::add(MediaFile ^newFile)
{
	//add Columns for new Keys
	for each (String ^key in newFile->getInformations()->Keys)
	{
		if (!Columns->Contains(key))
		{
			Columns->Add(key);
			Columns[key]->ReadOnly = newFile->getReadonlyinformation()[key];
		}
	}

	DataRow ^newRow = NewRow();

	//Store Informations to the Destination-Column
	for each (String ^key in newFile->getInformations()->Keys)
	{
		newRow[key] = newFile->getInformations()[key];
	}

	Rows->Add(newRow);
}

void Catalog::search(String ^ searchStr)
{
	String ^ filterStr;

	for each (DataColumn ^ column in Columns)
	{
		filterStr += column->ToString() + " LIKE '%" + searchStr + "%' OR ";
	}
	filterStr = filterStr->Remove(filterStr->Length - 3);	// remove last "OR"
	DefaultView->RowFilter = filterStr;
}

void Catalog::remove(DataGridViewRow ^ currentRow)
{
	try
	{
		DataRow ^ drow = safe_cast<DataRowView ^>(currentRow->DataBoundItem)->Row;
		Rows->Remove(drow);
	}
	catch (...)
	{
	}
}
