#include "Settings.h"

int main()
{
    // Parameters
    bool  b = false;
    int   i = 2000;
    float f = 1.73e3f;

    // Settings file name
    string filename = "settings.xml";

    Settings::load( filename, MakeParam(b, "boolean"),
                              MakeParam(i, "integer"),
                              MakeParam(f, "float") );

    return 0;
}



