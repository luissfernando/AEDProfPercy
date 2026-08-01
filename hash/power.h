#ifndef POWER_H
#define POWER_H

template <class T>
class Power {
public:
  unsigned int operator()(const T& data) const {
    return static_cast<unsigned int>(data * data);
  }
};
#endif
