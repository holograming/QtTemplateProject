#include <QApplication>
#include <ui/ColorBarDialog.h>

int __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, char*, int nShowCmd)
{
  QApplication app (__argc, __argv);

  ColorBarDialog e;
  e.setFixedSize(30, 500);
  e.show();

  return app.exec();
 }
