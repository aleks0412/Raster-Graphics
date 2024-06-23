#include "Application.h"
#include "Vector.hpp"
#include "SubclassPtr.hpp"
#include "Session.h"
#include "IImageReader.h"
#include "IImageWriter.h"
#include "PPMImageWriter.h"
#include "ImageReaderFactory.h"
#include "TransformFactory.h"
#include <iostream>
void Application::run()
{
	Vector<Session> sessions;
	int currentSession = 0;
	while (isRunning)
	{
		String command;
		std::cin >> command;
		if (command == LOAD_COMMAND)
		{
			Session session;
			sessions.pushBack(std::move(session));
			String imagePath;
			std::cin >> imagePath;
			SubclassPtr<IImageReader> reader = ImageReaderFactory::CreateImageReader(imagePath);
			sessions[currentSession++].addImage(reader->readImage(imagePath));
			std::cout << "Session with ID: " << currentSession << " started" << std::endl;
		}
		else if (command == ADD_COMMAND)
		{
			String imagePath;
			std::cin >> imagePath;
			SubclassPtr<IImageReader> reader = ImageReaderFactory::CreateImageReader(imagePath);
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
		else if (command == EXIT_COMMAND)
		{
			isRunning = false;
		}
	}
	PPMImageWriter writer;
	sessions[0].transformImages();
	writer.writeImage("testResult.ppm", sessions[0].getImage(0));
}