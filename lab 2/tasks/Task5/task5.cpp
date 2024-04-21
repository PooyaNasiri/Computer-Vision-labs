#include "headers.h"
#include "plot_histogram.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "The Image file name should be provided.\n";
        return 0;
    }
    cv::Mat img = cv::imread(argv[1]);
    if (img.data == NULL)
    {
        std::cout << "Could not read the image file.\n";
        return 0;
    }
    cv::namedWindow("Image");
    cv::imshow("Image", img);
    cv::Mat gray_img;
    cv::cvtColor(img, gray_img, cv::COLOR_BGR2GRAY);
    int bins;
    std::cout << "Enter the bins for histogram: ";
    std::cin >> bins;
    plot_histogram(gray_img, bins);
    cv::waitKey(0);
    return 0;
}