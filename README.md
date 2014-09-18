Load-Settings
=============

Load parameter values from a xml file using C++ boost library. 
1. xml file will be created on the first run of the program.
2. All values in the xml file can be updated. If so, '(updated)' will be tag after the parameter. Refer to example output below for more information. 
3. An arbitary number of parameters is supported. 
4. C++11 required. 


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

***Console***
```
Parameters are set to the following: 
           boolean: 1 (updated)
           integer: 2000
             float: 1730
```

***file_name.xml***
```
<?xml version="1.0" encoding="utf-8"?>
<boolean>true</boolean>
<integer>2000</integer>
<float>1730</float>
```
