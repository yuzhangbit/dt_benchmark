/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC), 
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: example.cpp
 *   Created on: 04, 13, 2018 
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <chrono>

int main( int argc, char **argv ) {
    static cv::Mat binary_map(800, 800, CV_8UC1);
    cv::randu(binary_map, 0, 255);
    unsigned char threshold = 127;
    unsigned char binary_MAX = 1;
    cv::threshold(binary_map, binary_map, threshold, binary_MAX, 0);
    // clearance grid map
    cv::Mat clearance_map;

    auto start = std::chrono::steady_clock::now();
    for (std::size_t i = 0; i < 10000; i++) {
        // distance transform
        cv::distanceTransform(binary_map,
                              clearance_map,
                              CV_DIST_L2,
                              CV_DIST_MASK_PRECISE);
    }
    
    auto end = std::chrono::steady_clock::now();
    std::cout << "distance tranform time:"
              << std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count()/10000.0;
}