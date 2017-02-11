/*
**
*
Equalizzazione Hist


void calcHist(const Mat* images, int nimages, const int* channels,
              InputArray mask, OutputArray hist, int dims,
              const int* histSize, const float** ranges,
              bool uniform=true, bool accumulate=false )


              void equalizeHist(InputArray src, OutputArray dst)


*/

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  //Load 2 images
  Mat src1 = imread("im1.jpg",1);
  Mat src2 ;//destination Matrix
  //Load i
  if( !src1.data ){
    return -1;
  }

  //convert to grayscale

  cvtColor(src1,src1,CV_BGR2GRAY);

  //equalize histogram
  equalizeHist(src1,src2);
  namedWindow("SourceImage",CV_WINDOW_AUTOSIZE);
  namedWindow("EqualizedImage", CV_WINDOW_AUTOSIZE);
  imshow("SourceImage", src1);
  imshow("EqualizedImage", src2);

  waitKey(0);

  return 0 ;

}
