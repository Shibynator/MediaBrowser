#include "MovieFile.h"

using namespace System;

MovieFile::MovieFile()
{
}

MovieFile::MovieFile(String ^ tit, String ^ res, String ^ dur, String ^ frm)
	: title(tit), resolution(res), duration(dur), framerate(frm)
{

}

MovieFile::MovieFile(String ^ pat, String ^ dcre, String ^ dmod, String ^ tit, String ^ res, String ^ dur, String ^ frm)
	: MediaFile(pat, dcre, dmod), title(tit), resolution(res), duration(dur), framerate(frm)
{

}


MovieFile::~MovieFile()
{
}

void MovieFile::play()
{
}

void MovieFile::edit()
{
}