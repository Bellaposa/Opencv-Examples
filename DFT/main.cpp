#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace std;
using namespace cv;



int   main(int argc, char const *argv[]) {


  Mat img = imread(argv[1],0);

      Mat planes[] = {Mat_<float>(img), Mat::zeros(img.size(), CV_32F)};
      Mat complexI;    //Complex plane to contain the DFT coefficients {[0]-Real,[1]-Img}
      merge(planes, 2, complexI);
      dft(complexI, complexI);  // Applying DFT
      //imshow("DFT", complexI);

      // Reconstructing original imae from the DFT coefficients
      Mat invDFT, invDFTcvt;
      idft(complexI, invDFT, DFT_SCALE | DFT_REAL_OUTPUT ); // Applying IDFT
      invDFT.convertTo(invDFTcvt, CV_8U);
      imshow("Output", invDFTcvt);

      //show the image
      imshow("Original Image", img);

      // Wait until user press some key
      waitKey(0);
      return 0;
}
