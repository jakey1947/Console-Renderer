namespace CustomTypes
{
    template <typename T>
    int sgn(T val)
    {
        return (T(0) < val) - (val < T(0));
  }


  struct Vector2
  {
    int x;
    int y;

    Vector2(int X = 0,int Y  = 0)
    {
      x=X;
      y=Y;
    }

    int GetMaximum()
    {
      return x > y ? x : y;
    }

  };

    #pragma region Vector2 Operators
    Vector2 operator+(Vector2 l, Vector2 r){
      return Vector2(l.x + r.x, l.y + r.y);
    }

    Vector2 operator-(Vector2 l, Vector2 r){
      return Vector2(l.x - r.x, l.y - r.y);
    }

    Vector2 operator*(Vector2 l, Vector2 r){
      return Vector2(l.x * r.x, l.y * r.y);
    }

    Vector2 operator/(Vector2 l, Vector2 r){
      return Vector2(l.x / r.x, l.y / r.y);
    }

    Vector2 operator*(Vector2 l, int r)
    {
        return Vector2(l.x * r, l.y * r);
    }

        Vector2 operator/(Vector2 l, int r)
    {
        return Vector2(l.x / r, l.y / r);
    }

    bool operator==(Vector2 l, Vector2 r)
    {
        return (l.x == r.x && l.y == r.y);
    }

    bool operator!=(Vector2 l, Vector2 r){
      return !(l == r);
    }
    bool operator<(Vector2 l, Vector2 r)
    {
        return l.x < r.x || l.y < r.y;
    }
    bool operator>(Vector2 l, Vector2 r)
    {
        return r < l;
    }
    bool operator>=(Vector2 l, Vector2 r)
    {
        return !(l < r);
    }

    bool operator<=(Vector2 l, Vector2 r)
    {
        return !(r < l);
    }

    //Vector2 , int comparisons
    bool operator==(Vector2 l, int r)
    {
        return (l.x == r && l.y == r);
    }

    bool operator!=(Vector2 l, int r){
      return !(l == r);
    }
    bool operator<(Vector2 l, int r)
    {
        return l.x < r || l.y < r;
    }
    bool operator>(Vector2 l, int r)
    {
        return r < l;
    }
    bool operator>=(Vector2 l, int r)
    {
        return !(l < r);
    }

    bool operator<=(Vector2 l, int r)
    {
        return !(r < l);
    }

    #pragma endregion

}
