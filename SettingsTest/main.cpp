#include <QtCore/QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QObject>

#include "GlobalSettings.h"

void save();
void load();

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	load();
	return a.exec();
}


void save() {
	QSettings settings("settings.ini", QSettings::IniFormat);
	settings.beginGroup("BuriedCO");
	settings.setValue("IP", "192.168.1.125");
	settings.setValue("Port", 8056);
	settings.endGroup();
}

void load() {
	QSettings settings("settings.ini", QSettings::IniFormat);
	settings.beginGroup("BuriedCO");
	GlobalSettings::IP = settings.value("IP", "127.0.0.1").toString();
	GlobalSettings::port = settings.value("Port", 8056).toInt();

	qDebug() << GlobalSettings::IP << "-" << GlobalSettings::port;
	settings.endGroup();
}