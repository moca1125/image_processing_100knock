// 2024/04/04
// 自力AC

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, const char *argv[])
{

    if (argc != 2)
    {
        cout << "usage" << endl;
    }

    Mat im_in = imread(argv[1], 1);
    if (!im_in.data)
    {
        cout << "No image data" << endl;
        return -1;
    }
    Mat im_out = im_in.clone();
    int j_height = im_in.rows;
    int i_width = im_in.cols;
    int size = j_height * i_width;
    for (int j = 0; j < j_height; j++)
    {
        for (int i = 0; i < i_width; i++)
        {
            im_out.at<Vec3b>(j, i)[0] = im_in.at<Vec3b>(j, i)[2];
            im_out.at<Vec3b>(j, i)[1] = im_in.at<Vec3b>(j, i)[1];
            im_out.at<Vec3b>(j, i)[2] = im_in.at<Vec3b>(j, i)[0];
        }
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    cv::imshow("Display Image", im_out);
    cv::waitKey(0);

    cv::destroyAllWindows();
    // save image
    cv::imwrite("../output/1.bmp", im_out);

    return 0;
}