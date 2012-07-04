
/**
 * libemulation
 * Apple 5.25" Disk Drive
 * (C) 2010-2012 by Marc S. Ressl (mressl@umich.edu)
 * Released under the GPL
 *
 * Controls an Apple 5.25" Disk Drive
 */

#include "OEComponent.h"

#include "DeviceInterface.h"

#include "OESound.h"

#include "diskimage.h"

class AppleDiskDrive525 : public OEComponent
{
public:
	AppleDiskDrive525();
	
	bool setValue(string name, string value);
	bool getValue(string name, string& value);
	bool setRef(string name, OEComponent *ref);
	bool init();
	void update();
    
	bool postMessage(OEComponent *sender, int message, void *data);
	
    OEChar read(OEAddress address);
    void write(OEAddress address, OEChar value);
    
private:
	OEComponent *device;
    OEComponent *drivePlayer;
    OEComponent *headPlayer;
    
	string diskImagePath;
	bool forceWriteProtected;
    string mechanism;
    map<string, OESound>sound;
    
    OEInt phaseControl;
    OESInt trackIndex;
    
    DIApple525DiskStorage diskStorage;
    
    DIData track;
    OEChar *trackData;
    OEInt trackDataSize;
    OEInt trackDataIndex;
    
    void updateSound();
    void setPhaseControl(OEInt value);
    void updateStepper(OESInt& position, OEInt phaseControl);
    
    bool openDiskImage(string path);
    bool closeDiskImage();
    
    void updateTrack();
};