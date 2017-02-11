#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int  main(int argc, char const *argv[]) {

  printf("CANNY EDGE DETECTOR\n");

  Mat input,
      dest,
      src_gray,
      detected_edges;


  //getting image
  input = imread(argv[1],1);
  //if empty show error
  if(!input.data){
    printf("Error opening image ");
    }
    //creating window
    namedWindow( "input", WINDOW_AUTOSIZE );
    //showing image
    imshow("IMAGE",input);
    //create image of same size
    dest.create(input.size(),input.type());

    //convert image to grayScale
    cvtColor(input,src_gray,COLOR_BGR2GRAY);

    //namedWindow("GRAYFIRST",WINDOW_AUTOSIZE);
    imshow("GRAYF",src_gray);

    //APPLICAZIONE CANNY EDGE DETECTOR

    blur(src_gray,src_gray,Size(3,3));


    //namedWindow("GRAYSECOND",WINDOW_AUTOSIZE);
    imshow("GRAYS",src_gray);


    //APPLYING CANNY!
    Canny(src_gray,detected_edges,0,100,3);

    dest = Scalar::all(0);
    input.copyTo(dest,detected_edges);
    imshow("CANNY", dest);

    //WAIT FOR USER INPUT
    waitKey(0);
  return 0;
}
