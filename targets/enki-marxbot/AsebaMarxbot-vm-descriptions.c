/*
	Aseba - an event-based middleware for distributed robot control
	Copyright (C) 2006 - 2007:
		Stephane Magnenat <stephane at magnenat dot net>
		(http://stephane.magnenat.net)
		Valentin Longchamp <valentin dot longchamp at epfl dot ch>
		Laboratory of Robotics Systems, EPFL, Lausanne
	
	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any other version as decided by the two original authors
	Stephane Magnenat and Valentin Longchamp.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../../vm/natives.h"

AsebaVMDescription vmLeftMotorDescription = {
	"left motor",
	{
		{ 1, "id" },
		{ 1, "source" },
		{ 32, "args" },
		{ 1, "speed" },
		{ 2, "odo" },
		{ 0, NULL }
	}
};

AsebaVMDescription vmRightMotorDescription = {
	"right motor",
	{
		{ 1, "id" },
		{ 1, "source" },
		{ 32, "args" },
		{ 1, "speed" },
		{ 2, "odo" },
		{ 0, NULL }
	}
};

AsebaVMDescription vmProximitySensorsDescription = {
	"proximity sensors",
	{
		{ 1, "id" },
		{ 1, "source" },
		{ 32, "args" },
		{ 24, "bumpers" },
		{ 12, "ground" },
		{ 0, NULL }
	}
};

AsebaVMDescription vmDistanceSensorsDescription = {
	"distance sensors",
	{
		{ 1, "id" },
		{ 1, "source" },
		{ 32, "args" },
		{ 180, "distances" },
		{ 0, NULL }
	}
};