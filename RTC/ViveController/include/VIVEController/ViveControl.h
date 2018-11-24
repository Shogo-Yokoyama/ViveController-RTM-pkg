
#ifndef VIVECONTROL_H_
#define VIVECONTROL_H_

#include <openvr.h>
#include <iostream>

//#include <opencv2\opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include<glew.h>
#include<glfw3.h>


typedef struct{
	vr::HmdVector3_t position;
	vr::HmdQuaternion_t rotation;
	vr::HmdVector3_t velocity;
	vr::HmdVector3_t angularVelocity;
}ViveDeviceData;

typedef struct{
	ViveDeviceData pose;
	bool gripButton;
	bool applicationMenuButton;
	bool systemButton;
	float trigger;
	float padx;
	float pady;
}ControllerData;


class Vive
{
public:

	int initOpenGL(cv::Mat image);
	void render(cv::Mat image, ViveDeviceData* hmd, ControllerData* controller, ViveDeviceData* tracker);
	void finish();

	/*
	*	コンストラクタ
	*	引数：なし
	*	返り値：なし
	*/
	Vive();

	/*
	*	Viveの初期化
	*	引数：なし
	*	返り値：なし
	*/
	void openVive();

	/*
	*	Viveの終了
	*	引数：なし
	*	返り値：なし
	*/
	void closeVive();

	void countupConnectedDeviceNum();

	int returnNumHmd(){ return numHmd; }
	int returnNumController(){ return numController; }
	int returnNumTracker(){ return numTracker; }

	/*
	*	全てのデバイスのデータの取得
	*	引数：接続されている全てのデバイスのデータ
	*	返り値：なし
	*/
	void getAllViveData(ViveDeviceData* hmd, ControllerData* controller, ViveDeviceData* tracker);

	/*
	*	イベントの確認
	*	引数：なし
	*	返り値：なし
	*/
	void checkEvent();

private:
	vr::IVRSystem *m_pHMD;

	//接続されているVIVEデバイスの個数
	vr::TrackedDeviceIndex_t numDevice;
	int numHmd;
	int numController;
	int numTracker;

	//コントローラのボタン・パッド・トリガーの状態の格納
	vr::VRControllerState_t controllerState;

	//VIVEデバイスの位置姿勢・速度の格納
	vr::TrackedDevicePose_t* trackedDevicePose;


	/*
	*	位置ベクトルの取得
	*	引数：行列
	*	返り値：なし
	*/
	vr::HmdVector3_t getPosition(vr::HmdMatrix34_t matrix);

	/*
	*	回転クオーテーションの取得
	*	引数：行列
	*	返り値：なし
	*/
	vr::HmdQuaternion_t getRotation(vr::HmdMatrix34_t matrix);


	GLFWwindow* window;
	GLuint g_texID;
	uint32_t m_nRenderWidth, m_nRenderHeight;
};

#endif VIVECONTROL_H_ 