
/**
 * libemulation
 * Address decoder
 * (C) 2010 by Marc S. Ressl (mressl@umich.edu)
 * Released under the GPL
 *
 * Controls an address decoder
 */

#ifndef _ADDRESSDECODER_H
#define _ADDRESSDECODER_H

#include "OEComponent.h"

// Events
enum {
	ADDRESSDECODER_MAP,
};

typedef struct
{	
	OEComponent *component;
	
	OEUInt32 startAddress;
	OEUInt32 endAddress;
	
	bool read;
	bool write;
} AddressDecoderMap;

typedef vector<AddressDecoderMap> AddressDecoderMaps;
typedef map<string, string> AddressDecoderRangeMap;
typedef map<string, OEComponent *> AddressDecoderRefMap;

class AddressDecoder : public OEComponent
{
public:
	AddressDecoder();
	
	bool setValue(const string &name, const string &value);
	bool setComponent(const string &name, OEComponent *component);
	
	bool init();
	
	bool postEvent(OEComponent *component, int event, void *data);
	
	OEUInt8 read(int address);
	void write(int address, OEUInt8 value);
	
private:
	int addressSize;
	int blockSize;
	OEComponent *floatingBus;
	
	AddressRangeMap rangeMap;
	AddressRefMap refMap;
	
	int addressMask;
	OEComponents readMap;
	OEComponents writeMap;
	
	void initMap(OEComponent *component);
	void mapComponent(AddressDecoderMap *theMap);
	bool mapComponent(OEComponent *component, const string &value);
	
	bool getAddressDecoderMap(AddressDecoderMap &theMap, const string &value);
	bool getAddressDecoderMaps(AddressDecoderMaps &theMaps, const string &value);
};

#endif
