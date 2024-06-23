#include <iostream>
#include "IImageReader.h"
#include "PPMImageReader.h"
#include "PPMImageWriter.h"
#include "NegativeTransform.h"
#include "DesaturateTransform.h"
#include "ClockwiseRotationTransform.h"
#include "SubclassPtr.hpp"
#include "Session.h"
#include "Vector.hpp"
#include "String.h"
#include "TransformFactory.h"

int main()
{
	bool isAppRunning = true;
	Vector<Session> sessions;
	int currentSession = 0;
	SubclassPtr<IImageReader> reader = SubclassPtr<IImageReader>(new PPMImageReader());
	while (isAppRunning)
	{
		String command;
		std::cin >> command;
		if (command == "load")
		{
			Session session;
			sessions.pushBack(std::move(session));
			String imagePath;
			std::cin >> imagePath;
			sessions[currentSession++].addImage(reader->readImage(imagePath.c_str()));
			std::cout << "Session with ID: " << currentSession << " started" << std::endl;
		}
		else if (command == "exit")
		{
			isAppRunning = false;
		}
		else if (command == "add")
		{
			String imagePath;
			std::cin >> imagePath;
			sessions[0].addImage(reader->readImage(imagePath.c_str()));
		}
		else if (TransformFactory::isTransformName(command))
		{
			sessions[currentSession - 1].addTransform(TransformFactory::createTransform(command));
		}
		else if (command == "undo")
		{
			sessions[0].popTransform();
		}
	}
	PPMImageWriter writer;
	sessions[0].transformImages();
	writer.writeImage("testResult.ppm", sessions[0].getImage(0));

    return 0;
}