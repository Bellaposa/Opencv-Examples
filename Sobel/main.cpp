/*

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <stdio.h>

using namespace std;
using namespace cv;


/*
1) open IMAGE
2) apply blur (gaussian)
3) apply sobel kernel for x and y
4) display
5) Enjoy (:

int main(int argc, char const *argv[]) {

int scale = 1;
int delta = 0;
  Mat img = imread(argv[1]);
  Mat dest, grad_x, grad_y;
  if(!img.data){
    printf("ERROR LOADING IMAGE");
    return -1;
  }
//source , destination , kernel size , sigma x ,sigma y ,BORDER
GaussianBlur(img,img,Point(3,3),0,0,BORDER_DEFAULT);

cvtColor( img, dest, COLOR_RGB2GRAY );

imshow("GaussianBlur", dest);
Mat abs_grad_x, abs_grad_y,grad;

  // Gradient X
  Sobel( dest, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_x, abs_grad_x );

  // Gradient Y
  Sobel( dest, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_y, abs_grad_y );

  /// Total Gradient (approximate)
  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );


  waitKey(0);
  return 0;
}
*/


#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

/** @function main */
int main( int argc, char** argv ){

  Mat src, src_gray;
  Mat grad;
  char* window_name = "Sobel Demo - Simple Edge Detector";
  int scale = 1;
  int delta = 0;
  int ddepth = CV_16S;

  int c;

  /// Load an image
  src = imread( argv[1] );

  if( !src.data )
  { return -1; }

  GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );

  /// Convert it to gray
  cvtColor( src, src_gray, COLOR_RGB2GRAY );

  /// Create window
  namedWindow( window_name, WINDOW_AUTOSIZE );

  /// Generate grad_x and grad_y
  Mat grad_x, grad_y;
  Mat abs_grad_x, abs_grad_y;

  /// Gradient X
  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_x, abs_grad_x );

  /// Gradient Y
  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
  Sobel( src_gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
  convertScaleAbs( grad_y, abs_grad_y );

  /// Total Gradient (approximate)
  addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );

  imshow( window_name, grad );

  waitKey(0);

  return 0;
  }
