#include "Settings.h"

int main()
{
    bool  b = false;
    int   i = 2000;
    float f = 1.73e3f;
    string str = "../data/data15.data";
    double d = 4.5;

    Settings::load( "settings.xml",
                    MakeParam(b, "boolean"),
                    MakeParam(i, "integer"),
                    MakeParam(f, "float"),
                    MakeParam(str, "string"),
                    MakeParam(d, "double number") );

    return 0;
}



