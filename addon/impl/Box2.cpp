#include "Box2.h"

namespace three {

Box2* Box2::Create(long min, long max) {
  return new Box2();
}

Box2* Box2::set(long min, long max) {
  return this;
}

bool Box2::isEmpty() {
  return false;
}

}; // namespace three