// Copyright (c) 2020 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
#include <vector>
#include <include/paddleocr.h>

using namespace PaddleOCR;

int main(int argc, char **argv)
{
    std::string image = "/home/heygears/Desktop/1.png";
    cv::Mat img = cv::imread(image, cv::IMREAD_COLOR);
    if (!img.data)
    {
        return 0;
    }
    PPOCR ocr = PPOCR();
    std::vector<cv::Mat> img_list{img};
    std::vector<std::vector<OCRPredictResult>> ocr_results = ocr.ocr(img_list, true, true, true);
    for(auto &r : ocr_results)
    {
//        for(auto &rr : r){
//            std::cout << rr.text << " " << rr.score << std::endl;
//        }
        Utility::print_result(r);
    }
    return 0;
}
