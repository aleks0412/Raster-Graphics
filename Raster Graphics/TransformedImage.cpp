#include "TransformedImage.h"

TransformedImage::TransformedImage(const Image& image) : image(image)
{
}

TransformedImage::TransformedImage(Image&& image) : image(std::move(image))
{
}

void TransformedImage::addTransform(const SubclassPtr<ITransform>& transform)
{
	this->transforms.pushBack(transform);
}

void TransformedImage::addTransform(SubclassPtr<ITransform>&& transform)
{
	this->transforms.pushBack(std::move(transform));
}

void TransformedImage::popTransform()
{
	try
	{
		this->transforms.popBack();
	}
	catch (const std::length_error& e)
	{
	}
}

void TransformedImage::transformImage()
{
	size_t transformsSize = this->transforms.getSize();
	for(int i = 0; i < transformsSize; i++)
		this->transforms[i]->transformImage(image);
}

const Image& TransformedImage::getImage() const
{
	return this->image;
}

Image& TransformedImage::getImage()
{
	return this->image;
}