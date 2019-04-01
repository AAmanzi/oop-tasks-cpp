#include "Gun.h"

Gun::Gun() :
	MagazineSize(0),
	AvailableBullets(0){};

Gun::Gun(const Point& location, int magazineSize, int availableBullets) : 
	Location(location), 
	MagazineSize(magazineSize), 
	AvailableBullets(availableBullets){};

Gun::Gun(const Point& location, int magazineSize) : 
	Location(location), 
	MagazineSize(magazineSize), 
	AvailableBullets(magazineSize){};

int Gun::GetMagazineSize()
{
	return MagazineSize;
}

int Gun::GetAvailableBullets()
{
	return AvailableBullets;
}

Point Gun::GetLocation()
{
	return Location;
}

bool Gun::IsEmpty() const
{
	return (AvailableBullets == 0);
}

void Gun::Shoot()
{
	AvailableBullets--;
}

void Gun::Reload()
{
	AvailableBullets = MagazineSize;
}