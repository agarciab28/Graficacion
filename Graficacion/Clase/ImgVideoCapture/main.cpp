#include "opencv2/opencv.hpp"

  //g++ -Wall %f -o %n `pkg-config --cflags --libs opencv`
  using namespace std;
  using namespace cv;

int main() {

  VideoCapture cap(0);
  if(!cap.isOpened()){
    return -1;
  }

  Mat frames;
  Mat img = imread("lunala.jpg");

  for(;;){
      cap >> frames;
      flip(frames, frames, 1);
      img.copyTo(frames(Rect(50, 200, img.cols, img.rows)));
      imshow("frames", frames);

      if(waitKey(30) >= 0){
        break;
      }
  }

  return 0;
}
