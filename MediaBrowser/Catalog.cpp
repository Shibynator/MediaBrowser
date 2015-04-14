#include "Catalog.h"


Catalog::Catalog()
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

void Catalog::remove()
{
}
void Catalog::save()
{
}
void Catalog::load()
{
}

void Catalog::add(MediaFile ^newFile)
{

	//add Columns for new Keys
	for each (String ^key in newFile->getInformations()->Keys)
	{
		if (!Columns->Contains(key)){
			Columns->Add(key);
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

