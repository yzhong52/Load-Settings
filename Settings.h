#include <iostream>
#include <fstream>
#include <exception>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>


using namespace std;
using boost::property_tree::ptree;




class Settings
{

public:

    // Load settings from file
    template<typename... Parameter>
    static void load(const string& filename, Parameter&&... params )
    {
        // Create empty property tree object
        ptree pt;

        try
        {
            // Load XML file and put its contents in property tree.
            // No namespace qualification is needed, because of Koenig
            // lookup on the second argument. If reading fails, exception
            // is thrown.
            read_xml(filename, pt);

            loadTree( pt, params... );
        }
        catch (std::exception &e)
        {
            std::cout << "Loading xml Error: " << e.what() << std::endl;
        }

        try {
            // Write parameters to tree
            writeTree( pt, params... );

            // Save tree to file
            // Reference: [boostproperty-tree-xml-pretty-printing]
            //            http://stackoverflow.com/questions/6572550/
            boost::property_tree::xml_writer_settings<char> settings('\n', 1);
            write_xml( filename, pt, std::locale(), settings );
        }
        catch (std::exception &e ) {
            std::cout << "Saving xml Error: " << e.what() << std::endl;
        }


        cout << endl << "Parameters are set to the following: " << endl;
        paramNameLength = maxParamNameLength( params... );
        print( params... );
    }

    template<typename T>
    struct Parameter
    {
        T& value;
        const string& name;
        bool updated;
    };

private:

    // Finish writing tree
    static void writeTree( ptree& pt ) { }

    // Writing tree
    template<typename Parameter1, typename... Parameter>
    static void writeTree( ptree& pt, Parameter1&& param1, Parameter&&... params )
    {
        // Write the current parameter to tree
        pt.put( param1.name, param1.value );
        // Continue writing tree
        writeTree( pt, params... );
    }

    // Finish loading tree
    static void loadTree( ptree& pt ) { }

    // Loading tree
    template<typename Parameter1, typename... Parameter>
    static void loadTree( ptree& pt, Parameter1& param1, Parameter&... params)
    {
        auto originalValue = param1.value;
        param1.value = pt.get( param1.name, param1.value );
        param1.updated = (originalValue!=param1.value);

        loadTree( pt, params... );
    }

    // Finish printing parameters
    static void print(){ }

    // Print parameters
    template<class Parameter1, class ... Parameter>
    static void print( Parameter1& param1, Parameter&... params ){
        // Add two more white space in front of the name for better formating
        cout.width( paramNameLength+2 );
        cout << param1.name << ": " << param1.value;
        cout << ( param1.updated ? " (updated)" : "" ) << endl;
        print( params... );
    }

    static unsigned paramNameLength;
    static unsigned maxParamNameLength(){ return 0; }

    // Get the maximum length of the names of the parameters
    template<class Parameter1, class ... Parameter>
    static unsigned maxParamNameLength( Parameter1& param1, Parameter&... params ){
        return std::max( (unsigned)param1.name.size(), maxParamNameLength(params...) );
    }
};

unsigned Settings::paramNameLength = 10;


template<typename T>
Settings::Parameter<T> MakeParam(T& value, string&& name )
{
    // replace all spaces in the name string to underscore
    replace( name.begin(), name.end(), ' ', '_' );
    return Settings::Parameter<T>( {value, name, false} );
}

