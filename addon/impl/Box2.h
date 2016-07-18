#ifndef IMPL_BOX2_H
#define IMPL_BOX2_H

namespace three {

class Box2 {
public:
  static Box2* Create(long min, long max);

  Box2* set(long min, long max);
  bool isEmpty();
};

}; // namespace three

#endif // IMPL_BOX2_H

