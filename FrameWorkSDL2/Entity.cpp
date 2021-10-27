#include "Entity.h"

Entity::Entity()
{


}

Entity::~Entity()
{


}

int Entity::getNb(std::string key)
{
	return this->m_nb_Entities[key];
}

std::string Entity::getStr(std::string key)
{
	return this->m_str_Entities[key];
}

void Entity::addToNbEntity(std::string newKey, int newNb)
{
	this->m_nb_Entities.insert(std::make_pair(newKey, newNb));
}

void Entity::displayNbEntites()
{
	for (auto it = this->m_nb_Entities.begin(); it != this->m_nb_Entities.end(); ++it)
	{
		string key = it->first;
		int value = it->second;

		std::cout << key << value << std::endl;
	}
}


