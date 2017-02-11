#include <stdio.h>
#include <stdlib.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;

int main(int argc,char * argv[]){
  //grayscale image
  Mat img = imread(argv[1],0);
  Mat grey,dst;

if(!img.data){
  printf ("ERROR LOADING IMAGE");
  return -1;
}

//REMEMBER FILTER SIZE MUST BE ODD (DISPARI)
GaussianBlur(img,img,Size(3,3),3,4,BORDER_DEFAULT);
imshow("GAUSSIAN BLUR",img);

//Convert to grayscale
cvtColor(img,grey,CV_BGR2GRAY);

/// Apply Laplace function
  Mat abs_dst;

  Laplacian( grey, dst, CV_16S, 3, 0, 0, BORDER_DEFAULT );
  convertScaleAbs( dst, abs_dst );

  /// Show what you got
  imshow( "OUTPUT", abs_dst );



waitKey(0);
  return 0 ;
}
