#include <QtCore/QCoreApplication>
#include <QSettings>

void save();

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	save();
	return a.exec();
}


void save() {
	QSettings settings("settings.ini", QSettings::IniFormat);
	settings.beginGroup("BuriedCO");
	settings.setValue("IP", "192.168.1.125");
	settings.setValue("Port", 8056);
	settings.endGroup();
}