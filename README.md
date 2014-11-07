Load-Settings
=============

When you design a program with a bunch of parameters to tune, you don't want to hard code the parameters in code because that means you need to recompile the porgram everytime you try a new parameter. Instead, all tunable parameters should be saved to file and could be updated in that file. 

The API is simple to use. All you need to provide is a filename where you want to save the settings and a set of parameters and their corresponding names. 

```
Seetings::( Filename, MakeParam(Parameter, Parameter name) );
```

1. A xml file will be automatically generated on the first run of the program with a list of all parameters and their default values.
2. All parameters in the xml file can be updated and the program will load new values from the xml file. If a parameter is update, a *updated* tag added behind hte parameter. 
3. The API function supports an arbitary number of parameters. 
4. C++11 and [boost libraries](http://www.boost.org/) ae required. 


Sample code
-----
```
int main(){
    // Parameters
    bool  b = false;
    int   i = 2000;
    float f = 1.73e3f;

    // Settings file name
    string filename = "settings.xml";

    Settings::load( filename, MakeParam(b, "boolean"),
                          MakeParam(i, "integer"),
                          MakeParam(f, "float") );
}
```


Example output
------

The console output: 

```
Parameters are set to the following: 
           boolean: 1 (updated)
           integer: 2000
             float: 1.73e3f
```

A *settings.xml* file: 

```
<?xml version="1.0" encoding="utf-8"?>
<boolean>true</boolean>
<integer>2000</integer>
<float>1730</float>
```
