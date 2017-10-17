#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

//g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`

int main(int argc, char const *argv[]) {
  //int sumAngulo = 0;
  VideoCapture cap(0);
  if(!cap.isOpened()){
    return -1;
  }

  //Mat edges;
  Mat frames;

  for(;;){
    cap >> frames;
    flip(frames, frames, 1);
    //ellipse(frames, Point(500, 200), Size(100, 200), 90 + sumAngulo, 1, 360, Scalar(0, 0, 0), -1, 8);
    line(frames, Point(630, 100), Point(630, 150), Scalar(0, 0, 0), 1, 8, 0);
    imshow("frames", frames);
    if(waitKey(30) >= 0){
      break;
    }
    sumAngulo += 10;

    cout << frames.rows << "  " << frames.cols << endl;
  }

  return 0;
}
