#include "MusicCatalog.h"
#include "MusicFile.h"
#include "MediaInfoDLL.h"

MusicCatalog::MusicCatalog()
{

}

MusicCatalog::~MusicCatalog()
{
}

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

MusicFile ^ MusicCatalog::getFile(DataGridViewRow ^ currentRow)
{
	DataRow ^ drow = safe_cast<DataRowView ^>(currentRow->DataBoundItem)->Row;

	MusicFile ^ musicFile = gcnew MusicFile();
	musicFile->setPath(drow[MusicFile::pathKey]->ToString());
	musicFile->setDateCreation(drow[MusicFile::dateCreationKey]->ToString());
	musicFile->setDateModified(drow[MusicFile::dateModifiedKey]->ToString());
	musicFile->setTitle(drow[MusicFile::titleKey]->ToString());
	musicFile->setArtist(drow[MusicFile::artistKey]->ToString());
	musicFile->setAlbumArtist(drow[MusicFile::albumArtistKey]->ToString());
	musicFile->setAlbum(drow[MusicFile::albumKey]->ToString());
	musicFile->setGenre(drow[MusicFile::genreKey]->ToString());
	musicFile->setDuration(drow[MusicFile::durationKey]->ToString());

	return musicFile;
}


void MusicCatalog::save()
{
}

void MusicCatalog::load()
{
}

