#include "Helper.hpp"

/***************************************************************/
/* User input functions ****************************************/
/***************************************************************/

bool Helper::s_needCinIgnore = false;

int Helper::GetIntInput()
{
    return StringToInt( GetStringInput() );
}

float Helper::GetFloatInput()
{
    return StringToFloat( GetStringInput() );
}

char Helper::GetCharInput()
{
    string str = GetStringInput();
    return str[0];
}

string Helper::GetStringInput()
{
    s_needCinIgnore = true;
    string strValue;
    cin >> strValue;
    return strValue;
}

string Helper::GetStringLine()
{
    if ( s_needCinIgnore )
    {
        cin.ignore();
    }

    s_needCinIgnore = false;
    string strValue;
    getline( cin, strValue );
    return strValue;
}

int Helper::GetIntInput( int min, int max )
{
    int input = GetIntInput();

    while ( input < min || input > max )
    {
        cout << "Invalid selection. Try again: " << endl;
        input = GetIntInput();
    }

    return input;
}


/***************************************************************/
/* Menu functionality ******************************************/
/***************************************************************/

void Helper::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Helper::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << " Press ENTER to continue..." << endl;
        if ( s_needCinIgnore )
        {
            cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
        }
        else
        {
            cin.get();
        }
    #endif
}

void Helper::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Helper::DrawHorizontalBar( int width, char symbol /*= '-'*/ )
{
    cout << string( width, symbol ) << endl;
}

void Helper::ShowMenu( const vector<string>& options, bool vertical /*= true*/, bool startAtOne /*= true*/ )
{
    for ( size_t i = 0; i < options.size(); i++ )
    {
        int number = ( startAtOne ) ? i+1 : i;
        cout << " " << number << ".";
        if ( vertical ) { cout << "\t"; } else { cout << " "; }
        cout << options[i];
        if ( vertical ) { cout << "\n"; } else { cout << "\t"; }
    }
    cout << endl;
}

int  Helper::ShowMenuGetInt( const vector<string>& options, bool vertical /*= true*/, bool startAtOne /*= true*/ )
{
    ShowMenu( options, vertical, startAtOne );
    int minVal = ( startAtOne ) ? 1 : 0;
    int maxVal = ( startAtOne ) ? options.size() : options.size() - 1;
    int choice = GetIntInput( minVal, maxVal );
    return choice;
}


/***************************************************************/
/* System info *************************************************/
/***************************************************************/

void Helper::PrintPwd()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "echo %cd%" );
    #else
        system( "pwd" );
    #endif
}

void Helper::Sleep( int milliseconds )
{
    this_thread::sleep_for( chrono::milliseconds( milliseconds ) );
}

void Helper::DisplayDirectoryContents( string path )
{
    string command;

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    command = "dir ";
    #else
    command = "ls ";
    #endif

    command += path;

    system( command.c_str() );
}


/***************************************************************/
/* Conversion functionality ************************************/
/***************************************************************/

int      Helper::StringToInt( const string& str )
{
    int value = 0;
    try
    {
        value = stoi( str );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cout << "Cannot convert \"" << str << "\" to int!" << std::endl;
        return -1;
    }

    return value;
}

float    Helper::StringToFloat( const string& str )
{
    float value = 0;
    try
    {
        value = stof( str );
    }
    catch( const std::invalid_argument& ex )
    {
        std::cout << "Cannot convert \"" << str << "\" to float!" << std::endl;
        return -1;
    }

    return value;
}

string   Helper::CurrencyToString( float currency )
{
    stringstream ss;
    ss << "$" << fixed << setprecision(2) << currency;
    return ss.str();
}

string   Helper::ToUpper( const string& val )
{
    string str = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        str += toupper( val[i] );
    }
    return str;
}

string   Helper::ToLower( const string& val )
{
    string str = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        str += tolower( val[i] );
    }
    return str;
}


/***************************************************************/
/* String helpers **********************************************/
/***************************************************************/

bool     Helper::Contains( string haystack, string needle, bool caseSensitive /*= true*/ )
{
    string a = haystack;
    string b = needle;

    if ( !caseSensitive )
    {
        for ( unsigned int i = 0; i < a.size(); i++ )
        {
            a[i] = tolower( a[i] );
        }

        for ( unsigned int i = 0; i < b.size(); i++ )
        {
            b[i] = tolower( b[i] );
        }
    }

    return ( a.find( b ) != string::npos );
}

int      Helper::Find( string haystack, string needle )
{
    return haystack.find( needle );
}

string   Helper::Replace( string fulltext, string findme, string replacewith )
{
    string updated = fulltext;
    int index = updated.find( findme );

    while ( index != string::npos )
    {
        // Make the replacement
        updated = updated.replace( index, findme.size(), replacewith );

        // Look for the item again
        index = updated.find( findme );
    }

    return updated;
}

vector<string> Helper::Split( string str, string delim )
{
    vector<string> data;

    int begin = 0;
    int end = 0;

    while ( str.find( delim ) != string::npos )
    {
        end = str.find( delim );

        // Get substring up until delimiter
        int length = end - begin;
        string substring = str.substr( begin, length );
        data.push_back( substring );

        // Remove this chunk of string
        str = str.erase( begin, length+1 );
    }

    // Put last string in structure
    data.push_back( str );

    return data;
}

/***************************************************************/
/* Timer functionality *****************************************/
/***************************************************************/

chrono::system_clock::time_point Helper::s_startTime;

void Helper::ClockStart()
{
    s_startTime = chrono::high_resolution_clock::now();
}

size_t Helper::GetElapsedSeconds()
{
    auto current_time = std::chrono::high_resolution_clock::now();
    return chrono::duration_cast<std::chrono::seconds>( current_time - s_startTime ).count();
}

size_t Helper::GetElapsedMilliseconds()
{
    auto current_time = std::chrono::high_resolution_clock::now();
    return chrono::duration_cast<std::chrono::milliseconds>( current_time - s_startTime ).count();
}


/***************************************************************/
/* Random functionality ****************************************/

void Helper::SeedRandomNumberGenerator()
{
    srand( time( NULL ) );
}

int  Helper::GetRandom( int min, int max )
{
    return rand() % ( max - min + 1 ) + min;
}
