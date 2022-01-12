#include <iostream>
#include <string>
using namespace std;

#include "Image.h"
#include "Utilities/Helper.hpp"

void DisplayLog( const string& message )
{
    cout << endl << string( 80, '-' ) << endl << message << endl << string( 80, '-' ) << endl;
}

void ImageOperation1( const string IMAGE_PATH )
{
    DisplayLog( "1. Create an image and draw some pixels to it." );

    // Draw an image
    DisplayLog( "Create an image and fill it with white" );
    
    // TODO: Add

    DisplayLog( "Draw pixels manually" );
    
    // TODO: Add

    DisplayLog( "Save the image" );
    
    // TODO: Add
}

void ImageOperation2( const string IMAGE_PATH )
{
    DisplayLog( "2. Load an existing image and apply a filter to it." );

    // Add a filter to an image
    DisplayLog( "Load an existing image" );
    
    // TODO: Add

    DisplayLog( "Apply a filter to the image" );
    
    // TODO: Add

    DisplayLog( "Save the modified image" );
    
    // TODO: Add
}

void ImageOperation3( const string IMAGE_PATH )
{
    DisplayLog( "3. Create an image and draw some pixels to it." );
    
    // TODO: Add
}

void ImageOperation4( const string IMAGE_PATH )
{
    DisplayLog( "4. Load an existing image and apply a filter to it." );
    
    // TODO: Add
}

int main()
{
    string imagePath = "../images/";
    
    cout << "Enter path to images directory: ";
    getline( cin, imagePath );

    cout << "Image directory set to \"" << imagePath << "\", files in directory:" << endl;
    Helper::DisplayDirectoryContents( imagePath );
    Helper::DrawHorizontalBar( 80, '-' );

    ImageOperation1( imagePath );
    ImageOperation2( imagePath );
    ImageOperation3( imagePath );
    ImageOperation4( imagePath );

    return 0;
}

