#include <stdio.h>
#include <stdlib.h>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;

int  main(int argc, char const *argv[]) {
  /* code */
    //grayscale image
  Mat img = imread(argv[1],1);

if(!img.data){
  printf ("ERROR LOADING IMAGE");
  return -1;
}
GaussianBlur(img,img,Size(3,3),0,0,BORDER_DEFAULT);


imshow("GAUSSIAN BLUR",img);



waitKey(0);
  return 0 ;
}
