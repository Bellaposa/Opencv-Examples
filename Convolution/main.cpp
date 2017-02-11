#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

/*
filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
The arguments denote:

src: Source image
dst: Destination image
ddepth: The depth of dst. A negative value (such as -1) indicates that the depth is the same as the source.
kernel: The kernel to be scanned through the image
anchor: The position of the anchor relative to its kernel. The location Point(-1, -1) indicates the center by default.
delta: A value to be added to each pixel during the convolution. By default it is 0
BORDER_DEFAULT: We let this value by default (more details in the following tutorial)



*/
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc, char const *argv[]) {
  /* code */
  Mat mat = imread(argv[1],1);
  int kernel_size ;
  Mat dest,kernel;
  double delta;
  int depth;
  kernel = Mat::ones(1,1, CV_32F);
  if(!mat.data){
    printf("Error reading image");
    return -1;
  }
  namedWindow("Convolution", CV_WINDOW_AUTOSIZE);
  Point ancor = Point(-1,-1);//image center position

filter2D(mat,dest,-1,kernel,ancor,0,BORDER_DEFAULT);
imshow("ConvolutionResult", dest);

  waitKey(0);
  return 0;
}
