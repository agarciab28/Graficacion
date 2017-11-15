
#include <cxcore.h>
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <time.h>
#include <ctype.h>


// Create memory for calculations
static CvMemStorage* storage0 = 0;
static CvMemStorage* storage1 = 0;
static CvMemStorage* storage2 = 0;
    CvScalar s;
// Create a new Haar classifier
static CvHaarClassifierCascade* cascade = 0;
CvFont font;
double hScale=1.0;
double vScale=1.0;
int    lineWidth=1;

// Function prototype for detecting and drawing an object from an image
void detect_and_draw( IplImage* image );

// Create a string that contains the cascade name
const char* cascade_name ="haarcascade_frontalface_alt2.xml";


/*    "haarcascade_profileface.xml";*/


int eye_opt=0;
int cascade_opt=0;
int circ_opt=0;
int rect_opt=0;
int object_opt=0;
int boca_opt=0;
int boca2_opt=0;
int cejas_opt=0;
int orejas_opt=0;
int nariz_opt=0;
int bigote_opt=0;

// Main function, defines the entry point for the program.
int main( int argc, char** argv )
{

    // Structure for getting video from camera or avi
    CvCapture* capture = 0;
    // Images to capture the frame from video or camera or from file
    IplImage *frame, *frame_copy = 0;


    // Load the HaarClassifierCascade
    cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );

    // Check whether the cascade has loaded successfully. Else report and error and quit
    if( !cascade )
    {
        fprintf( stderr, "ERROR: Could not load classifier cascade\n" );
        return -1;
    }

    // Allocate the memory storage
    storage0 = cvCreateMemStorage(0);
    storage1 = cvCreateMemStorage(0);
    storage2 = cvCreateMemStorage(0);



    // Create a new named window with title: result
    cvNamedWindow( "result", 1 );

    // Find if the capture is loaded successfully or not.
    // If loaded succesfully, then:
    int i=0;
    //capture = cvCaptureFromCAM(0);
    capture = cvCaptureFromCAM(0);
	//capture = cvCreateCameraCapture(0);
	//capture = cvCaptureFromCAM(0);
    if ( !capture ) {
    capture = cvCaptureFromAVI("/home/likcos/Titulacion/mas_opencv/p1");
	 // capture = cvCreateCameraCapture(0);
	  //  capture = cvCaptureFromCAM(0);
        if ( !capture ) {
            fprintf( stderr, "Cannot open initialize webcam!\n" );
            return 1;
        }
    }

    if( capture )
    {
        for(;;i++)
        {
            // Capture the frame and load it in IplImage
            if( !cvGrabFrame( capture ))
                break;
            frame = cvRetrieveFrame( capture );

            // If the frame does not exist, quit the loop
            if( !frame )
                break;

            // Allocate framecopy as the same size of the frame
            if( !frame_copy )
                frame_copy = cvCreateImage( cvSize(frame->width,frame->height), IPL_DEPTH_8U, frame->nChannels );

            // Check the origin of image. If top left, copy the image frame to frame_copy.
            if( frame->origin == IPL_ORIGIN_TL )
                cvCopy( frame, frame_copy, 0 );
            // Else flip and copy the image
            else
                cvFlip( frame, frame_copy, 0 );

            // Call the function to detect and draw the face
            detect_and_draw( frame_copy );

            // Wait for a while before proceeding to the next frame
            char c =  cvWaitKey( 10 );
           switch(c){
               case 27:
                   exit(0);
                   break;
               case '0':
                   circ_opt=!circ_opt;
                    break;
                case '1':
                   rect_opt=!rect_opt;
                    break;
               case '2':
                   eye_opt=!eye_opt;
                   break;
               case '3':
                   cejas_opt=!cejas_opt;
                     break;
               case '4':
                   boca_opt=!boca_opt;
                     break;
               case '5':
                   boca2_opt=!boca2_opt;
                     break;
               case '7':
                     bigote_opt=!bigote_opt;
                     break;
               case '8':
                   orejas_opt=!orejas_opt;
                     break;
               case '6':
                  nariz_opt=!nariz_opt;
                   break;
        }
        }
        // Release the images, and capture memory
        cvReleaseImage( &frame_copy );
        cvReleaseCapture( &capture );
    }


    // Destroy the window previously created with filename: "result"
    cvDestroyWindow("result");

    // return 0 to indicate successfull execution of the program
    return 0;
}

// Function to detect and draw any faces that is present in an image
void detect_and_draw( IplImage* img )
{
    int scale = 1;

    // Create a new image based on the input image
    IplImage* temp = cvCreateImage( cvSize(img->width/scale,img->height/scale), 8, 3 );

    // Create two points to represent the face locations
    CvPoint pt1, pt2;
    int i;

    // Clear the memory storage which was used before
    cvClearMemStorage( storage0 );
    cvClearMemStorage( storage1 );
    cvClearMemStorage( storage2 );

    // Find whether the cascade is loaded, to find the faces. If yes, then:
    if( cascade )
    {

        // There can be more than one face in an image. So create a growable sequence of faces.
        // Detect the objects and store them in the sequence
        CvSeq* faces = cvHaarDetectObjects( img, cascade, storage0, 1.8, 2, CV_HAAR_DO_CANNY_PRUNING, cvSize(40, 40) );
        //if (faces->total>0)

        // Loop the number of faces found.
        for( i = 0; i < (faces ? faces->total : 0); i++ )
        {
           // Create a new rectangle for drawing the face
            CvRect* r = (CvRect*)cvGetSeqElem( faces, i );

            // Find the dimensions of the face,and scale it if necessary
            pt1.x = r->x*scale;
            pt2.x = (r->x+r->width)*scale;
            pt1.y = r->y*scale;
            pt2.y = (r->y+r->height)*scale;
             int ancho = abs( pt2.x-pt1.x);
 			 int alto = abs(pt2.y-pt1.y);
              int ojo5=pt1.x+ ancho*0.3;
              int ojo6=pt1.y+alto*0.4;
              int ojo7=ojo5+ojo6;
             int resolucion = (ancho + alto)/8;
             CvPoint ojo1, ojo2, boca1, boca2, bigote1, bigote2, cara, nariz1, nariz2;
             ojo1.x=pt1.x+ ancho*0.3;
             ojo1.y=pt1.y+alto*0.4;
             ojo2.x=pt1.x+ ancho*0.7;
             ojo2.y=pt1.y+alto*0.4;
             cara.x=pt1.x+ancho/2;
             cara.y=pt1.y+alto/2;
             if(circ_opt==1)
                cvEllipse(img, cara,cvSize(ancho/2, (alto/2)*1.2), 0, 0, 360,CV_RGB(255, 255, 0), resolucion/10, 0, 0);

            if(rect_opt==1)
                cvRectangle( img, pt1, pt2, CV_RGB(255,0,0), 3, 8, 0 );

			if(eye_opt==1){
                cvCircle( img,ojo1,resolucion*0.3, CV_RGB(255,255,255), -1, 8,0);
                cvCircle( img,ojo2,resolucion*0.3, CV_RGB(255,255,255), -1, 8,0);
                cvCircle( img,ojo1,resolucion*0.12, CV_RGB(255,0,0), -1, 8,0);
                cvCircle( img,ojo2,resolucion*0.12, CV_RGB(255,0,0), -1, 8,0);
          s = cvGet2D(img, ojo5,ojo6);

          printf("\n Pixel ( ancho,alto ) : (B=%.0f; G=%.0f; R=%.0f)",s.val[0], s.val[1], s.val[2]);



			}
            if(cejas_opt==1){
                    cvEllipse(img, ojo1,cvSize(resolucion/2, resolucion/2), 45, 0, 90,CV_RGB(60, 40,20), resolucion/8, 0, 0);
                    cvEllipse(img, ojo2,cvSize(resolucion/2, resolucion/2), 45, 0, 90,CV_RGB(60, 40, 20), resolucion/8, 0, 0);
                  }
            if(boca_opt==1){
                boca1.x=pt1.x+ancho*0.5;
                boca1.y=pt1.y+alto;
                boca2.x=pt1.x+ancho*0.5;
                boca2.y=pt1.y+alto*0.60;
                cvEllipse(img, boca1,cvSize(resolucion, resolucion), 45, 10, 80,CV_RGB(255, 0, 0), resolucion/6, 0, 0);
                cvEllipse(img, boca2,cvSize(resolucion, resolucion), 225, 10,80,CV_RGB(255, 0, 0), resolucion/6, 0, 0);
                  }
             else if(boca2_opt==1){
                boca1.x=pt1.x+ancho*0.5;
                boca1.y=pt1.y+alto;
                boca2.x=pt1.x+ancho*0.5;
                boca2.y=pt1.y+alto*0.55;
                cvEllipse(img, boca1,cvSize(resolucion, resolucion), 45, 10, 80,CV_RGB(255, 0, 0), resolucion/6, 0, 0);
                cvEllipse(img, boca2,cvSize(resolucion*1.2, resolucion*1.2), 225, 10,80,CV_RGB(255, 0, 0), resolucion/4, 0, 0);
                  }
            if(bigote_opt==1){
                bigote1.x=pt1.x+ancho*0.41;
                bigote1.y=pt1.y+alto*0.67;
                bigote2.x=pt1.x+ancho*0.59;
                bigote2.y=pt1.y+alto*0.722;
                cvRectangle(img, bigote1, bigote2, CV_RGB(0, 0, 0), -1, 8, 0);
                }
            if(nariz_opt==1){
                nariz1.x=pt1.x+ancho*0.45;
                nariz1.y=pt1.y+alto*0.4;
                nariz2.x=pt1.x+ancho*0.55;
                nariz2.y=pt1.y+alto*0.62;
                cvRectangle(img, nariz1, nariz2, CV_RGB(0, 0, 0), -1, 8, 0);

            }
        }
    }

    // Show the image in the window named "result"
    cvShowImage( "result", img );

    // Release the temp image created.
    cvReleaseImage( &temp );
}
