/******************************************************************************
 * Author:       Franziska Krüger
 * Requirements: OpenCV 3
 *
 * Description:
 * ------------
 * 
 * 
 ******************************************************************************
 */

#ifndef EDGE_MAP_H
#define EDGE_MAP_H

#include <array>
#include <opencv2/opencv.hpp>


namespace DepthAwareDeblurring {

    /**
     * Creates a more robust gradient. First, the image will be filtered
     * with a bilateral and shock filter to reduce blur. After that, the
     * gradients in x- and y-direction will be calculated.
     */
    void gradientMaps(const cv::Mat& image, std::array<cv::Mat,2>& gradients);

    /**
     * Selectes salient edges from a gradient image.
     * 
     * @param image Source image for which the edge map should be constructed
     * @param map   Edge map of the input image
     */
    void thresholdGradients(const std::array<cv::Mat,2>& gradients,
                            std::array<cv::Mat,2>& maps, const int psfWidth,
                            const cv::InputArray& mask = cv::noArray());


}

#endif