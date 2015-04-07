#include "MovieFile.h"

using namespace System;

MovieFile::MovieFile()
{
	informations->Add(titleKey, "unbekannt");
	informations->Add(resolutionKey, "unbekannt");
	informations->Add(durationKey, "00:00:00");
	informations->Add(framerateKey, "unbekannt");
}

MovieFile::~MovieFile()
{
}

String ^ MovieFile::getTitle(){ return informations[titleKey]; }
String ^ MovieFile::getResolution(){ return informations[resolutionKey]; }
String ^ MovieFile::getDuration(){ return informations[durationKey]; }
String ^ MovieFile::getFramerate(){ return informations[framerateKey]; }

void MovieFile::setTitle(String ^title){ informations[MovieFile::titleKey] = title; }
void MovieFile::setResolution(String ^resolution){ informations[MovieFile::resolutionKey] = resolution; }
void MovieFile::setDuration(String ^duration){ informations[MovieFile::durationKey] = duration; }
void MovieFile::setFramerate(String ^framerate){ informations[MovieFile::framerateKey] = framerate; }

void MovieFile::edit()
{
}