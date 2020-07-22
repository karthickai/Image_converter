#include <iostream>
#include <filesystem>
#include <string>
#include "opencv2/opencv.hpp"

bool check_image_is_valid(const std::string& image_path, const std::string& output){

    cv::Mat image = cv::imread(image_path);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        std::cout <<  "Could not open or find the image" << std::endl ;
        std::cout << image_path << std::endl;
        return false;
    }
    try {
        cv::resize(image, image, cv::Size(224, 224));

        cv::imwrite(output, image);
    } catch (...) {
        std::cout <<  "Could not write the image" << std::endl ;
        std::cout << image_path << std::endl;
        return false;
    }
    return true;

}

int main()
{
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;
    std::string input_folder = "/mnt/02766c76-96a3-408a-944b-e361bc4952dd/Karthick/Research/Forest_Fire/dataset/train/2/";
//    std::string input_folder = "/home/karthick/Desktop/image";
    std::string output_folder = "/mnt/02766c76-96a3-408a-944b-e361bc4952dd/Karthick/Research/Forest_Fire/dataset/preprocessed/train/start_fire/";

    int i = 2378;
    for (auto& p: std::filesystem::recursive_directory_iterator(input_folder)){
        std::string output = output_folder + std::to_string(i) + ".jpg";
        std::cout << output << std::endl;
        check_image_is_valid(p.path().string(), output);
        i++;
    }

}