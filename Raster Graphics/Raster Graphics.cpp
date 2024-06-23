#include "Application.h"

int main()
{
	try
	{
		Application app;
		app.run();
	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}

    return 0;
}