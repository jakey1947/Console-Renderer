namespace CustomTypes
{

  template <typename T> int sgn(T val) {
      return (T(0) < val) - (val < T(0));
  }

  struct Vector2
  {
    int x, y;

    Vector2(int x, int y);
    Vector2();
    
    int GetMaximum();
    #pragma region operators
    Vector2 operator+(Vector2 other);

    Vector2 operator-(Vector2 other);

    Vector2 operator*(Vector2 other);

    Vector2 operator/(Vector2 other);

    Vector2 operator*(int other);

    Vector2 operator/(int other);

    bool operator==(Vector2 other);

    bool operator!=(Vector2 other);

    bool operator<(Vector2 other);
    bool operator>(Vector2 other);
    bool operator<=(Vector2 other);
    bool operator>=(Vector2 other);

        //Vector2 , int comparisons
    bool operator==(int r);
    bool operator!=(int r);
    bool operator<(int r);
    bool operator>(int r);
    bool operator>=(int r);
    bool operator<=(int r);
    #pragma endregion
    
    };  
}