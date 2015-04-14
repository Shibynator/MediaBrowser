#include "Catalog.h"

#include "PopUpForm.h"

using namespace MediaBrowser;

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
	catch (Exception ^ e)		// catch all
	{
		PopUpForm ^ popWindow = gcnew PopUpForm("Fehler", "Speichern fehlgeschlagen. Eine Exception ist aufgetreten.", "Exception: " + e->Message);
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
	catch (Exception ^ e)		// catch all
	{
		PopUpForm ^ popWindow = gcnew PopUpForm("Fehler", "Laden fehlgeschlagen. Eine Exception ist aufgetreten.", "Exception: " + e->Message);
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
	try
	{
		for each (DataColumn ^ column in Columns)
		{
			filterStr += column->ToString() + " LIKE '%" + searchStr + "%' OR ";
		}
		filterStr = filterStr->Remove(filterStr->Length - 3);	// remove last "OR"
		DefaultView->RowFilter = filterStr;
	}
	catch (Exception ^ e)		// catch all
	{
		// Popup nur nervend, tritt auf wenn katalog leer
		// PopUpForm ^ popWindow = gcnew PopUpForm("Fehler", "Suchen fehlgeschlagen. Eine Exception ist aufgetreten.", "Exception: " + e->Message);
	}
}

void Catalog::remove(DataGridViewRow ^ currentRow)
{
	try
	{
		DataRow ^ drow = safe_cast<DataRowView ^>(currentRow->DataBoundItem)->Row;
		Rows->Remove(drow);
	}
	catch (Exception ^ e)		// catch all
	{
		PopUpForm ^ popWindow = gcnew PopUpForm("Fehler", "Entfernen fehlgeschlagen. Eine Exception ist aufgetreten.", "Exception: " + e->Message);
	}
}
