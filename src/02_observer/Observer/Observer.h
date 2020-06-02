#ifndef CPP_DESIGN_PATTERN_OBSERVER_H
#define CPP_DESIGN_PATTERN_OBSERVER_H

namespace observer_pattern {

class Observer {
public:
  Observer();
  virtual ~Observer();

  virtual void Update() = 0;

private:
};

}

#endif //CPP_DESIGN_PATTERN_OBSERVER_H
