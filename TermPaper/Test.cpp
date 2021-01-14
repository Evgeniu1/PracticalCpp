#define BOOST_TEST_MODULE mytests
//#include <boost/test/included/unit_test.hpp>
#include "Container.h"
#include <fstream>
using namespace std;

BOOST_AUTO_TEST_CASE(CreatePistonTest)
{
	Piston* obj = new Piston("TSI", "Petrol", CAST_IRON, 200, 95, 200, 260, 4, STRAIGHT);
	BOOST_AUTO_TEST_CASE(obj->getCylinder);
}
