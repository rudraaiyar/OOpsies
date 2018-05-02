#ifndef shape_h
#define shape_h

class shape{
protected:
  float x;
  float y;

public:
  shape();
  shape(float,float);
  void setXPos(float);
  void setYPos(float);
  float getXPos()const;
  float getYPos()const;
  virtual void draw()=0;
};

#endif
