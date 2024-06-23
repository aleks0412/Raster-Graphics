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
		else if (command == "grayscale")
		{
			SubclassPtr<ITransform> desaturateTransform(new DesaturateTransform());
			sessions[0].addTransform(std::move(desaturateTransform));
		}
		else if (command == "negative")
		{
			SubclassPtr<ITransform> negativeTransform(new NegativeTransform());
			sessions[0].addTransform(std::move(negativeTransform));
		}
		else if (command == "clockwise")
		{
			SubclassPtr<ITransform> clockwiseRotationTransform(new ClockwiseRotationTransform());
			sessions[0].addTransform(std::move(clockwiseRotationTransform));
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