#include <opencv2/opencv.hpp>

#ifndef MONOCULAR_CALIBRATION_CAMERACALIBRATION_H
#define MONOCULAR_CALIBRATION_CAMERACALIBRATION_H

using namespace std;

class CameraCalibration {
private:

    vector<string> file_names;
    int board_width, board_height;
    cv::Size board_size;
    int board_num;
    cv::Size image_size;

    vector<vector<cv::Point2f> > image_points;
    vector<vector<cv::Point3f> > object_points;
    cv::Mat intrinsic_matrix, dist_coeffs;
    vector<cv::Mat> rvecs, tvecs;
public:

    CameraCalibration(int board_w, int board_h, string &file_path);

    void LoadImages();

    void Calibrate();

    void Dedestrotion();

};


#endif //MONOCULAR_CALIBRATION_CAMERACALIBRATION_H
