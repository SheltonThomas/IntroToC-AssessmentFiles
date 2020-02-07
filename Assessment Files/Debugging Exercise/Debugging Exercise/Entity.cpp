#include "Entity.h"



Entity::Entity()
{
}


Entity::~Entity()
{
}

bool Entity::isAlive()
{
	if (health <= 0) return false;
	return true;
}

int Entity::attack()
{
	return 0;
}

void Entity::takeDamage(int damage)
{

}
