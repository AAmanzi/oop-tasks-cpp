#include "Gun.h"

Gun::Gun() :
	MagazineSize(0),
	AvailableBullets(0){};

Gun::Gun(const Point& location, int magazineSize, int availableBullets) : 
	Location(location), 
	MagazineSize(magazineSize), 
	AvailableBullets(availableBullets){};

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