#include <opencv2/opencv.hpp>
#include "edges_pose_refiner/segmentedImage.hpp"
#include <omp.h>

using namespace cv;
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  omp_set_num_threads(3);
  CV_Assert(argc == 4);
  const string rgbFilename = argv[1];
  const string segmentationFilename = argv[2];
  const string outputFilename = argv[3];

  Mat testImage = imread(rgbFilename);
  CV_Assert(!testImage.empty());

  SegmentedImage segmentedImage(testImage, segmentationFilename);
  segmentedImage.write(outputFilename);

  return 0;
}