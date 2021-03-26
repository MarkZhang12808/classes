// Class for Movies

#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movies.h"

using namespace std;

Movie::Movie()
{}
int Movie::getType() {
  return 2;
}

char* Movie::getDirector() {
  return Director;
}

int* Movie::getDuration() {
  return &Duration;
}

float* Movie::getRating() {
  return &Rating; 
}
