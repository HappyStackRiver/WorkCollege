#ifndef _HELPER_HPP
#define _HELPER_HPP

#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Helper
{
    /***************************************************************/
    /* User input functions ****************************************/
    public:
    static int      GetIntInput();
    static float    GetFloatInput();
    static char     GetCharInput();
    static string   GetStringInput();
    static string   GetStringLine();
    static int      GetIntInput( int min, int max );

    private:
    static bool     s_needCinIgnore;

    /***************************************************************/
    /* Menu functionality ******************************************/
    public:
    static void ClearScreen();
    static void Pause();
    static void Header( const string& header );
    static void DrawHorizontalBar( int width, char symbol = '-' );
    static void ShowMenu( const vector<string>& options, bool vertical = true, bool startAtOne = true );
    static int  ShowMenuGetInt( const vector<string>& options, bool vertical = true, bool startAtOne = true );

    /***************************************************************/
    /* System info *************************************************/
    public:
    static void PrintPwd();
    static void Sleep( int milliseconds );
    static void DisplayDirectoryContents( string path );

    /***************************************************************/
    /* Conversion functionality ************************************/
    public:
    template <typename T>
    static string   ToString( const T& value );

    static int      StringToInt( const string& str );
    static float    StringToFloat( const string& str );
    static string   CurrencyToString( float currency );
    static string   ToUpper( const string& val );
    static string   ToLower( const string& val );

    /***************************************************************/
    /* String helpers **********************************************/
    public:
    static bool     Contains( string haystack, string needle, bool caseSensitive = true );
    static int      Find( string haystack, string needle );
    static string   Replace( string fulltext, string findme, string replacewith );
    static vector<string> Split( string str, string delim );

    /***************************************************************/
    /* Array helpers ***********************************************/
    public:
    template <typename T>
    static void     ArrayOutput( T myArray[], int size, ofstream& out );
    template <typename T>
    static string   ArrayToString( T myArray[], int size );

    template <typename T>
    static void     VectorOutput( vector<T> myVector, ofstream& out );
    template <typename T>
    static string   VectorToString( vector<T> myVector );

    /***************************************************************/
    /* Timer functionality *****************************************/
    public:
    static void   ClockStart();
    static size_t GetElapsedSeconds();
    static size_t GetElapsedMilliseconds();

    private:
    static chrono::system_clock::time_point s_startTime;

    /***************************************************************/
    /* Random functionality ****************************************/
    public:
    static void SeedRandomNumberGenerator();
    static int  GetRandom( int min, int max );
};


template <typename T>
string Helper::ToString( const T& value )
{
    stringstream ss;
    ss << value;
    return ss.str();
}


template <typename T>
void Helper::ArrayOutput( T myArray[], int size, ofstream& out )
{
    for ( int i = 0; i < size; i++ )
    {
        if ( i != 0 ) { cout << ", "; }
        out << myArray[i];
    }
    out << endl;
}

template <typename T>
string Helper::ArrayToString( T myArray[], int size )
{
    string text = "";

    for ( int i = 0; i < size; i++ )
    {
        if ( i != 0 ) { text += ", "; }
        text += ToString( myArray[i] );
    }

    return text;
}

template <typename T>
void     Helper::VectorOutput( vector<T> myVector, ofstream& out )
{
    for ( size_t i = 0; i < myVector.size(); i++ )
    {
        if ( i != 0 ) { cout << ", "; }
        out << myVector[i];
    }
    out << endl;
}

template <typename T>
string   Helper::VectorToString( vector<T> myVector )
{
    string text = "";

    for ( size_t i = 0; i < myVector.size(); i++ )
    {
        if ( i != 0 ) { text += ", "; }
        text += ToString( myVector[i] );
    }

    return text;
}

#endif
