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

void Catalog::search()
{
}

void Catalog::sort()
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

void Catalog::Add(MediaFile ^newFile){

	for each (String ^key in newFile->getInformations()->Keys)
	{
		if (!Columns->Contains(key)){
			Columns->Add(key);
		}
	}

	DataRow ^newRow = NewRow();

	for each (String ^key in newFile->getInformations()->Keys)
	{
		newRow[key] = newFile->getInformations()[key];
	}

	Rows->Add(newRow);
}
