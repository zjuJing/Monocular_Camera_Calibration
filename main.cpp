#include <iostream>
#include "CameraCalibration.h"

using namespace std;

int main(int argc, char **argv) {
    const string keys =
            "{file_path||directory for store images}"
            "{board_width|6|width of board}"
            "{board_height|9|height of board}"
            "{undistortion_flag flag||whether do undistort}";
    cv::CommandLineParser parser = cv::CommandLineParser(argc, argv, keys);
    if (argc < 4) {
        cout << "----- Calibrate a camera -----\n"
             << "Call:\ncamera_calibration.exe {file_path} {board_width} {board_height} {undistortion_flag}\n"
             << "Example:\ncamera_calibration.exe -file_path=./left 6 9 -flag=1" << endl;
        return -1;
    }
    bool undistortion_flag = parser.get<bool>("undistortion_flag");
    int board_width = parser.get<int>("board_width");
    int board_height = parser.get<int>("board_height");
    string file_path = parser.get<string>("file_path");
    CameraCalibration cameraCalibration(board_width, board_height, file_path);
    cameraCalibration.Calibrate();
    if (undistortion_flag) {
        cameraCalibration.Dedestrotion();
    }
    return 0;
}
