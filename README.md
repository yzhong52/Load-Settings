Load-Settings
=============

Load parameter values from a xml file using C++ boost library


Sample code
-----
```
    bool  b = false;
    int   i = 2000;
    float f = 1.73e3f;

    Settings::load( "settings.xml",
                    MakeParam(b, "boolean"),
                    MakeParam(i, "integer"),
                    MakeParam(f, "float") );
```


Example output
------

```
Parameters are set to the following: 
           boolean: 0
           integer: 2000
             float: 1730
```