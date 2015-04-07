#pragma once

#include <windows.h>
#include <tchar.h>
#include <stdio.h>

using namespace System;
using namespace System::Data;
using namespace System::Collections::Generic;

ref class MediaFile
{
protected:
	Dictionary<String^, String^> ^informations = gcnew Dictionary<String^, String^>();
public:
	static String ^pathKey = "Path";
	static String ^dateCreationKey = "DateCreated";
	static String ^dateModifiedKey = "DateModified";


public:
	MediaFile();
	virtual ~MediaFile();

	Dictionary<String^, String^> ^getInformations();
	String ^getPath();
	String ^getDateCreation();
	String ^getDateModified();

	void setPath(String ^path);
	void setDateCreation(String ^dateCreation);
	void setDateModified(String ^dateModified);

	void play();

	virtual void edit();
};

