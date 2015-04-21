/***************************************************************************
Header     :	MusicCatalog                                    Version 1.0
****************************************************************************

Function   :	This class implements a musiccatalog. it derived from the
abstract baseclass catalog.

Methodes   :	MusicCatalog()
~MusicCatalog()
import()
getFile()

Author     :	Matthias Stalder
Daniel Ziörjen

History    :	21.04.2015

File       :	MusicCatalog.cpp

*****************************************************************************/

/* imports					   */
#include "MusicCatalog.h"
#include "MusicFile.h"
#include "MediaInfoDLL.h"

/****************************************************************************
Method      :	MusicCatalog()
Function    :	Constructor for the musiccatalog-class
Type        :	Constructor
Input Para  :	pathSaveName		name of the data savefile
				pathSaveSchema		name of the schema savefile
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MusicCatalog::MusicCatalog(String ^ pathSaveName, String ^ pathSaveSchema)
	: Catalog(pathSaveName, pathSaveSchema)
{

	TableName = "musicCatalog";		// needs an name for save and load
}

/****************************************************************************
Method      :	~MusicCatalog()
Function    :	Destructor for the musiccatalog-class
Type        :	Destructor
Input Para  :	none
Output Para :	None
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MusicCatalog::~MusicCatalog()
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
void MusicCatalog::import(String ^ folderPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	hFind = FindFirstFile((wchar_t*)(Runtime::InteropServices::Marshal::StringToHGlobalUni(folderPath + endingMusicMP3).ToPointer()), &FindFileData);
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
				MediaInfoDLL::MediaInfo minfo;
				MusicFile ^ musicFile = gcnew MusicFile();

				SYSTEMTIME fileTime;
				// Änderungsdatum
				FileTimeToSystemTime(&FindFileData.ftLastWriteTime, &fileTime);
				strDateModified = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear) + " " + Convert::ToString(fileTime.wHour) + ":" + Convert::ToString(fileTime.wMinute);
				// Erstelldatum
				FileTimeToSystemTime(&FindFileData.ftCreationTime, &fileTime);
				strDateCreation = Convert::ToString(fileTime.wDay) + "." + Convert::ToString(fileTime.wMonth) + "." + Convert::ToString(fileTime.wYear) + " " + Convert::ToString(fileTime.wHour) + ":" + Convert::ToString(fileTime.wMinute);

				musicFile->setPath(folderPath + "\\" + strFilename);
				musicFile->setDateCreation(strDateCreation);
				musicFile->setDateModified(strDateModified);

				minfo.Open((wchar_t*)Runtime::InteropServices::Marshal::StringToHGlobalUni(folderPath + "\\" + strFilename).ToPointer());
				musicFile->setTitle(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Title"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				musicFile->setArtist(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Artist"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				musicFile->setAlbumArtist(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Album/Performer"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				musicFile->setAlbum(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Album"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				musicFile->setGenre(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Genre"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				musicFile->setDuration(gcnew String(minfo.Get(MediaInfoDLL::Stream_General, 0, __T("Duration/String"), MediaInfoDLL::Info_Text, MediaInfoDLL::Info_Name).c_str()));
				minfo.Close();

				add(musicFile);

				delete musicFile;
				fclose(file);
			}
		} while (FindNextFile(hFind, &FindFileData));

		FindClose(hFind);
	}
}

/****************************************************************************
Method      :	getFile()
Function    :	convertes the data in a row to a MusicFile. Therefore it uses
				the template getFileFromRow().
Type        :	global
Input Para  :	currentRow		the row which should be converted
Output Para :	MusicFile		the generated MusicFile
Author      :	Matthias Stalder
				Daniel Ziörjen
History     :	21.04.2015 created
/*****************************************************************************/
MusicFile ^ MusicCatalog::getFile(DataGridViewRow ^ currentRow)
{
	return Catalog::getFileFromRow<MusicFile^>(currentRow);
}


