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
	this->transforms.popBack();
}

void TransformedImage::transformImage()
{
	for(int i = 0; i < this->transforms.getSize(); i++)
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