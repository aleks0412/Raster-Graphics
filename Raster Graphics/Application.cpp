#include "Application.h"
#include "Vector.hpp"
#include "SubclassPtr.hpp"
#include "Session.h"
#include "IImageReader.h"
#include "IImageWriter.h"
#include "ImageReaderFactory.h"
#include "ImageWriteFactory.h"
#include "TransformFactory.h"
#include "utils.hpp"
#include <iostream>
void Application::run()
{
	Vector<Session> sessions;
	int currentSession = 0;
	std::cout << "Write help to get list of commands" << std::endl;
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
		else if (command == SESSION_INFO_COMMAND)
		{
			std::cout << "Session ID: " << currentSession << std::endl;
			size_t sessionImagesSize = sessions[currentSession - 1].getImagesSize();
			for (size_t i = 0; i < sessionImagesSize; i++)
			{
				std::cout << "Image " << i + 1 << ": " << sessions[currentSession - 1].getImage(i).getFileName() << std::endl;
			}
		}
		else if (command == SWITCH_COMMAND)
		{
			int sessionID;
			std::cin >> sessionID;
			currentSession = sessionID;
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
		else if (command == HELP_COMMAND)
		{
			std::cout << HELP_MESSAGE << std::endl;
		}
		else if (command == COLLAGE_COMMAND)
		{
			String direction;
			std::cin >> direction;
			int firstImageIndex, secondImageIndex;
			std::cin >> firstImageIndex >> secondImageIndex;
			String collageName;
			std::cin >> collageName;
			Image firstImage = sessions[currentSession - 1].getImage(firstImageIndex - 1);
			Image secondImage = sessions[currentSession - 1].getImage(secondImageIndex - 1);
			if (firstImage.getImageType() != secondImage.getImageType())
			{
				throw std::invalid_argument("Images have different types");
			}
			if (direction == COLLAGE_HORIZONTAL_DIRECTION)
			{
				int firstImageWidth = firstImage.getWidth();
				int secondImageWidth = secondImage.getWidth();
				int firstImageHeight = firstImage.getHeight();
				int secondImageHeight = secondImage.getHeight();
				int collageWidth = firstImageWidth + secondImageWidth;
				int collageHeight = utils::max<int>(firstImageHeight, secondImageHeight);
				Image result(collageWidth, collageHeight, firstImage.getImageType(), collageName);
				for (int x = 0; x < firstImageWidth; x++)
				{
					for (int y = 0; y < firstImageHeight; y++)
					{
						result.setPixel(x, y, firstImage.getPixel(x, y));
					}
				}
				for (int x = 0; x < secondImageWidth; x++)
				{
					for (int y = 0; y < secondImageHeight; y++)
					{
						result.setPixel(x + firstImageWidth, y, secondImage.getPixel(x, y));
					}
				}
				sessions[currentSession - 1].addImage(result);
			}
			else if (direction == COLLAGE_VERTICAL_DIRECTION)
			{

				int firstImageWidth = firstImage.getWidth();
				int secondImageWidth = secondImage.getWidth();
				int firstImageHeight = firstImage.getHeight();
				int secondImageHeight = secondImage.getHeight();
				int collageWidth = utils::max<int>(firstImageWidth, secondImageWidth);
				int collageHeight = firstImageHeight + secondImageHeight;
				Image result(collageWidth, collageHeight, firstImage.getImageType(), collageName);
				for (int x = 0; x < firstImageWidth; x++)
				{
					for (int y = 0; y < firstImageHeight; y++)
					{
						result.setPixel(x, y, firstImage.getPixel(x, y));
					}
				}
				for (int x = 0; x < secondImageWidth; x++)
				{
					for (int y = 0; y < secondImageHeight; y++)
					{
						result.setPixel(x, y + firstImageHeight, secondImage.getPixel(x, y));
					}
				}
				sessions[currentSession - 1].addImage(result);
			}
			else
			{
				throw std::invalid_argument("Unknown direction");
			}
		}
		else
		{
			throw std::invalid_argument("Unknown command");
		}
	}
}