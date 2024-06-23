#include "Session.h"

void Session::addImage(const Image& image)
{
	this->images.pushBack(image);
}

void Session::addImage(Image&& image)
{
	this->images.pushBack(std::move(image));
}

const Image& Session::getImage(size_t index) const
{
	return this->images[index].getImage();
}

Image& Session::getImage(size_t index)
{
	return this->images[index].getImage();
}

void Session::addTransform(const SubclassPtr<ITransform>& transform)
{
	size_t imagesSize = this->images.getSize();
	for(size_t i = 0; i < imagesSize; i++)
		this->images[i].addTransform(transform);
}

void Session::addTransform(SubclassPtr<ITransform>&& transform)
{
	size_t imagesSize = this->images.getSize();
	for(size_t i = 0; i < imagesSize; i++)
		this->images[i].addTransform(std::move(transform));
}

void Session::popTransform()
{
	size_t imagesSize = this->images.getSize();
	for(size_t i = 0; i < imagesSize; i++)
		this->images[i].popTransform();
}

void Session::transformImages()
{
	size_t imagesSize = this->images.getSize();
	for(size_t i = 0; i < imagesSize; i++)
		this->images[i].transformImage();
}

size_t Session::getImagesSize() const
{
	return this->images.getSize();
}
