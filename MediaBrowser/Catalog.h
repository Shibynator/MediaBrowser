#ifndef CATALOG_HPP
#define CATALOG_HPP

/***************************************************************************
  Header     :	Catalog                                      Version 1.0    
****************************************************************************
                                                                           
  Function   :	This class implements a generic, abstract catalog.                      
                                                                           
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
                                                                           
  File       :	Catalog.h                                              
                                                                           
*****************************************************************************/

#pragma once

/* imports					   */
#include "MediaFile.h"
#include "MusicFile.h"

/* namespaces				   */	
using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

/* Class definition            */
ref class Catalog abstract : public DataTable
{
	/* data      */
	protected:
		String ^ const pathSaveDir = "C:\\MediaBrowserTest";
		String ^ pathSaveFileCatalog;
		String ^ pathSaveFileSchema;

	/* methodes      */
	public:
		/****************************************************************************
		Method      :	getFileFromRow()
		Function    :	convertes the data in a row to a MediaFile (MusicFile,
						MovieFile or PictureFile).
		Type        :	template
		Input Para  :	currentRow		the row which should be converted
		Output Para :	MediaFile		the generated MediaFile
		Author      :	Matthias Stalder
						Daniel Ziörjen
		History     :	21.04.2015 created
		/*****************************************************************************/
		generic <typename T>  where T : MediaFile, ref class
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

		Catalog(String ^ pathSaveDir, String ^ pathSaveName);
		virtual ~Catalog();
		virtual void import(String ^ folderPath) = 0;	// pure virtual
		void save();
		void load();
		void add(MediaFile ^ newFile);
		void search(String ^ searchStr);
		void remove(DataGridViewRow ^ currentRow);
};

#endif