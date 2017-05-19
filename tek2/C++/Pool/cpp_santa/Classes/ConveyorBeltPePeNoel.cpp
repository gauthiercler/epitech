/*
** ConveyorBeltPePeNoel.cpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/ConveyorBeltPePeNoel.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 16:13:39 2017 Antoine FORET
** Last update Sat Jan 14 16:13:39 2017 Antoine FORET
*/

#include <iostream>
#include "ConveyorBeltPePeNoel.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel() : _currentObject(NULL), _model_idx(0) {
  this->_models[0] = new Box();
  this->_models[1] = new GiftPaper();
}

ConveyorBeltPePeNoel::ConveyorBeltPePeNoel(const ConveyorBeltPePeNoel &conveyorBeltPePeNoel) : _model_idx(conveyorBeltPePeNoel.getModelIdx()) {
  for (unsigned int i = 0; i < NBR_MODELS; i++)
  {
    if (conveyorBeltPePeNoel.getModel(i) != NULL)
      this->setModel(i, static_cast<AWrap*>(conveyorBeltPePeNoel.getModel(i)->clone()));
    else
      this->setModel(i, NULL);
  }
  if (conveyorBeltPePeNoel.getCurrentObject() != NULL)
    this->setCurrentObject(conveyorBeltPePeNoel.getCurrentObject()->clone());
  else
    this->setCurrentObject(NULL);
}

ConveyorBeltPePeNoel::~ConveyorBeltPePeNoel() {
  for (unsigned int i = 0; i < NBR_MODELS; i++)
  {
    if (this->getModel(i) != NULL)
      delete this->getModel(i);
  }
  if (this->getCurrentObject() != NULL)
    delete this->getCurrentObject();
}

ConveyorBeltPePeNoel &ConveyorBeltPePeNoel::operator=(const ConveyorBeltPePeNoel &conveyorBeltPePeNoel) {
  if (this != &conveyorBeltPePeNoel)
  {
    for (unsigned int i = 0; i < NBR_MODELS; i++)
    {
      if (this->getModel(i) != NULL)
	delete this->getModel(i);
      if (conveyorBeltPePeNoel.getModel(i) != NULL)
	this->setModel(i, static_cast<AWrap*>(conveyorBeltPePeNoel.getModel(i)->clone()));
      else
	this->setModel(i, NULL);
    }
    if (this->getCurrentObject() != NULL)
      delete this->getCurrentObject();
    if (conveyorBeltPePeNoel.getCurrentObject() != NULL)
      this->setCurrentObject(conveyorBeltPePeNoel.getCurrentObject()->clone());
    else
      this->setCurrentObject(NULL);
  }
  return *this;
}

bool ConveyorBeltPePeNoel::in() {
  if (this->getCurrentObject() != NULL)
    return false;
  this->_currentObject = this->getModel(this->getModelIdx())->clone();
  this->incrementIdx();
  return true;
}

bool ConveyorBeltPePeNoel::out() {
  if (this->getCurrentObject() == NULL)
    return false;
  delete this->getCurrentObject();
  this->setCurrentObject(NULL);
  return true;
}

void ConveyorBeltPePeNoel::incrementIdx() {
  this->_model_idx = (this->_model_idx + 1) % NBR_MODELS;
}

AObject *ConveyorBeltPePeNoel::take() {
  AObject *object;
  if (this->getCurrentObject() == NULL)
    return NULL;
  object = this->getCurrentObject();
  this->setCurrentObject(NULL);
  return object;
}

const std::string *ConveyorBeltPePeNoel::look() const {
  if (this->getCurrentObject() != NULL)
    return &this->getCurrentObject()->getName();
  else
    return NULL;
}

unsigned int ConveyorBeltPePeNoel::getModelIdx() const {
  return this->_model_idx;
}

AObject *ConveyorBeltPePeNoel::getCurrentObject() const {
  return this->_currentObject;
}

AWrap *ConveyorBeltPePeNoel::getModel(unsigned int idx) const {
  if (idx < NBR_MODELS)
    return this->_models[idx];
  else
    return NULL;
}

bool ConveyorBeltPePeNoel::put(AObject *object) {
  if (this->getCurrentObject() != NULL)
    return false;
  this->setCurrentObject(object);
  return true;
}

void ConveyorBeltPePeNoel::setModel(unsigned int idx, AWrap *wrap) {
  if (idx > NBR_MODELS)
    return ;
  this->_models[idx] = wrap;
}

void ConveyorBeltPePeNoel::setCurrentObject(AObject *object) {
  this->_currentObject = object;
}
