#ifndef _CSV_PARSER_HPP
#define _CSV_PARSER_HPP

#include "Helper.hpp"

#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct CsvDocument
{
    vector<string> header;
    vector< vector< string > > rows;
};

class CsvParser
{
    public:
    static CsvDocument Parse( string filepath );
    static void Save( string filepath, const CsvDocument& doc );
    static vector<string> CsvSplit( string str, char delim );
};

#endif
