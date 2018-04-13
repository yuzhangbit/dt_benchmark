/* Copyright (c) 2018, Yu Zhang, Intelligent Vehicle Research Center(IVRC),
 * Beijing Institute of Technology.
 * All rights reserved.
 *        Files: dt_benchmark.cpp
 *   Created on: 04, 13, 2018
 *       Author: Yu Zhang
 *        Email: yu.zhang.bit@gmail.com
 */

#include <benchmark/benchmark.h>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

// 2d distance transform benchmark
static void DistanceTransform(benchmark::State& state) {
    // binary grid map
    static cv::Mat binary_map(800, 800, CV_8UC1);
    cv::randu(binary_map, 0, 255);
    unsigned char threshold = 127;
    unsigned char binary_MAX = 1;
    cv::threshold(binary_map, binary_map, threshold, binary_MAX, 0);
    // clearance grid map
    cv::Mat clearance_map;
    for (auto _ : state) {
        // distance transform
        cv::distanceTransform(binary_map, clearance_map, CV_DIST_L2, CV_DIST_MASK_PRECISE);
    }
}
BENCHMARK(DistanceTransform)->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();
