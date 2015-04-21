/***************************************************************************
Header     :	MovieCatalog                                    Version 1.0
****************************************************************************

Function   :	This class implements a moviecatalog. it derived from the
				abstract baseclass catalog.

Methodes   :	MovieCatalog()
				~MovieCatalog()
				import()
				getFile()

Author     :	Matthias Stalder
				Daniel Ziörjen

History    :	21.04.2015

File       :	MovieCatalog.cpp

*****************************************************************************/

/* imports					   */
#include "MovieCatalog.h"
#include "MovieFile.h"
#include "MediaInfoDLL.h"

/****************************************************************************
Method      :	MovieCatalog()
Function    :	Constructor for the moviecatalog-class
Type        :	Constructor
Input Para  :	pathSaveName		name of the data savefile
				pathSaveSchema		name of the schema savefile
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MovieCatalog::MovieCatalog(String ^ pathSaveName, String ^ pathSaveSchema)
	: Catalog(pathSaveName, pathSaveSchema)
{
	TableName = "movieCatalog";		// needs an name for save and load
}

/****************************************************************************
Method      :	~MovieCatalog()
Function    :	Destructor for the moviecatalog-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MovieCatalog::~MovieCatalog()
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
void MovieCatalog::import(String ^ folderPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile((wchar_t*)(Runtime::InteropServices::Marshal::StringToHGlobalUni(folderPath + endingMovieMP4).ToPointer()), &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		//	FindFirstFile failed
	}
	else
	{
		do	{
			if (FILE_ATTRIBUTE_DIRECTORY & FindFileData.dwFileAttributes){ continue; }						//Skip directories

			String ^ const strFilename = gcnew String(FindFileData.cFileName);
			String ^ strDateModified = "", ^ strDateCreation = "";

			FILE *file;
			const char * filename = (const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(folderPath + "\\" + strFilename).ToPointer());
			file = fopen(filename, "r");

			if (file != NULL)
			{
				MediaInfoDLL::MediaInfo minfo;
				MovieFile ^ movieFile = gcnew MovieFile();

				SYSTEMTIME fileTime;
				// Änderungsdatum
				FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &fileTime);
				strDateModified = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear) + " " + Convert::ToString(fileTime.wHour) + ":" + Convert::ToString(fileTime.wMinute);
				// Erstelldatum
				FileTimeToSystemTime(&FindFileData.ftCreationTime, &fileTime);
				strDateCreation = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear) + " " + Convert::ToString(fileTime.wHour) + ":" + Convert::ToString(fileTime.wMinute);

				movieFile->setPath(folderPath + "\\" + strFilename);
				movieFile->setDateCreation(strDateCreation);
				movieFile->setDateModified(strDateModified);

				minfo.Open((wchar_t*)Runtime::InteropServices::Marshal::StringToHGlobalUni(folderPath + "\\" + strFilename).ToPointer());
				movieFile->setTitle(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Title"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				movieFile->setResolution(gcnew String(minfo.Get(MediaInfoDLL::Stream_Video, 0, __T("Width"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()) + "  x "
					+ gcnew String(minfo.Get(MediaInfoDLL::Stream_Video, 0, __T("Height"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				movieFile->setDuration(gcnew String(minfo.Get(MediaInfoDLL::Stream_Video, 0, __T("Duration/String"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				movieFile->setFramerate(gcnew String(minfo.Get(MediaInfoDLL::Stream_Video, 0, __T("FrameRate"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				minfo.Close();

				add(movieFile);

				delete movieFile;
				fclose(file);
			}
		} while (FindNextFile(hFind, &FindFileData));

		FindClose(hFind);
	}
}

/****************************************************************************
Method      :	getFile()
Function    :	convertes the data in a row to a MovieFile. Therefore it uses
				the template getFileFromRow().
Type        :	global
Input Para  :	currentRow		the row which should be converted
Output Para :	MovieFile		the generated MusicFile
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MovieFile ^ MovieCatalog::getFile(DataGridViewRow ^ currentRow)
{
	return Catalog::getFileFromRow<MovieFile^>(currentRow);
}

