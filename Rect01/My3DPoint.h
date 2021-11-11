#pragma once

class My3DPoint{

private:
	double X = 0; //(1)
	double Y = 0; //(1)
	double Z = 0;
	int processParamId = 1; //(1)
	int scanFieldId = 1; //(2)
	double jumpspeed = 0, JumpDelay = 0,
		markSpeed = 0, markDelay = 0, polyDelay = 0, laserOnDelay = 0, laserOffDelay = 0,
		laserPower = 0, laserFreq = 0, laserWidth = 0;

public:
	//Getters
	double getX() const { return X; }
	double getY() const { return Y; }
	double getZ() const { return Z; }
	int getprocessParamId() const { return processParamId; }
	int getscanFieldId() const { return scanFieldId; }
	double getjumpspeed() const { return jumpspeed; }
	double getJumpDelay() const { return JumpDelay; }
	double getmarkSpeed() const { return markSpeed; }
	double getmarkDelay() const { return markDelay; }
	double getpolyDelay() const { return polyDelay; }
	double getlaserOnDelay() const { return laserOnDelay; }
	double getlaserOffDelay() const { return laserOffDelay; }
	double getlaserPower() const { return laserPower; }
	double getlaserFreq() const { return laserFreq; }
	double getlaserWidth() const { return laserWidth; }

	//setters
	void setX(double x) { X = x; }
	void setY(double y) { Y = y; }
	void setZ(double z) { Z = z; }
	void setprocessParamId(double p) { processParamId = p; }
	void setscanFieldId(double p) { scanFieldId = p; }
	void setjumpspeed(double p) { jumpspeed = p; }
	void setJumpDelay(double p) { JumpDelay = p; }
	void setmarkSpeed(double p) { markSpeed = p; }
	void setmarkDelay(double p) { markDelay = p; }
	void setpolyDelay(double p) { polyDelay = p; }
	void setlaserOnDelay(double p) { laserOnDelay = p; }
	void setlaserOffDelay(double p) { laserOffDelay = p; }
	void setlaserPower(double p) { laserPower = p; }
	void setlaserFreq(double p) { laserFreq = p; }
	void setlaserWidth(double p) { laserWidth = p; }
};