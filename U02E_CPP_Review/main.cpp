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
    PpmImage image(255, 10, 10);
    image.fillAll(255, 0, 0);

    // TODO: Add

    DisplayLog( "Draw pixels manually" );

    image.setPixel(0, 0, 0, 0, 0);
    image.setPixel(9, 0, 225, 255, 225);
    image.setPixel(9, 9, 0, 255, 0);
    image.setPixel(0, 9, 0, 0, 225);

    // TODO: Add

    DisplayLog( "Save the image" );
    // NOTE: This should be a ppm file -- Rachel
//    image.saveImage("Test.txt");
    image.saveImage("Test.ppm");
    // TODO: Add


    // NOTE:
//    The image drawn here is malformed. The file looks like this:
//    P3
//    # Comment
//    80 1
//    183956980             << bad color depth
//    0
//    0
//    0
}

void ImageOperation2( const string IMAGE_PATH )
{
    DisplayLog( "2. Load an existing image and apply a filter to it." );

    string filename = IMAGE_PATH + "umkc.ppm";

    // Add a filter to an image
    DisplayLog( "Load an existing image" );
    PpmImage image;
    image.loadImage(filename);

    // TODO: Add

    DisplayLog( "Apply a filter to the image" );
    image.applyFilter1();
    // TODO: Add

    DisplayLog( "Save the modified image" );
    image.saveImage(IMAGE_PATH + "umkcFilter.ppm");
    // TODO: Add
}

void ImageOperation3( const string IMAGE_PATH )
{
    DisplayLog( "3. Create an image and draw some pixels to it." );

    // Draw an image
    PpmImage image(255, 10, 10);
    image.fillAll(222, 222, 222);

    // TODO: Add

    DisplayLog("Draw pixels manually");

    image.setPixel(1, 7, 0, 0, 0);
    image.setPixel(3, 2, 25, 255, 25);
    image.setPixel(5, 3, 33, 55, 100);
    image.setPixel(0, 0, 8, 77, 225);

    // TODO: Add

    DisplayLog("Save the image");
    // NOTE: This should be a ppm file -- Rachel
//    image.saveImage("drawn.txt");
    image.saveImage("drawn.ppm");
    // TODO: Add

    // NOTE:
//    The image drawn here is malformed. The file looks like this:
//    P3
//    # Comment
//    0 1734438249              << bad image height
//    1966044005                << bad color depth


}

void ImageOperation4( const string IMAGE_PATH )
{
    DisplayLog( "4. Load an existing image and apply a filter to it." );

    string filename = IMAGE_PATH + "cat.ppm";

    // Add a filter to an image
    DisplayLog("Load an existing image");
    PpmImage image;
    image.loadImage(filename);

    // TODO: Add

    DisplayLog("Apply a filter to the image");
    image.applyFilter1();
    // TODO: Add

    DisplayLog("Save the modified image");
    image.saveImage(IMAGE_PATH + "catFilter.ppm");
    // TODO: Add
    // TODO: Add
}

int main()
{
//    string imagePath = "C:\Users\reyri\source\GitLabRepository\cs235_350-rriver10\U02E_CPP_Review\CppReview\CppReview\images";
    string imagePath = "images/";
    //The Directory path is not able to be read for some reason and I think it's due to the permissions I have set to my
    //computer but if this directory is input in the following
    //getline portion it works

    // NOTE: You probably need to write it as "images\\" since it's on Windows.
    // But remember that the \ is the escape character (e.g., \n, \t), so to get
    // a backslash you have to use \\.
    // -- Rachel

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

