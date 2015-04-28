/***************************************************************************
Header     :	Catalog                                      Version 1.0
****************************************************************************

Function   :	This class implements a generic catalog

Methodes   :	Catalog()
				~Catalog()
				import()
				save()
				load()
				add()
				search()
				remove()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	Catalog.cpp

*****************************************************************************/

/* imports					   */
#include "Catalog.h"
#include "PopUpForm.h"

/* namespaces				   */
using namespace MediaBrowser;

/****************************************************************************
Method      :	Catalog()                                                                                                               
Function    :	Constructor for the catalog-class                                                                                    
Type        :	Constructor                                                                                                                       
Input Para  :	pathSaveName		name of the data savefile               
				pathSaveSchema		name of the schema savefile                                                                                                
Output Para :	None                                                                                                                                 
Author      :	Matthias Stalder
				Daniel Ziörjen                                                                          
History     :	21.04.2015 created                                                                                                          
/*****************************************************************************/
Catalog::Catalog(String ^ pathSaveName, String ^ pathSaveSchema)
	: pathSaveFileCatalog(pathSaveName), pathSaveFileSchema(pathSaveSchema)
{
}

/****************************************************************************
Method      :	~Catalog()
Function    :	Destructor for the catalog-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
Catalog::~Catalog()
{
}

/****************************************************************************
Method      :	save()
Function    :	saves the data and the schema of the data
Type        :	global
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
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

/****************************************************************************
Method      :	load()
Function    :	loads existing data to the catalog
Type        :	global
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
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

/****************************************************************************
Method      :	add()
Function    :	adds an new file to the catalog. 
Type        :	global
Input Para  :	newFile			the file to be added
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void Catalog::add(MediaFile ^newFile)
{
	//add Columns for new Keys
	for each (String ^key in newFile->getInformations()->Keys)
	{
		if (!Columns->Contains(key))
		{
			Columns->Add(key);

			if (newFile->getReadonlyinformation()->ContainsKey(key))
			{
				Columns[key]->ReadOnly = newFile->getReadonlyinformation()[key];
			}
			else
			{
				newFile->getReadonlyinformation()->Add(key, true);		// eigetlich unnötig
				Columns[key]->ReadOnly = TRUE;
			}
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

/****************************************************************************
Method      :	search()
Function    :	searchs in every column for the searchStr and filters the
				displayed data in the dataGridView.
Type        :	global
Input Para  :	searchStr			the data filtered with this string
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void Catalog::search(String ^ searchStr)
{
	String ^ filterStr;
	try
	{
		for each (DataColumn ^ column in Columns)
		{
			filterStr += (column->ToString() + " LIKE '%" + searchStr + "%' OR ");
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

/****************************************************************************
Method      :	remove()
Function    :	removes a row from the catalog
Type        :	global
Input Para  :	currentRow		the row to be deleted
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void Catalog::remove(DataGridViewRow ^ currentRow)
{
	try
	{
		DataRow ^ drow = safe_cast<DataRowView ^>(currentRow->DataBoundItem)->Row;
		Rows->Remove(drow);
	}
	catch (Exception ^ e)		// catch all
	{
		// Popup nur nervend, tritt auf wenn katalog leer
		// PopUpForm ^ popWindow = gcnew PopUpForm("Fehler", "Entfernen fehlgeschlagen. Eine Exception ist aufgetreten.", "Exception: " + e->Message);
	}
}
