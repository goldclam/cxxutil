#include <cstdlib>
#include <iostream>
#include <fstream>
#include "jsoncppexam.h"

// JSON header
#include "json/json.h"


void jsoncpp_exam() {
	std::cout << "[jsoncpp_exam]" << std::endl;

//READ Json from file
    Json::CharReaderBuilder rbuilder;
    std::ifstream ifs("exam/example.json");
    Json::Value iroot;   // will contains the root value after parsing.
    JSONCPP_STRING err;

    // read from stream
    // <example.json>
    // {
    // "encoding" : "UTF-8",
    // "plug-ins" : [
    //     "python",
    //     "c++",
    //     "ruby"
    //     ],
    // "indent" : { "length" : 3, "use_space": true }
    // }
    std::cout << std::endl << ">>>> read from stream <<<<" << std::endl;
    if (!Json::parseFromStream(rbuilder,ifs,&iroot,&err)) {
        std::cout << "[Error] parseFromStream: " << err << std::endl;
    }

    std::string encoding = iroot.get("encoding", "UTF-X" ).asString();
    std::cout << "encoding: " << encoding << std::endl;

    const Json::Value plugins = iroot["plug-ins"];   //read "plug-ins" sub-tree
    std::cout << "plug-ins : ";
    for ( int index = 0; index < plugins.size(); ++index )  // Iterates over the sequence elements.
        std::cout << plugins[index].asString() << ", ";
    std::cout << std::endl;


    // read from string
    std::cout << std::endl << ">>>> read from string <<<<" << std::endl;
    const std::string rawJson = R"({"Age": 20, "Name": "soonwoo"})";
    const int rawJsonLength = static_cast<int>(rawJson.length());
    std::unique_ptr<Json::CharReader> const reader(rbuilder.newCharReader());
    if (!reader->parse(rawJson.c_str(), rawJson.c_str() + rawJsonLength, &iroot,
                       &err)) {
        std::cout << "[Error] reader: " << err << std::endl;
    }
    const std::string name = iroot["Name"].asString();
    const int age = iroot["Age"].asInt();
    std::cout << "name: " << name << std::endl;
    std::cout << "age: " << age << std::endl << std::endl;



// write example
// {
//     1key1 : valueAA,
//     1key2 : {
//                 2key1 : valueBA,
//                 2key2 : valueBB,
//                 2key3 : valueBC,
//             },
//     1key3 : [ valueCA, valueCB, valueCC] }
// }


// KEY can be specified as      ["key"]
// VALUE can assigned as        = "value"
// ARRAY-VALUE can be appended  [].append("array-value")
    Json::Value oroot; 
    oroot["1key1"] = "valueAA";
    oroot["1key2"]["2key1"] = "valueBA";
    oroot["1key2"]["2key2"] = "valueBB";
    oroot["1key2"]["2key3"] = "valueBC";
    oroot["1key3"].append("valueCA");
    oroot["1key3"].append("valueCA");
    oroot["1key3"].append("valueCA");

/* warning: ‘StyledWriter’ is old style and deprecated: Use StreamWriterBuilder instead [-Wdeprecated-declarations] */
    std::cout << std::endl << "[StyledWriter]" << std::endl;
    Json::StyledWriter styledwriter;
    std::cout << styledwriter.write( oroot ) << std::endl;

    std::cout << std::endl << "[Jason::value]" << std::endl;
    std::cout << oroot << std::endl;

    std::cout << std::endl << "\n[StreamWriterBuilder]";
    Json::StreamWriterBuilder wbuilder;
    //wbuilder.setDefaults();  //write builder has settings, refer Default settings
    //! [StreamWriterBuilderDefaults]
    // (*settings)["commentStyle"] = "All";
    // (*settings)["indentation"] = "\t";
    // (*settings)["enableYAMLCompatibility"] = false;
    // (*settings)["dropNullPlaceholders"] = false;
    // (*settings)["useSpecialFloats"] = false;
    // (*settings)["precision"] = 17;
    // (*settings)["precisionType"] = "significant";
    //! [StreamWriterBuilderDefaults]

    // write to stream
    wbuilder["indentation"] = "....";  // indentation default is \t
    std::cout << std::endl << ">>>> write to stream, indentation with .... <<<<" << std::endl;
    const std::unique_ptr<Json::StreamWriter> writer(wbuilder.newStreamWriter());
    writer->write(oroot, &std::cout);
    std::cout << std::endl;

    // write to string
    wbuilder["indentation"] = ",,,,";  // indentation default is \t
    std::cout << std::endl << ">>>> write to string, indentation with ,,,, <<<<" << std::endl;
    const std::string json_file = Json::writeString(wbuilder, oroot);
    std::cout << json_file << std::endl;

    // write to string
    wbuilder["indentation"] = "\t";  // indentation default is \t
    std::cout << std::endl << ">>>> write to string, indentation with TAB <<<<" << std::endl;
    const std::string json_file2 = Json::writeString(wbuilder, oroot);
    std::cout << json_file2 << std::endl;

    // write to string
    std::cout << std::endl << ">>>> write to string with toStyledString() <<<<" << std::endl;
    std::cout << oroot.toStyledString() << std::endl;
}
