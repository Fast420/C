#include "client.h"

void control(const InputPacket* inpack, OutputPacket* outpack)
{
	outpack -> accelaration = 100;
	//outpack -> steering = 2;
}
