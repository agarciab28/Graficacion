#include<opencv2/core/core.hpp>
#include<opencv2/ml/ml.hpp>
#include<opencv/cv.h>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
	{
		VideoCapture cam(0);
		Mat matriz_patito;
		if(!cam.isOpened())  {return -1; }
			for(;;)
				{
					cam >> matriz_patito;
					imshow("Pasillo1",matriz_patito);
						if(waitKey(30)>0)
						break;
				}
	return 1;
	}
