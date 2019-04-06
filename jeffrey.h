#ifndef JEFFREY_H_
#define JEFFREY_H_

#include "MyRio.h"
#include "Ultrasonic.h"

#include "opencv2/core.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/operations.hpp"


	#define HAND_LEFT 0
	#define HAND_CENTER 0
	#define HAND_RIGHT 0


	#define HAND_OPEN 180
	#define HAND_CLOSED 0
	#define WEIGHT_FRONT 0
	#define WEIGHT_BACK 170
	#define DEFAULT_CAMERA 0

class Jeffrey {
private:
	Motor_Controller mc;
    Ultrasonic ultrasonic;

	/*
	 * The number of degree to turn the (4" / 31.9cm) wheel forward one centimenter
	 *  Formula used : 360/31.918581360472
	 */
	static constexpr double WHEEL_DEGREE_CM = 11.2786968;



public:
    Jeffrey();
    ~Jeffrey();
    NiFpga_Status init(NiFpga_Session* myrio_session);
    void reset();

	void moveForwardCM(int cm, int speed);
	int alignWithWall(int speed, float calib);
	int servo();

	void moveToDistanceForward(int speed, float distance);
	void moveToDistanceBackward(int speed, float distance);
	void moveHandToBlock();
	void openHand();
	void closeHand();
	void weightFront();
	void weightBack();
	void rotate180dregees();
	void detectQRCode();
	int scanQRCode(cv::Mat display, cv::Mat pts);

};

#endif
