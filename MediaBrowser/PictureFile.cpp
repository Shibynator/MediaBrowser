#include "PictureFile.h"

using namespace System;

PictureFile::PictureFile()
{
}

PictureFile::PictureFile(String ^ tit, String ^ res, String ^ fst, String ^ exp, String ^ is)
	: title(tit), resolution(res), fstop(fst), exposuretime(exp), iso(is)
{

}

PictureFile::PictureFile(String ^ pat, String ^ dcre, String ^ dmod, String ^ tit, String ^ res, String ^ fst, String ^ exp, String ^ is)
	: MediaFile(pat, dcre, dmod), title(tit), resolution(res), fstop(fst), exposuretime(exp), iso(is)
{

}

PictureFile::~PictureFile()
{
}

void PictureFile::play()
{
}

void PictureFile::edit()
{
}