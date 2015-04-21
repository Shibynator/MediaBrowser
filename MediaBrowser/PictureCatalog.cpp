/***************************************************************************
Header     :	PictureCatalog                                    Version 1.0
****************************************************************************

Function   :	This class implements a picturecatalog. it derived from the
				abstract baseclass catalog.

Methodes   :	PictureCatalog()
				~PictureCatalog()
				import()
				getFile()

Author     :	Matthias Stalder
Daniel Ziörjen

History    :	21.04.2015

File       :	PictureCatalog.cpp

*****************************************************************************/

/* imports					   */
#include "PictureCatalog.h"
#include "PictureFile.h"
#include <FreeImage.h>

/****************************************************************************
Method      :	PictureCatalog()
Function    :	Constructor for the picturecatalog-class
Type        :	Constructor
Input Para  :	pathSaveName		name of the data savefile
p				athSaveSchema		name of the schema savefile
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
PictureCatalog::PictureCatalog(String ^ pathSaveName, String ^ pathSaveSchema)
	: Catalog(pathSaveName, pathSaveSchema)
{
	TableName = "pictureCatalog";		// needs an name for save and load
}

/****************************************************************************
Method      :	~PictureCatalog()
Function    :	Destructor for the picturecatalog-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
PictureCatalog::~PictureCatalog()
{
}

/****************************************************************************
Method      :	import()
Function    :	imports new data to the catalog
Type        :	global
Input Para  :	folderPath			the path to the new data
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
void PictureCatalog::import(String ^ folderPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile((wchar_t*)(Runtime::InteropServices::Marshal::StringToHGlobalUni(folderPath + endingPictureJPG).ToPointer()), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		//	FindFirstFile failed
	}
	else
	{
		do
		{
			if (FILE_ATTRIBUTE_DIRECTORY & FindFileData.dwFileAttributes){ continue; }						//Skip directories

			String ^ const strFilename = gcnew String(FindFileData.cFileName);
			String ^ strDateModified = "", ^ strDateCreation = "";

			FILE *file;
			const char * filename = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(folderPath + "\\" + strFilename).ToPointer());
			file = fopen(filename, "r");

			if (file != NULL)
			{
				PictureFile ^ pictureFile = gcnew PictureFile();

				SYSTEMTIME fileTime;
				// Änderungsdatum
				FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &fileTime);
				strDateModified = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear) + " " + Convert::ToString(fileTime.wHour) + ":" + Convert::ToString(fileTime.wMinute);
				// Erstelldatum
				FileTimeToSystemTime(&FindFileData.ftCreationTime, &fileTime);
				strDateCreation = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear) + " " + Convert::ToString(fileTime.wHour) + ":" + Convert::ToString(fileTime.wMinute);

				pictureFile->setPath(folderPath + "\\" + strFilename);
				pictureFile->setDateCreation(strDateCreation);
				pictureFile->setDateModified(strDateModified);

				pictureFile->mapInformations(folderPath + "\\" + strFilename, FIMD_EXIF_EXIF);

				add(pictureFile);

				fclose(file);
			}
		} while (FindNextFile(hFind, &FindFileData));

		FindClose(hFind);
	}
}

/****************************************************************************
Method      :	getFile()
Function    :	convertes the data in a row to a PictureFile. Therefore it 
				uses the template getFileFromRow().
Type        :	global
Input Para  :	currentRow		the row which should be converted
Output Para :	PictureFile		the generated MusicFile
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
PictureFile ^ PictureCatalog::getFile(DataGridViewRow ^ currentRow)
{
	return Catalog::getFileFromRow<PictureFile^>(currentRow);
}

