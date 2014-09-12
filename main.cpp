#include "Settings.h"

int main()
{
    bool  b = false;
    int   i = 2000;
    float f = 1.73e3f;

    Settings::load( "settings.xml",
                    MakeParam(b, "boolean"),
                    MakeParam(i, "integer"),
                    MakeParam(f, "float") );

    return 0;
}



