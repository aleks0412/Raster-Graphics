#include "Application.h"
#include "Vector.hpp"
#include "SubclassPtr.hpp"
#include "Session.h"
#include "IImageReader.h"
#include "IImageWriter.h"
#include "ImageReaderFactory.h"
#include "ImageWriteFactory.h"
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
			sessions[currentSession - 1].addImage(reader->readImage(imagePath.c_str()));
		}
		else if (TransformFactory::isTransformName(command))
		{
			SubclassPtr<ITransform> transform = TransformFactory::createTransform(command);
			sessions[currentSession - 1].addTransform(transform);
		}
		else if (command == UNDO_COMMAND)
		{
			sessions[currentSession - 1].popTransform();
		}
		else if (command == EXIT_COMMAND)
		{
			isRunning = false;
		}
		else if (command == SAVE_COMMAND)
		{
			sessions[currentSession - 1].transformImages();
			size_t sessionImagesSize = sessions[currentSession - 1].getImagesSize();
			for (size_t i = 0; i < sessionImagesSize; i++)
			{
				SubclassPtr<IImageWriter> writer = ImageWriterFactory::CreateImageWriter(sessions[currentSession - 1].getImage(i));
				writer->writeImage(sessions[currentSession - 1].getImage(i).getFileName(), sessions[currentSession - 1].getImage(i));
			}
		}
		else if (command == SAVEAS_COMMAND)
		{
			String imagePath;
			std::cin >> imagePath;
			sessions[currentSession - 1].transformImages();
			SubclassPtr<IImageWriter> writer = ImageWriterFactory::CreateImageWriter(sessions[currentSession - 1].getImage(0));
			writer->writeImage(imagePath, sessions[currentSession - 1].getImage(0));
		}
	}
}