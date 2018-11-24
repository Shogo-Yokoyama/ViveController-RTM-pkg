#include"ViveControl.h"

Vive::Vive()
{
	m_pHMD = NULL;

	numDevice = 0;
	numHmd = 0;
	numController = 0;
	numTracker = 0;
}

/*
*	VIVEの初期化
*	引数：なし
*	返り値：なし
*/
void Vive::openVive()
{
	vr::EVRInitError error = vr::VRInitError_None;
	m_pHMD = vr::VR_Init(&error, vr::VRApplication_Scene);

	if (error)
	{
		m_pHMD = NULL;
		printf_s("Unable to init VR system\n");
	}
}

int Vive::initOpenGL(cv::Mat image)
{
	if (!glfwInit())
	{
		std::cout << "Failed to initialize glfw" << std::endl;
		return -1;
	}

	window = glfwCreateWindow(image.cols, image.rows, "glCameraImage", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create the window" << std::endl;
		return -2;
	}

	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, image.cols, 0.0f, image.rows, -1.0f, 1.0f);

	glGenTextures(1, &g_texID);
	glBindTexture(GL_TEXTURE_2D, g_texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.cols, image.rows, 0, GL_BGR, GL_UNSIGNED_BYTE, image.data);

	static const GLfloat vtx[] = {
		0, image.rows,
		image.cols, image.rows,
		image.cols, 0,
		0, 0,
	};
	glVertexPointer(2, GL_FLOAT, 0, vtx);

	// テクスチャの領域指定
	static const GLfloat texuv[] = {
		0.0f, 1.0f,
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
	};
	glTexCoordPointer(2, GL_FLOAT, 0, texuv);

	/*vr::IVRSystem *m_pHMD = NULL;
	vr::EVRInitError error = vr::VRInitError_None;
	m_pHMD = vr::VR_Init(&error, vr::VRApplication_Scene);

	if (error)
	{
	m_pHMD = NULL;
	printf_s("Unable to init VR system\n");
	}*/

	return 0;

}

/*
*	VIVEの終了
*	引数：なし
*	返り値：なし
*/
void Vive::closeVive()
{
	if (m_pHMD != NULL)
	{
		vr::VR_Shutdown();
		//glfwTerminate();
		m_pHMD = NULL;
	}
}

void Vive::countupConnectedDeviceNum()
{
	//接続されているデバイス数のカウント
	while (m_pHMD->IsTrackedDeviceConnected(numDevice))
	{
		switch (m_pHMD->GetTrackedDeviceClass(numDevice))
		{
		case vr::TrackedDeviceClass_HMD:
			numHmd++;
			break;
		case vr::TrackedDeviceClass_Controller:
			numController++;
			break;
		case vr::TrackedDeviceClass_GenericTracker:
			numTracker++;
			break;
		}

		numDevice++;
	}

	//std::cout << numDevice << "/" << numHmd << "/" << numController << "/" << numTracker << std::endl;
}

/*
*	コントローラの情報の取得
*	引数：HMDの位置姿勢/コントローラの位置姿勢・ボタン・パッド・トリガー/トラッカーの位置姿勢
*	返り値：なし
*/
void Vive::getAllViveData(ViveDeviceData* hmd, ControllerData* controller, ViveDeviceData* tracker)
{
	//hmd->deviceNum = numHmd;

	trackedDevicePose = new vr::TrackedDevicePose_t[numDevice];
	m_pHMD->GetDeviceToAbsoluteTrackingPose(vr::TrackingUniverseStanding, 0, trackedDevicePose, numDevice);

	for (vr::TrackedDeviceIndex_t deviceIndex = 0; deviceIndex < numDevice; deviceIndex++)
	{
		switch (m_pHMD->GetTrackedDeviceClass(deviceIndex))
		{
		case vr::TrackedDeviceClass_HMD:
			hmd->position = getPosition(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			//printf_s("%d   x:%.2f    y:%.2f    z:%.2f\n", deviceIndex, hmd->position.v[0], hmd->position.v[1], hmd->position.v[2]);
			hmd->rotation = getRotation(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			hmd->velocity = trackedDevicePose[deviceIndex].vVelocity;
			hmd->angularVelocity = trackedDevicePose[deviceIndex].vAngularVelocity;

			hmd++;
			break;

		case vr::TrackedDeviceClass_Controller:
			controller->pose.position = getPosition(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			//printf_s("%d   x:%.2f    y:%.2f    z:%.2f    ", deviceIndex, controller->pose.position.v[0], controller->pose.position.v[1], controller->pose.position.v[2]);
			controller->pose.rotation = getRotation(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			controller->pose.velocity = trackedDevicePose[deviceIndex].vVelocity;
			controller->pose.angularVelocity = trackedDevicePose[deviceIndex].vAngularVelocity;

			m_pHMD->GetControllerState(deviceIndex, &controllerState, sizeof(controllerState));
			controller->trigger = controllerState.rAxis[vr::k_eHiddenAreaMesh_Inverse].x;
			controller->padx = controllerState.rAxis[vr::k_eHiddenAreaMesh_Standard].x;
			controller->pady = controllerState.rAxis[vr::k_eHiddenAreaMesh_Standard].y;
			//printf_s("%d   trigger:%.2f    padx:%.2f    pady:%.2f\n", deviceIndex, controller->trigger, controller->pad.x, controller->pad.y);

			//ボタンのON/OFFの判断
			if (controllerState.ulButtonPressed)
			{
				if (controllerState.ulButtonPressed & vr::ButtonMaskFromId(vr::k_EButton_System))
				{
					// システムボタンを識別できない
					controller->systemButton = true;
					//std::cout << deviceIndex << ":Pressed System Button" << std::endl;
				}
				if (controllerState.ulButtonPressed & vr::ButtonMaskFromId(vr::k_EButton_ApplicationMenu))
				{
					controller->applicationMenuButton = true;
					//std::cout << deviceIndex << ":Pressed Application Button" << std::endl;
				}
				if (controllerState.ulButtonPressed & vr::ButtonMaskFromId(vr::k_EButton_Grip))
				{
					controller->gripButton = true;
					//std::cout << deviceIndex << ":Pressed Grip Button" << std::endl;
				}
			}
			else
			{
				controller->systemButton = false;
				controller->applicationMenuButton = false;
				controller->gripButton = false;
			}

			controller++;
			break;

		case vr::TrackedDeviceClass_GenericTracker:
			//std::cout << "Tracler" << std::endl;

			tracker->position = getPosition(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			//printf_s("%d   x:%.2f    y:%.2f    z:%.2f\n", deviceIndex, tracker->position.v[0], tracker->position.v[1], tracker->position.v[2]);
			tracker->rotation = getRotation(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			tracker->velocity = trackedDevicePose[deviceIndex].vVelocity;
			tracker->angularVelocity = trackedDevicePose[deviceIndex].vAngularVelocity;

			tracker++;
			break;
		}
	}
}


vr::HmdVector3_t Vive::getPosition(vr::HmdMatrix34_t matrix)
{
	vr::HmdVector3_t vector;

	vector.v[0] = matrix.m[0][3];
	vector.v[1] = matrix.m[1][3];
	vector.v[2] = matrix.m[2][3];

	return vector;
}

vr::HmdQuaternion_t Vive::getRotation(vr::HmdMatrix34_t matrix) {
	vr::HmdQuaternion_t q;

	q.w = sqrt(fmax(0, 1 + matrix.m[0][0] + matrix.m[1][1] + matrix.m[2][2])) / 2;
	q.x = sqrt(fmax(0, 1 + matrix.m[0][0] - matrix.m[1][1] - matrix.m[2][2])) / 2;
	q.y = sqrt(fmax(0, 1 - matrix.m[0][0] + matrix.m[1][1] - matrix.m[2][2])) / 2;
	q.z = sqrt(fmax(0, 1 - matrix.m[0][0] - matrix.m[1][1] + matrix.m[2][2])) / 2;
	q.x = copysign(q.x, matrix.m[2][1] - matrix.m[1][2]);
	q.y = copysign(q.y, matrix.m[0][2] - matrix.m[2][0]);
	q.z = copysign(q.z, matrix.m[1][0] - matrix.m[0][1]);
	return q;
}

void Vive::render(cv::Mat image, ViveDeviceData* hmd, ControllerData* controller, ViveDeviceData* tracker)
{
	// 画面の初期化
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// テクスチャの画像指定
	glBindTexture(GL_TEXTURE_2D, g_texID);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, image.cols, image.rows, GL_BGR, GL_UNSIGNED_BYTE, image.data);

	// PC画面へのテクスチャの描画
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
	// バッファの入れ替え
	glfwSwapBuffers(window);

	// VIVE HMDへのテクスチャの出力
	vr::Texture_t leftEyeTexture = { (void*)(uintptr_t)g_texID, vr::TextureType_OpenGL, vr::ColorSpace_Gamma };
	vr::VRCompositor()->Submit(vr::Eye_Left, &leftEyeTexture);
	vr::Texture_t rightEyeTexture = { (void*)(uintptr_t)g_texID, vr::TextureType_OpenGL, vr::ColorSpace_Gamma };
	vr::VRCompositor()->Submit(vr::Eye_Right, &rightEyeTexture);
	
	// 待機
	trackedDevicePose = new vr::TrackedDevicePose_t[numDevice];
	vr::VRCompositor()->WaitGetPoses(trackedDevicePose, numDevice, NULL, 0);

	for (vr::TrackedDeviceIndex_t deviceIndex = 0; deviceIndex < numDevice; deviceIndex++)
	{
		switch (m_pHMD->GetTrackedDeviceClass(deviceIndex))
		{
		case vr::TrackedDeviceClass_HMD:
			hmd->position = getPosition(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			//printf_s("%d   x:%.2f    y:%.2f    z:%.2f\n", deviceIndex, hmd->position.v[0], hmd->position.v[1], hmd->position.v[2]);
			hmd->rotation = getRotation(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			hmd->velocity = trackedDevicePose[deviceIndex].vVelocity;
			hmd->angularVelocity = trackedDevicePose[deviceIndex].vAngularVelocity;

			hmd++;
			break;

		case vr::TrackedDeviceClass_Controller:
			controller->pose.position = getPosition(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			//printf_s("%d   x:%.2f    y:%.2f    z:%.2f    ", deviceIndex, controller->pose.position.v[0], controller->pose.position.v[1], controller->pose.position.v[2]);
			controller->pose.rotation = getRotation(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			controller->pose.velocity = trackedDevicePose[deviceIndex].vVelocity;
			controller->pose.angularVelocity = trackedDevicePose[deviceIndex].vAngularVelocity;

			m_pHMD->GetControllerState(deviceIndex, &controllerState, sizeof(controllerState));
			controller->trigger = controllerState.rAxis[vr::k_eHiddenAreaMesh_Inverse].x;
			controller->padx = controllerState.rAxis[vr::k_eHiddenAreaMesh_Standard].x;
			controller->pady = controllerState.rAxis[vr::k_eHiddenAreaMesh_Standard].y;
			//printf_s("%d   trigger:%.2f    padx:%.2f    pady:%.2f\n", deviceIndex, controller->trigger, controller->pad.x, controller->pad.y);

			//ボタンのON/OFFの判断
			if (controllerState.ulButtonPressed)
			{
				if (controllerState.ulButtonPressed & vr::ButtonMaskFromId(vr::k_EButton_System))
				{
					// システムボタンを識別できない
					controller->systemButton = true;
					//std::cout << deviceIndex << ":Pressed System Button" << std::endl;
				}
				if (controllerState.ulButtonPressed & vr::ButtonMaskFromId(vr::k_EButton_ApplicationMenu))
				{
					controller->applicationMenuButton = true;
					//std::cout << deviceIndex << ":Pressed Application Button" << std::endl;
				}
				if (controllerState.ulButtonPressed & vr::ButtonMaskFromId(vr::k_EButton_Grip))
				{
					controller->gripButton = true;
					//std::cout << deviceIndex << ":Pressed Grip Button" << std::endl;
				}
			}
			else
			{
				controller->systemButton = false;
				controller->applicationMenuButton = false;
				controller->gripButton = false;
			}

			controller++;
			break;

		case vr::TrackedDeviceClass_GenericTracker:
			//std::cout << "Tracler" << std::endl;

			tracker->position = getPosition(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			//printf_s("%d   x:%.2f    y:%.2f    z:%.2f\n", deviceIndex, tracker->position.v[0], tracker->position.v[1], tracker->position.v[2]);
			tracker->rotation = getRotation(trackedDevicePose[deviceIndex].mDeviceToAbsoluteTracking);
			tracker->velocity = trackedDevicePose[deviceIndex].vVelocity;
			tracker->angularVelocity = trackedDevicePose[deviceIndex].vAngularVelocity;

			tracker++;
			break;
		}
	}
}

void Vive::checkEvent()
{
	vr::VREvent_t event;

	if (m_pHMD->PollNextEvent(&event, sizeof(event)))
	{
		switch (event.eventType)
		{
			/*case vr::VREvent_ButtonTouch:
			std::cout << "Button Touched" << std::endl;
			break;*/
		case vr::VREvent_ButtonPress:
			std::cout << "Button Pressed" << std::endl;

			std::cout << "DeviceIndex:" << event.trackedDeviceIndex
				<< "	EventAgeSeconds:" << event.eventAgeSeconds
				<< "	Data:" << event.data.controller.button << std::endl;

			if (ButtonMaskFromId(vr::k_EButton_ApplicationMenu)&event.data.controller.button)
			{
				std::cout << "Application Button Pressed" << std::endl;
			}
			if (ButtonMaskFromId(vr::k_EButton_Grip)&event.data.controller.button)
			{
				std::cout << "Grip Button Pressed" << std::endl;
			}
			if (ButtonMaskFromId(vr::k_EButton_Axis0)&event.data.controller.button)
			{
				std::cout << "Axis0" << std::endl;
			}

			break;
		case vr::VREvent_TouchPadMove:
			std::cout << "TOUCH_PAD_MOVE" << std::endl;
			break;
		case vr::VREvent_MouseMove:
			std::cout << "MOUSE_MOVE" << std::endl;
			break;
		}
	}
}