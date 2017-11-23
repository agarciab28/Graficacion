#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv` -lglut -lGL -lGLU

#include <iostream>

using namespace cv;
using namespace std;

float y = 200;
float x = 200;

static void drawOptFlowMap(const Mat& flow, Mat& cflowmap, int step,
			   double, const Scalar& color){
           //int x = 200, y = 200;
           const Point2f& fxy = flow.at<Point2f>(y, x);
           circle(cflowmap, Point(cvRound(x+fxy.x),cvRound(y+fxy.y)), 30, color, -1);
           cout << fxy << endl;

           if(fxy.x < -2){
             x = x - step;
           }

           if(fxy.x > 3){
             x = x + step;
           }

           if(fxy.y < -2){
             y = y - step;
           }

           if(fxy.y > 3){
             y = y + step;
           }



  // for(int y = 0; y < 100; y += step)
  //   for(int x = 0; x < 100; x += step){
  //       const Point2f& fxy = flow.at<Point2f>(y, x);
  //
  //       circle(cflowmap, Point(a + cvRound(x+fxy.x), b + cvRound(y+fxy.y)), 10, color, -1);
  //
  //       if(fxy.x > 2 || fxy.y > 2){
  //           // cout  << fxy << endl;
  //           // putText(cflowmap, "Esquina superior izquierda", Point(100, 170), FONT_HERSHEY_TRIPLEX, 1, Scalar(112, 10, 98), 2, 8);
  //           a = a - 0.1;
  //           b = b - 0.1;
  //
  //   	      line(cflowmap, Point(x,y - step), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
  //   	      line(cflowmap, Point(x - step,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
  //           rectangle(cflowmap, Point(fxy.x, fxy.y), Point(fxy.x + 100, fxy.y +100), Scalar(22, 25, 223), -1, 8);
  //       }
  //     }
}


int main(int, char**)
{
    VideoCapture cap(0);
    //help();
    if( !cap.isOpened() )
        return -1;

    Mat flow, cflow, frame;
    Mat gray, prevgray, uflow;
    namedWindow("flow", 1);

    for(;;)
      {
        cap >> frame;
        flip(frame, frame, 1);
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        if( !prevgray.empty() )
	  {
            calcOpticalFlowFarneback(prevgray, gray, uflow, 0.5, 3, 15, 3, 5, 1.2, 0);
            cvtColor(prevgray, cflow, COLOR_GRAY2BGR);
            uflow.copyTo(flow);
            drawOptFlowMap(flow, cflow, 16, 1.5, Scalar(0, 255, 0));
            imshow("flow", cflow);
	  }
        if(waitKey(10)>=0)
	  break;
        std::swap(prevgray, gray);
      }
    return 0;
}
