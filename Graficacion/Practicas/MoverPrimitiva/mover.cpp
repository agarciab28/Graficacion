#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv` -lglut -lGL -lGLU

#include <iostream>

using namespace cv;
using namespace std;

float a = 200;
float b = 200;

static void drawOptFlowMap(const Mat& flow, Mat& cflowmap, int step,
			   double, const Scalar& color){

    rectangle(cflowmap, Point(a, b), Point(a + 100, b +100), Scalar(22, 25, 223), -1, 8);


  for(int y = 0; y < 100; y += step)
    for(int x = 0; x < 100; x += step){
        const Point2f& fxy = flow.at<Point2f>(y, x);
        //Esquina superior izq
	      circle(cflowmap, Point(cvRound(x+fxy.x), cvRound(y+fxy.y)), 2, color, -1);
	      line(cflowmap, Point(x,y - step), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
	      line(cflowmap, Point(x - step,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
        if(fxy.x > 2 || fxy.y > 2){
            // cout  << fxy << endl;
            // putText(cflowmap, "Esquina superior izquierda", Point(100, 170), FONT_HERSHEY_TRIPLEX, 1, Scalar(112, 10, 98), 2, 8);
            a = a - 0.1;
            b = b - 0.1;
            rectangle(cflowmap, Point(a, b), Point(a + 100, b +100), Scalar(22, 25, 223), -1, 8);
        }
      }

      //Esquina inferior izq
      for(int y = cflowmap.rows - 100; y < cflowmap.rows; y += step)
        for(int x = 0; x < 100; x += step){
            const Point2f& fxy = flow.at<Point2f>(y, x);
    	      circle(cflowmap, Point(cvRound(x+fxy.x), cvRound(y+fxy.y)), 2, color, -1);
    	      line(cflowmap, Point(x,y - step), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
    	      line(cflowmap, Point(x - step,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
            if(fxy.x > 2 || fxy.y > 2){
                // cout  << fxy << endl;
                // putText(cflowmap, "Esquina inferior izquierda", Point(100, 200), FONT_HERSHEY_TRIPLEX, 1, Scalar(112, 10, 98), 2, 8);
                a = a - 0.1;
                b = b + 0.1;
                rectangle(cflowmap, Point(a, b), Point(a + 100, b + 100), Scalar(22, 25, 223), -1, 8);
            }
          }

          //Esquina superior der
          for(int y = 0; y < 100; y += step)
            for(int x = cflowmap.cols - 100; x < cflowmap.cols; x += step){
                const Point2f& fxy = flow.at<Point2f>(y, x);
        	      circle(cflowmap, Point(cvRound(x+fxy.x), cvRound(y+fxy.y)), 2, color, -1);
        	      line(cflowmap, Point(x,y - step), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
        	      line(cflowmap, Point(x - step,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
                if(fxy.x > 2 || fxy.y > 2){
                    // cout  << fxy << endl;
                    // putText(cflowmap, "Esquina superior derecha", Point(100, 230), FONT_HERSHEY_TRIPLEX, 1, Scalar(112, 10, 98), 2, 8);
                    a = a + 0.1;
                    b = b - 0.1;
                    rectangle(cflowmap, Point(a, b), Point(a + 100, b + 100), Scalar(22, 25, 223), -1, 8);
                }
              }

              //Esquina inferior der
              for(int y = cflowmap.rows - 100; y < cflowmap.rows; y += step)
                for(int x = cflowmap.cols - 100; x < cflowmap.cols; x += step){
                    const Point2f& fxy = flow.at<Point2f>(y, x);
            	      circle(cflowmap, Point(cvRound(x+fxy.x), cvRound(y+fxy.y)), 2, color, -1);
            	      line(cflowmap, Point(x,y - step), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
            	      line(cflowmap, Point(x - step,y), Point(cvRound(x+fxy.x), cvRound(y+fxy.y)),color);
                    if(fxy.x > 2 || fxy.y > 2){
                        // cout  << fxy << endl;
                        // putText(cflowmap, "Esquina inferior derecha", Point(100, 260), FONT_HERSHEY_TRIPLEX, 1, Scalar(112, 10, 98), 2, 8);
                        a = a + 0.1;
                        b = b + 0.1;
                        rectangle(cflowmap, Point(a, b), Point(a + 100, b + 100), Scalar(22, 25, 223), -1, 8);
                    }
                  }

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
            drawOptFlowMap(flow, cflow, 10, 1.5, Scalar(0, 255, 0));
            imshow("flow", cflow);
	  }
        if(waitKey(10)>=0)
	  break;
        std::swap(prevgray, gray);
      }
    return 0;
}
