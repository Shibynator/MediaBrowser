#include "PictureCatalog.h"
#include "PictureFile.h"

PictureCatalog::PictureCatalog()
{
}

PictureCatalog::~PictureCatalog()
{
}

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

				pictureFile->setTitle("didel");
				pictureFile->setResolution("dadel");
				pictureFile->setFstop("dudel");
				pictureFile->setExposuretime("da");
				pictureFile->setISO("!!!");

				add(pictureFile);

				delete pictureFile;
				fclose(file);
			}
		} while (FindNextFile(hFind, &FindFileData));

		FindClose(hFind);
	}
}

void PictureCatalog::search()
{
}

void PictureCatalog::sort()
{
}

void PictureCatalog::remove()
{
}

void PictureCatalog::save()
{
}

void PictureCatalog::load()
{
}
